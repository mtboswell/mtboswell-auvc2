#include "version.h"


QString getVersion(){
#ifdef _WIN32
	return QString();
#endif
	QProcess hg;
	hg.start("hg identify -i");
	if (!hg.waitForStarted())
		return QString();

	if (!hg.waitForFinished())
		return QString();

	QString result(hg.readAll());
	if(result.contains("abort")) 
		return QString();
	else return result.trimmed();
}
