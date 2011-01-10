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

/* this is for future expansion
// tree message format
typedef struct VData {
	QString parentID;
	QList<VDatum> treeItems;
} VData;

VData parseVData(QByteArray treeData);

*/
QList<VDatum> parseVDatums(QByteArray treeData);

QByteArray serializeVDatum(VDatum datum);
QByteArray serializeVDatums(QList<VDatum> datums);

//QByteArray serializeVData(VData tree);

#endif
