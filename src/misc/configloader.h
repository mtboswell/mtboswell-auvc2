#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <QMap>
#include <QFile>
#include <QStringList>
#include <QTextStream>

//typedef QMap<QString, QString> StringTable;
extern QMap<QString, QString> config;
extern QFile * confFile;
static QStringList confFileContents;

void loadConfigFile(QMap<QString, QString> & config);
void saveConfig(QString id);
void saveAllConfigs();

#endif
