#include "configloader.h"

void loadConfigFile(){
	// look in the following places for the config file:
	QStringList confFileLocations;
	confFileLocations << "auvrc";
	confFileLocations << "~/.auvrc";
	confFileLocations << "/etc/auvrc";
	confFileLocations << ".auvrc";

	int fileIndex = 0;
	do{
		confFile = QFile(confFileLocations[fileIndex++]);
	} while(!confFile.open(QIODevice::ReadWrite | QIODevice::Text) && fileIndex < confFileLocations.size());

	if (fileIndex == confFileLocations.size())
		return;

	while (!confFile.atEnd()) {
		QByteArray line = confFile.readLine();
		confFileContents.append(line);
		if(!line.startsWith('#') && line.contains('='))
			config[SIDLine.split(';')[0].split('=')[0]] = SIDLine.split(';')[0].split('=')[1];
	}
}


void saveConfig(QString id){
	if(!confFile.isOpen() || confFileContents.isEmpty()) return;
	confFileContents.replaceInStrings(QRegExp(id+"=.*;"),id+"="+config[id]+";")
	confFile.resize(0);
	QTextStream out(&confFile);
	out << confFileContents.join('\n');
	out.flush();
	confFile.flush();
}
void saveAllConfigs(){
	if(!confFile.isOpen() || confFileContents.isEmpty()) return;
	foreach(QString id, config.keys()){
		confFileContents.replaceInStrings(QRegExp(id+"=.*;"),id+"="+config[id]+";")
	}
	confFile.resize(0);
	QTextStream out(&confFile);
	out << confFileContents.join('\n');
	out.flush();
	confFile.flush();
}

loadConfigFile();
