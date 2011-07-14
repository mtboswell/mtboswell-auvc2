#ifndef STATEDATA_H
#define STATEDATA_H

#include <QMap>
#include <QVarient>
#include <QString>
#include <QDebug>

class StateData
{
	Q_OBJECT
	public:
		StateData();
		void setData(QString name, QVarient value);
		QVarient getData(QString name);
		
	private:
		QMap data;
		
		
	
}


#endif
