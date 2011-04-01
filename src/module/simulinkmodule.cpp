#include "simulinkmodule.h"
#include <QDebug>

void SimulinkModule::initializeParameters(){
	QMapIterator<QString, double*> i(paramList);
	while (i.hasNext()) {
		i.next();
		QString paramID = "Parameter."+i.key();
		setData(paramID.replace('_','.'), *(i.value()));
	//	qDebug() << "setData(paramID.replace('_','.'), *(i.value()));" << paramID.replace('_','.') << *(i.value());
	}
}
void SimulinkModule::updateParameters(){
	QMapIterator<QString, double*> i(paramList);
	while (i.hasNext()) {
		i.next();
		QString paramID = "Parameter."+i.key();
		*(paramList[i.key()]) = doubleValue(paramID.replace('_','.'));
	}
}
