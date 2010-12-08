#include "configloader.h"
#include <QDebug>
#include <QDir>

QFile * confFile;

void loadConfigFile(QMap<QString, QString> &config){
	// look in the following places for the config file:
	QStringList confFileLocations;
	confFileLocations << "../src/.auvrc";
	confFileLocations << QDir::homePath() + "/auvc/src/.auvrc";
	confFileLocations << "auvrc";
	confFileLocations << QDir::homePath()+"/.auvrc";
	confFileLocations << "/etc/auvrc";
	confFileLocations << ".auvrc";

	qDebug() << "Searching for config file";
	int fileIndex = 0;
	do{
		if(confFile) delete confFile;
		//qDebug() << "Looking in: " + confFileLocations[fileIndex];
		confFile = new QFile(confFileLocations[fileIndex++]);
	} while((!confFile->exists() || !confFile->open(QIODevice::ReadWrite | QIODevice::Text)) && fileIndex < confFileLocations.size());

	if (fileIndex == confFileLocations.size()){
		qDebug() << "Config file not found, everything will not work right.";
		qDebug() << "Exiting.";
		exit(1);
	}

	qDebug() << "Loading File: " << confFile->fileName();
	while (!confFile->atEnd()) {
		QByteArray line = confFile->readLine();
		confFileContents.append(line);
		if(!line.startsWith('#') && line.contains('=')){
			//qDebug() << "Loading Line: " << line;
			config[line.split(';')[0].split('=')[0]] = line.split(';')[0].split('=')[1];
		}
	}
	if(config["Debug"]=="true") qDebug() << "Loaded Configuration:" << config;
}


/*
void saveConfig(QString id){
	if(!confFile || !confFile->isOpen() || confFileContents.isEmpty()) return;
	confFileContents.replaceInStrings(QRegExp(id+"=.*;"),id+"="+config[id]+";");
	confFile->resize(0);
	QTextStream out(confFile);
	out << confFileContents.join("\n");
	out.flush();
	confFile->flush();
}
void saveAllConfigs(){
	if(!confFile || !confFile->isOpen() || confFileContents.isEmpty()) return;
	foreach(QString id, config.keys()){
		confFileContents.replaceInStrings(QRegExp(id+"=.*;"),id+"="+config[id]+";");
	}
	confFile->resize(0);
	QTextStream out(confFile);
	out << confFileContents.join("\n");
	out.flush();
	confFile->flush();
}
*/
