#ifndef VISION_H
#define VISION_H

#include "vdatum.h"
#include "simulinkmodule.h"
#include <QDebug>
#include <QVector4D>

class Vision : public SimulinkModule
{
    Q_OBJECT;
    public:
        Vision();
        QStringList subscriptions(){
                QStringList sub;
                //sub << ""; // subscribe to all
                sub << "Mode";
                return sub;
        }
    public slots:

        void dataIn(VDatum message);

    private slots:
        void init();
        void step();

    private:
        bool stopped;
};

#endif // VISION_H
