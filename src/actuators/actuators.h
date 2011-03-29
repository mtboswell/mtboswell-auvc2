#ifndef ACTUATE_H
#define ACTUATE_H

/*
 * Data available to this module (inputs):


 */

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
	protected slots:
		void dataIn(VDatum datum);
	private slots:
	private:
		Pololu* pololu;
};


#endif

