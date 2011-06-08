#ifndef VISION_H
#define VISION_H

#include "vdatum.h"
#include "simulinkmodule.h"
#include <QDebug>
#include <QVector4D>
#include "src/VisionModel.h"

/** @author Shawn Furrow, Carlo del Mundo
 *  This class is the bridge between the C++ State Data and the Matlab Simulink VisionModel.mdl file.
 *  It's primary function is to:
 *      1.) Populate the inputs seen in the Simulink block diagram
 *      2.) Run the block diagram
 *      3.) Extract the outputs and place it onto state data
 */
class Vision : public SimulinkModule
{
    Q_OBJECT;
    public:
        Vision();
        QStringList subscriptions()
        {
                QStringList sub;
//                sub << ""; // subscribe to all
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
        QTimer *timer;  // work around to initialize values for statedata
};

#endif // VISION_H
