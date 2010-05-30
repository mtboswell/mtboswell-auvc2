#ifndef CONFIGLOADER_H
#define CONFIGLOADER_H

#include <QMap>
#include <QFile>
#include <QStringList>
#include <QTextStream>

static QMap<QString, QString> config;
static QFile confFile;
static QStringList confFileContents;

void loadConfigFile();
void saveConfig(QString id);
void saveAllConfigs();

#endif
