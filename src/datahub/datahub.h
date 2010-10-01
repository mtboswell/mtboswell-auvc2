#include <QObject>
#include <QString>
#include <QMetaObject>
#include <QMetaMethod>
#include <QStringList>
#include <QDebug>
#include "server/sidsocket.h"

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
		void addModule(QObject* module){
			const QMetaObject* metaMod = module->metaObject();
			QStringList methods;
			for(int i = metaMod->methodOffset(); i < metaMod->methodCount(); ++i)
				methods << QString::fromLatin1(metaMod->method(i).signature());
			//qDebug() << "Methods of class" << metaMod->className() << ":" << methods;
			if(methods.contains("messageIn(QString,QString)")){
				QMetaMethod method = metaMod->method(metaMod->methodOffset()+methods.indexOf("messageIn(QString,QString)"));
				if(method.methodType() == QMetaMethod::Slot)
					connect(this, SIGNAL(messageBroadcast(QString,QString)), module, SLOT(messageIn(QString,QString)));
				qDebug() << "Module" << metaMod->className() << "is accepting messages.";
			}else qDebug() << "Module" << metaMod->className() << "is not accepting messages.";
			if(methods.contains("messageOut(QString,QString)")){
				QMetaMethod method = metaMod->method(metaMod->methodOffset()+methods.indexOf("messageIn(QString,QString)"));
				if(method.methodType() == QMetaMethod::Signal)
					connect(module, SIGNAL(messageOut(QString,QString)), this, SLOT(messageIn(QString,QString)));
				qDebug() << "Module" << metaMod->className() << "can send messages.";
			}else qDebug() << "Module" << metaMod->className() << "is not sending messages.";

		}

	public slots:
		void messageIn(QString id, QString data){
			qDebug() << "Message ID:" << id;
			emit messageBroadcast(id, data);
		}

	signals:
		void messageBroadcast(QString id, QString data);

	private:
		SIDSocket* srv;
};
