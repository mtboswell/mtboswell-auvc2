#ifndef PIDCONTROL_H
#define PIDCONTROL_H

#include <QTime>

class PIDController : public QObject
{
	Q_OBJECT
	public:
		PIDController(double P, double I = 0, double D = 0);
		~PIDController()

	public slots:
		// do calculation and emit output()
		void step();
		// should this call step()?
		void setActual(double value);
		void setTarget(double value);

	signals:
		void output(double output);

	private:
		double Kp, Ki,Kd;
		double previous_error;
		double integral;
		double target;
		QTime dt;
};

#endif
