/**
 * Default implementations for Module class.
 */

 #include "module.h"

 Module::Module(QMap<QString, QString>* configIn, AUV_State* stateIn, QObject* parent = 0):QThread(parent){
 	state = stateIn;
	config = configIn;
	stepTimer = new QTimer(this);
 	connect(stepTimer, SIGNAL(timeout()), this, SLOT(step()));
	stepTimer->start(20);
 }
