#ifndef ACTUATE_H
#define ACTUATE_H

#define NUMBER_OF_THRUSTERS 4

/*
 * Data available to this module (inputs):


 */

#include <QVector4D>
#include "module.h"
#include "pololu.h"
#include "mechanisms.h"

class Actuators: public Module
{
	Q_OBJECT
	public:
		Actuators(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
		QStringList subscriptions(){
			QStringList sub;
			sub << "Thrusters";
			return sub;
		}
	private slots:
		void dataIn(VDatum datum);
		void step();
		void init();
		void setThrusters(double[4]);
	private:
		Pololu* pololu;
};


#endif

