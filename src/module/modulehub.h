#include <QObject>
#include <QString>
#include <QMetaObject>
#include <QMetaMethod>
#include <QStringList>
#include <QDebug>
#include "../state/state.h"
#include "../state/vdatum.h"
#include "../module/module.h"
#include "../module/simulinkmodule.h"
#include "../state/vdatasocket.h"

/**
 * DataHub is a class designed to connect and manage Modules.
 * \ingroup HUB
 */
class ModuleHub : public QObject
{
	Q_OBJECT
	public:
		ModuleHub(AUVC_State_Data* stateIn){
			state = stateIn;
			// connect up server to state data
			srv = new VDataSocket(5325, 5236, true);
			connect(srv, SIGNAL(datumReceived(VDatum, QHostAddress)), this, SLOT(messageIn(VDatum)));
			connect(this, SIGNAL(messageBroadcast(VDatum)), srv, SLOT(sendVDatum(VDatum)));
			connect(state, SIGNAL(dataUpdated(VDatum)), srv, SLOT(sendVDatum(VDatum)));
		}
		/**
		 * addModule adds a module object to the message broadcasting system.
		 * The module object should have a signal messageOut(QString), and a slot
		 * called messageIn(QString).  Messages are VDatas.
		 * \param module pointer to module QObject
		 */
		void addModule(Module* module){
			const QMetaObject* metaMod = module->metaObject();
			qDebug() << "Initializing Module:" << metaMod->className();
			//connect(this, SIGNAL(messageBroadcast(VDatum)), module, SLOT(messageIn(VDatum)));
			//connect(state, SIGNAL(dataUpdated(QString)), module, SLOT(newData(QString)));


			connect(this, SIGNAL(subOut(QString, VDatum)), module, SLOT(recvDatum(QString, VDatum)));
			addSubscriptions(metaMod->className(), module->subscriptions());

			connect(module, SIGNAL(setData(VDatum)), this, SLOT(messageIn(VDatum)));
			connect(this, SIGNAL(go()), module, SLOT(start()));

		}
		/**
		 * As an alternative to the addModule function, you can set this module as the parent of your modules, then call this function.
		 */
		void initializeAndLaunchAllModules(){
			QObjectList kids = this->children();
			foreach(QObject* kid, kids){
				if(kid->inherits("Module")) addModule((Module*)kid);
				if(kid->inherits("SimulinkModule")) ((SimulinkModule*)kid)->initializeParameters();
				qDebug() << "Adding Module";
			}
			startAll();
			qDebug() << "Initialization Complete, System Online";
		}

		void addSubscriptions(QString module, QStringList IDs){
			foreach(QString str, IDs){
				subscriptions[str].append(module);
			}
		}
		void addSubscription(QString module, QString ID){
			subscriptions[ID].append(module);
		}

	public slots:
		void messageIn(VDatum msg){
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
		void startAll(){emit go();}

	signals:
		void messageBroadcast(VDatum msg);
		void go(); // used to launch modules
		// subscription outputs
		void subOut(QString, VDatum);

	private:
		VDataSocket* srv;
		AUVC_State_Data* state;
		QMap<QString, QStringList> subscriptions;
};
