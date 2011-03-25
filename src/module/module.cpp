/**
 * Default implementations for Module class.
 */

 #include "module.h"

 Module::Module(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent):QThread(parent){
 	state = stateIn;
	config = configIn;
	stepTimer = new QTimer(this);
 	connect(stepTimer, SIGNAL(timeout()), this, SLOT(step()));
	//stepTimer->start(20);
 }

 void Module::recvDatum(QString module, VDatum datum){
 	if(module == this->metaObject()->className()){
		dataIn(datum);
	}
 }


void Module::setData(QString ID, QVariant value, QTime timestamp, QVariant meta){
	VDatum datum;
	datum.id = ID;
	datum.value = value;
	datum.timestamp = timestamp;
	datum.meta = meta;
	emit setData(datum);
}

QVariant Module::value(QString ID){return state->value(ID);}
bool Module::boolValue(QString ID){return state->value(ID).toBool();}
int Module::intValue(QString ID){return state->value(ID).toInt();}
double Module::doubleValue(QString ID){return state->value(ID).toDouble();}
QString Module::stringValue(QString ID){return state->value(ID).toString();}
