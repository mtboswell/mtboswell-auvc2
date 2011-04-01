#include <QtGui/QApplication>
#include "mainwindow.h"
#include "../state/state.h"
#include "../module/modulehub.h"
#include "../misc/configloader.h"
#include <QTreeView>
#include <QString>

#include "controllers/controllers.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMap<QString, QString> config;
    loadConfigFile(config);
    AUVC_State_Data stateData;
    ModuleHub hub(&stateData);
    Module* controllers = new Controllers(&config, &stateData, &hub);
    hub.initializeAndLaunchAllModules();

    MainWindow w(0, &stateData);
    w.show();

    return a.exec();
}
