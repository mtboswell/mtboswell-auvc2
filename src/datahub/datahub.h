#include <QObject>
#include <QString>
#include <QMetaObject>
#include <QMetaMethod>
#include <QStringList>
#include <QDebug>
#include "../module.h"
#include "server/sidsocket.h"

/**
 * DataHub is a class designed to connect and manage Modules.
 * \ingroup HUB
 */
class DataHub : public QObject
{
	Q_OBJECT
	public:
		DataHub(){
			srv = new SIDSocket(5325, 5236, true);
			connect(srv, SIGNAL(sidReceived(QString, QString, QHostAddress)), this, SLOT(messageIn(QString, QString)));
			connect(this, SIGNAL(messageBroadcast(QString, QString)), srv, SLOT(sendSID(QString, QString)));
		}
		/**
		 * addModule adds a module object to the message broadcasting system.
		 * The module object should have a signal messageOut(QString), and a slot
		 * called messageIn(QString).  Messages are SID strings.
		 * \param module pointer to module QObject
		 */
		void addModule(Module* module){
			const QMetaObject* metaMod = module->metaObject();
			qDebug() << "Initializing Module:" << metaMod->className();
			connect(this, SIGNAL(messageBroadcast(QString,QString)), module, SLOT(messageIn(QString,QString)));
			connect(module, SIGNAL(messageOut(QString,QString)), this, SLOT(messageIn(QString,QString)));
			connect(this, SIGNAL(go()), module, SLOT(start()));

		}
		/**
		 * As an alternative to the addModule function, you can set this module as the parent of your modules, then call this function.
		 */
		void initializeAndLaunchAllModules(){
			QObjectList kids = this->children();
			foreach(QObject* kid, kids){
				if(kid->inherits("Module")) addModule(kid);
			}
			startAll();
			qDebug() << "Initialization Complete, System Online";
		}

	public slots:
		void messageIn(QString id, QString data){
			qDebug() << "Message ID:" << id;
			emit messageBroadcast(id, data);
		}
		void startAll(){emit go();}

	signals:
		void messageBroadcast(QString id, QString data);
		void go(); // used to launch modules

	private:
		SIDSocket* srv;
};
