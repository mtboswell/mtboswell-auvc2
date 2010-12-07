#ifndef TMF_H
#define TMF_H

#include <QStringList>
#include <QMap>

// tree item format
struct TIF {
	QString ID;
	QVariant value;
	QTime timestamp;
	bool available;
	QVariant meta;
}

// tree message format
struct TMF {
	QString parentID;
	QList<TIF> treeItems;
};

TMF parseTMF(QByteArray treeData);

QString serializeTIF(TIF treeItem);
QString serializeTMF(TMF tree);

#endif
