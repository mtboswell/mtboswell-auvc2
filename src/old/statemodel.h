#ifndef STATEMODEL_H
#define STATEMODEL_H


//#include "stateitem.h"
#include "treemodel.h"

class StateModel
{
	Q_OBJECT
	public:
		StateModel(){
			QStringList headers;
			headers << "ID" << "Value" << "Timestamp" << "Availability" << "Meta";
			data_model = new TreeModel(headers, this);
		}

		QString serialize();

		QVector<QVariant> operator[](QString ID);

	private:
		TreeModel* data_model;

};



#endif
