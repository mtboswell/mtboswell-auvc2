#ifndef SID_H
#define SID_H

#include <QStringList>
#include <QMap>

struct SID {
	QStringList ID;
	QMap<QString, QString> Data;
};

SID parseSID(QString ID, QString Data);
SID parseSID(QString SID);

QString serializeSID(SID sidObj);

#endif
