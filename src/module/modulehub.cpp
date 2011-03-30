#include "modulehub.h"


ModuleHub::ModuleHub(AUVC_State_Data* stateIn, bool server, quint16 listenPort, quint16 remotePort){
	state = stateIn;
	// connect up server to state data
	srv = new VDataSocket(listenPort, remotePort, server, QHostAddress::LocalHost);
	connect(srv, SIGNAL(datumReceived(VDatum, QHostAddress)), this, SLOT(messageIn(VDatum)));
	connect(this, SIGNAL(messageBroadcast(VDatum)), srv, SLOT(sendVDatum(VDatum)));
	//connect(state, SIGNAL(dataUpdated(VDatum)), srv, SLOT(sendVDatum(VDatum)));
}
/**
 * addModule adds a module object to the vdata broadcasting system.
 * \param module pointer to module QObject
 */
void ModuleHub::addModule(Module* module){
	const QMetaObject* metaMod = module->metaObject();
	qDebug() << "Initializing Module:" << metaMod->className();

	connect(this, SIGNAL(subOut(QString, VDatum)), module, SLOT(recvDatum(QString, VDatum)));
	addSubscriptions(metaMod->className(), module->subscriptions());

	connect(module, SIGNAL(sendData(VDatum)), this, SLOT(moduleIn(VDatum)));

}
void ModuleHub::addModule(GuiModule* module){
	const QMetaObject* metaMod = module->metaObject();
	qDebug() << "Initializing Module:" << metaMod->className();

	connect(this, SIGNAL(subOut(QString, VDatum)), module, SLOT(recvDatum(QString, VDatum)));
	addSubscriptions(metaMod->className(), module->subscriptions());

	connect(module, SIGNAL(sendData(VDatum)), this, SLOT(moduleIn(VDatum)));

}
/**
 * As an alternative to the addModule function, you can set this module as the parent of your modules, then call this function.
 */
void ModuleHub::initializeAndLaunchAllModules(){
	QObjectList kids = this->children();
	foreach(QObject* kid, kids){
		if(kid->inherits("Module")) addModule((Module*)kid);
		if(kid->inherits("SimulinkModule")) ((SimulinkModule*)kid)->initializeParameters();
		if(((Module*) kid)->isThread()) connect(this, SIGNAL(go()), kid, SLOT(start()));
		qDebug() << "Adding Module";
	}
	startAll();
	qDebug() << "Initialization Complete, System Online";
}

void ModuleHub::addSubscriptions(QString module, QStringList IDs){
	foreach(QString str, IDs){
		subscriptions[str].append(module);
	}
}
void ModuleHub::addSubscription(QString module, QString ID){
	subscriptions[ID].append(module);
}

void ModuleHub::messageIn(VDatum msg){
	//qDebug() << "Message ID:" << msg.id;
	state->setData(msg);

	QStringList modulesToNotify;


	QMapIterator<QString, QStringList> i(subscriptions); 
	while(i.hasNext()){
		i.next();
		if(msg.id.startsWith(i.key())) modulesToNotify.append(i.value());
	}

	modulesToNotify.removeDuplicates();

	// handle subscriptions
	foreach(QString str, modulesToNotify){
		emit subOut(str, msg);
	}
}

void ModuleHub::moduleIn(VDatum msg){
	//qDebug() << "Message ID:" << msg.id;
	state->setData(msg);
	messageBroadcast(msg);
	messageIn(msg);
}
