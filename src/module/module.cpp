/**
 * Default implementations for Module class.
 */

 #include "module.h"

 //Module::Module(AUVC_State_Data* stateIn):QThread(){ state = stateIn; }
  Module::Module():QThread(){}
	
	
void Module::setLinks(AUVC_State_Data* stateIn, QMap<QString, QString>* configIn, bool debugIn){
	state = stateIn;
	configuration = configIn;
	debug = debugIn;
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
	emit sendData(datum);
}
void Module::setData(VDatum datum){
	emit sendData(datum);
}
void Module::setData(QList<VDatum> datums){
	foreach(VDatum datum, datums){
		emit sendData(datum);
	}
}

void Module::run(){
	stepTimer = new QTimer();
 	connect(stepTimer, SIGNAL(timeout()), this, SLOT(step()));
	init();
	exec();
}

QVariant Module::value(QString ID){return state->value(ID);}
bool Module::boolValue(QString ID){return state->value(ID).toBool();}
int Module::intValue(QString ID){return state->value(ID).toInt();}
double Module::doubleValue(QString ID){return state->value(ID).toDouble();}
QString Module::stringValue(QString ID){return state->value(ID).toString();}
bool Module::available(QString ID){return state->available(ID);}
QTime Module::timestamp(QString ID){return state->timestamp(ID);}



/**
 * Default implementations for Module class.
 */


 GuiModule::GuiModule(AUVC_State_Data* stateIn):QMainWindow(){
 	state = stateIn;
	stepTimer = new QTimer(this);
 	connect(stepTimer, SIGNAL(timeout()), this, SLOT(step()));
 }

 void GuiModule::recvDatum(QString module, VDatum datum){
 	if(module == this->metaObject()->className()){
		dataIn(datum);
	}
 }


void GuiModule::setData(QString ID, QVariant value, QTime timestamp, QVariant meta){
	VDatum datum;
	datum.id = ID;
	datum.value = value;
	datum.timestamp = timestamp;
	datum.meta = meta;
	emit sendData(datum);
}
void GuiModule::setData(VDatum datum){
	emit sendData(datum);
}
void GuiModule::setData(QList<VDatum> datums){
	foreach(VDatum datum, datums){
		emit sendData(datum);
	}
}

QVariant GuiModule::value(QString ID){return state->value(ID);}
bool GuiModule::boolValue(QString ID){return state->value(ID).toBool();}
int GuiModule::intValue(QString ID){return state->value(ID).toInt();}
double GuiModule::doubleValue(QString ID){return state->value(ID).toDouble();}
QString GuiModule::stringValue(QString ID){return state->value(ID).toString();}

void GuiModule::setLinks(AUVC_State_Data* stateIn, QMap<QString, QString>* configIn, bool debugIn){
	state = stateIn;
	configuration = configIn;
	debug = debugIn;
}
