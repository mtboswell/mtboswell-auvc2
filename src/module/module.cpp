/**
 * Default implementations for Module class.
 */

 #include "module.h"

 Module::Module(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent):QThread(parent){
 	state = stateIn;
	config = configIn;
	stepTimer = new QTimer(this);
 	connect(stepTimer, SIGNAL(timeout()), this, SLOT(step()));
	//stepTimer->start(20);
 }

 void Module::recvDatum(QString module, VDatum datum){
 	if(module == this->metaObject()->className()){
		dataIn(datum);
	}
 }


void Module::setData(QString ID, QVariant value, QTime timestamp, QVariant meta){
	VDatum datum;
	datum.id = ID;
	datum.value = value;
	datum.timestamp = timestamp;
	datum.meta = meta;
	emit sendData(datum);
}
void Module::setData(VDatum datum){
	emit sendData(datum);
}
void Module::setData(QList<VDatum> datums){
	foreach(VDatum datum, datums){
		emit sendData(datum);
	}
}

void Module::run(){
	init();
	exec();
}

QVariant Module::value(QString ID){return state->value(ID);}
bool Module::boolValue(QString ID){return state->value(ID).toBool();}
int Module::intValue(QString ID){return state->value(ID).toInt();}
double Module::doubleValue(QString ID){return state->value(ID).toDouble();}
QString Module::stringValue(QString ID){return state->value(ID).toString();}
bool Module::available(QString ID){return state->available(ID);}
QTime Module::timestamp(QString ID){return state->timestamp(ID);}



/**
 * Default implementations for Module class.
 */


 GuiModule::GuiModule(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QWidget* parent):QMainWindow(parent){
 	state = stateIn;
	config = configIn;
	stepTimer = new QTimer(this);
 	connect(stepTimer, SIGNAL(timeout()), this, SLOT(step()));
	//stepTimer->start(20);
 }

 void GuiModule::recvDatum(QString module, VDatum datum){
 	if(module == this->metaObject()->className()){
		dataIn(datum);
	}
 }


void GuiModule::setData(QString ID, QVariant value, QTime timestamp, QVariant meta){
	VDatum datum;
	datum.id = ID;
	datum.value = value;
	datum.timestamp = timestamp;
	datum.meta = meta;
	emit sendData(datum);
}
void GuiModule::setData(VDatum datum){
	emit sendData(datum);
}
void GuiModule::setData(QList<VDatum> datums){
	foreach(VDatum datum, datums){
		emit sendData(datum);
	}
}

QVariant GuiModule::value(QString ID){return state->value(ID);}
bool GuiModule::boolValue(QString ID){return state->value(ID).toBool();}
int GuiModule::intValue(QString ID){return state->value(ID).toInt();}
double GuiModule::doubleValue(QString ID){return state->value(ID).toDouble();}
QString GuiModule::stringValue(QString ID){return state->value(ID).toString();}
