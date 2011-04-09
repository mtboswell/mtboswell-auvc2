#include <QtCore/QCoreApplication>
#include "director.h"
#include "../misc/configloader.h"
#include "../state/state.h"
#include "../state/vdatum.h"
#include "../module/modulehub.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QMap<QString, QString> config;
    loadConfigFile(config);
    AUVC_State_Data stateData;

    director d(&config, &stateData);


    return a.exec();
}
