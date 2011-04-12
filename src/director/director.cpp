#include "director.h"
#include <QDebug>
#include <QTimer>

director::director(QMap<QString, QString> *configIn, AUVC_State_Data *stateIn, QObject *parent)
		: Module(configIn, stateIn, parent)
{
    QTimer *t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(doSomething()));
    t->start(1000);
}

void director::dataIn(VDatum datum) {}

// TODO: FSM Design Pattern based on sensors and/or time duration
// TODO: State Interface
    //  exit()
    //  setState()
    //  entry()

void director::doSomething()
{
    QString myStr = "Depth.Kp";
    qDebug() << intValue(myStr) << "\n";
}
