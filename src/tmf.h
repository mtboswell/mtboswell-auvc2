#ifndef VData_H
#define VData_H

#include <QStringList>
#include <QMap>
#include <QTime>
#include <QVariant>

// tree item format
typedef struct VDatum {
	QString ID;
	QVariant value;
	QTime timestamp;
	bool available;
	QVariant meta;
} VDatum;

// tree message format
typedef struct VData {
	QString parentID;
	QList<VDatum> treeItems;
} VData;

VData parseVData(QByteArray treeData);

QByteArray serializeVDatum(VDatum treeItem);
QByteArray serializeVData(VData tree);

#endif
