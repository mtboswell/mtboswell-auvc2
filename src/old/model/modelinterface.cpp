#include "model.h"
#include <QDebug>

Model::Model(QMutex* mutex){

	OverrunFlag = 0;
	
	// 100ms = 10Hz rate
	// 160ms = 6.25Hz
	// 200ms = 5Hz
	stepTime = 200;

	/* Initialize model */
	brain_initialize();
	  
	modelMutex = mutex;
  
	//qDebug("Setting Timer");
	modelTimer = new QTimer(this);
	  
	connect(modelTimer, SIGNAL(timeout()), this, SLOT(rt_OneStep()));
  
	if(parameters.isEmpty()) init_params(parameters);

	stepTimer.start();
}

Model::~Model(){
//	delete modelTimer;
	qDebug("Shutting Down Brain");
	wait();
}

void Model::run(){
	modelTimer->start(stepTime);
	exec();
}

/* Associating rt_OneStep with a real-time clock or interrupt service routine
 * is what makes the generated code "real-time".  The function rt_OneStep is
 * always associated with the base rate of the model.  Subrates are managed
 * by the base rate from inside the generated code.  Enabling/disabling
 * interrupts and floating point context switches are target specific.  This
 * example code indicates where these should take place relative to executing
 * the generated code step function.  Overrun behavior should be tailored to
 * your application needs.  This example simply sets an error status in the
 * real-time model and returns from rt_OneStep.
 */
void Model::rt_OneStep(void)
{
	if(DEBUG) qDebug("Stepping Model");

	/* Check for overrun */
	if (OverrunFlag++) {
		emit error("Overrun!!");
		rtmSetErrorStatus(brain_M, "Overrun");
		return;
	}

	/* Step the model */
	brain_step();
	if(DEBUG) qDebug("Model Stepped");

	/* Indicate task complete */
	OverrunFlag--;

	emit outputReady(brain_Y, stepTimer.restart());
	//if(DEBUG) qDebug("Output Sent");
}
		

void Model::setParam(QString name, double value){
	if(parameters.contains(name)) {
		*(parameters[name]) = value;
		emit status("Set parameter " + name + " to " + QString::number(value));
	}else emit error("Nonexistent parameter: " + name);	
}

void Model::setInput(QString name, double value){
	if(inputs.contains(name)) {
		*(inputs[name]) = value;
		emit status("Set input " + name + " to " + QString::number(value));
	}else emit error("Nonexistent input: " + name);	
} 
