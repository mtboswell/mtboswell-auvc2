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
		Actuators();
		QStringList subscriptions(){
			QStringList sub;
			sub << "Thrusters";
			sub << "ThrustersON.Forward";
			sub << "ThrustersON.Angled";
			sub << "FireTorp";
			return sub;
		}
		void fireTorpedo(int torp, bool fire);
	private slots:
		void dataIn(VDatum datum);
		void step();
		void init();
		void setThrusters(double[4]);
		void retractTorpedos();
	private:
		Pololu* pololu;
		VDatum oldData;
		int forwardON;
		int  angledON;
		bool fired1;
		bool fired2;
};


#endif

