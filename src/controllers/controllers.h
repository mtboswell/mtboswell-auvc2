#ifndef CONTROLLERS_H
#define CONTROLLERS_H

#include "../tmf.h"
#include "../simulinkmodule.h"
#include "src/MotionController.h"
#include <QDebug>

/**
 * Controllers Module.
 */
class Controllers : public SimulinkModule 
{
	Q_OBJECT;
	public:
		Controllers(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
	public slots:

	//	void setCmd(QString cmd);

	//	void setThrusters(int thrusterSpeeds[]);
	//	void move(heading, depth, fwd, strafe, timeout = inf);
	//	void track(object, down/fwd, bool maintainHeading, align=long/short, int approachSpeed);
	//	void surface();
		void messageIn(QString message);
		void messageIn(VDatum message);
		void newData(QString ID, QVariant value);

	signals:
		void statusChanged();
		void finished();

	private slots:
		void step();

	private:
	/*
		ControllersMode currentCMD;

		// directRC
		QList<char> thrusterSpeeds;
		// move
		double desiredYaw,
			desiredZ,
			desiredXVel,
			desiredYVel;
		QTime timeout;
		// tracking
		QString targetID;
		targetDir targetDirection;
		bool maintainHeading;
		double approachSpeed;
		double alignAngle;
		*/
};

#endif
