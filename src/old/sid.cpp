#include "sid.h"

SID parseSID(QString ID, QString Data){
	SID out;
	out.ID = id.split(QRegExp("[._]"), QString::SkipEmptyParts);

	QStringList dataList = Data.split(",", QString::SkipEmptyParts); 
	foreach(QString datum, dataList){
		QStringList datumParts = datum.split(":", QString::SkipEmptyParts);
		if(datumParts.size() < 2) continue;
		out.Data[datumParts[0]] = datumParts[1];
	}
	return out;
}

QList<SID> parseSIDs(QString SIDs){
	QStringList SIDlist = SIDs.split(';');
	foreach (QString thisSID, SIDlist) {
		if (((ID=thisSID.split('=')).size() == 2)) {
			return parseSID(ID[0], ID[1]);
		}
	}
}

QString serializeSID(SID sidObj){

	m_outBuffer.append(ID);
	m_outBuffer.append("=");
	m_outBuffer.append(data);
	m_outBuffer.append(";");
}

