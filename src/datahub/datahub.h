#include <QObject>
#include <QString>
#include <QMetaObject>
#include <QMetaMethod>
#include <QStringList>
#include <QDebug>
#include "../state.h"
#include "../tmf.h"
#include "../module.h"
#include "../server/tmfsocket.h"

/**
 * DataHub is a class designed to connect and manage Modules.
 * \ingroup HUB
 */
class DataHub : public QObject
{
	Q_OBJECT
	public:
		DataHub(AUVC_State_Data* stateIn){
			state = stateIn;
			srv = new VDataSocket(5325, 5236, true);
			connect(srv, SIGNAL(tmfReceived(VData, QHostAddress)), this, SLOT(messageIn(VData)));
			connect(this, SIGNAL(messageBroadcast(VData)), srv, SLOT(sendVData(VData)));
			connect(state, SIGNAL(dataUpdated(VData)), srv, SLOT(sendVData(VData)));
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
			connect(this, SIGNAL(messageBroadcast(VData)), module, SLOT(messageIn(VData)));
			connect(state, SIGNAL(dataUpdated(QString)), module, SLOT(newData(QString)));
			connect(module, SIGNAL(messageOut(VData)), this, SLOT(messageIn(VData)));
			connect(this, SIGNAL(go()), module, SLOT(start()));

		}
		/**
		 * As an alternative to the addModule function, you can set this module as the parent of your modules, then call this function.
		 */
		void initializeAndLaunchAllModules(){
			QObjectList kids = this->children();
			foreach(QObject* kid, kids){
				if(kid->inherits("Module")) addModule((Module*)kid);
				qDebug() << "Adding Module";
			}
			startAll();
			qDebug() << "Initialization Complete, System Online";
		}

	public slots:
		void messageIn(VData msg){
			qDebug() << "Message ID:" << msg.treeItems[0].ID;
			emit messageBroadcast(msg);
		}
		void startAll(){emit go();}

	signals:
		void messageBroadcast(VData msg);
		void go(); // used to launch modules

	private:
		VDataSocket* srv;
		AUVC_State_Data* state;
};
