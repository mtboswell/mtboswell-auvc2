#include "simulinkmodule.h"

void SimulinkModule::initializeParameters(){
	QMapIterator<QString, double*> i(paramList);
	while (i.hasNext()) {
		i.next();
		QString paramID = "Parameter."+i.key();
		state->setData(paramID.replace('_','.'), (*i.value()));
	}
}
void SimulinkModule::updateParameters(){
	QMapIterator<QString, double*> i(paramList);
	while (i.hasNext()) {
		i.next();
		QString paramID = "Parameter."+i.key();
		(*i.value()) = state->value(paramID.replace('_','.')).toDouble();
	}
}
