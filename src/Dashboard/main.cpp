#include <QtGui/QApplication>
#include "mainwindow.h"
#include "../state.h"
#include "../datahub/datahub.h"
#include <QTreeView>
#include <QString>

#include "controllers/controllers.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMap<QString, QString> config;
    loadConfigFile(config);
    AUVC_State_Data stateData;
    DataHub hub(&stateData);
    Module* controllers = new Controllers(&config, &stateData, &hub);
    hub.initializeAndLaunchAllModules();

    MainWindow w(0, &stateData);
    w.show();

    return a.exec();
}
