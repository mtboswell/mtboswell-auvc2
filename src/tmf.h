#ifndef TMF_H
#define TMF_H

#include <QStringList>
#include <QMap>
#include <QTime>
#include <QVariant>

// tree item format
struct TIF {
	QString ID;
	QVariant value;
	QTime timestamp;
	bool available;
	QVariant meta;
};

// tree message format
struct TMF {
	QString parentID;
	QList<TIF> treeItems;
};

TMF parseTMF(QByteArray treeData);

QByteArray serializeTIF(TIF treeItem);
QByteArray serializeTMF(TMF tree);

#endif
