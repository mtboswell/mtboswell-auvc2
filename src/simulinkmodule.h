/**
 * SimulinkModule.h - module interface for Simulink model code
 */
#include "module.h"

class SimulinkModule : public Module
{
	Q_OBJECT
	public:
		// what does the constructor need to do different from Module?	
	public slots:
		/// set Simulink params by using paramList
		void setParameter(QString name, double value);

	private slots:
		/// runStep is implemented in the child class to read inputs, call rt_OneStep(), and write outputs
		virtual void runStep();
	private:

		/// paramList should be populated from the constructor of the child class
		QMap<QString, double*> paramList;
};
