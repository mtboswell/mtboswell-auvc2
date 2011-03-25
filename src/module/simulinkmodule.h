#ifndef SIMULINKMOD
#define SIMULINKMOD
/**
 * SimulinkModule.h - module interface for Simulink model code
 */
#include "module.h"

class SimulinkModule : public Module
{
	Q_OBJECT
	public:
		// what does the constructor need to do different from Module?	
		SimulinkModule(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0):Module(configIn, stateIn, parent){}
	public slots:
		/// set Simulink params by using paramList
		void setParameter(QString name, double value){}
		/// called by moduleHub
		void initializeParameters();

	protected slots:
		/// step is implemented in the child class to read inputs, call rt_OneStep(), and write outputs
		virtual void step()=0;
		void updateParameters();
	protected:

		/// paramList should be populated from the constructor of the child class
		QMap<QString, double*> paramList;
};

#endif
