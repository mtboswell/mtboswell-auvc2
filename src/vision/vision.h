#ifndef VISION_H
#define VISION_H

#include "vdatum.h"
#include "simulinkmodule.h"
#include <QDebug>
#include <QVector4D>
#include <QUdpSocket>
#include <QImageWriter>
#include "src/VisionModel.h"

/** @author Shawn Furrow, Carlo del Mundo
 *  This class is the bridge between the C++ State Data and the Matlab Simulink VisionModel.mdl file.
 *  It's primary function is to:
 *      1.) Populate the inputs seen in the Simulink block diagram
 *      2.) Run the block diagram
 *      3.) Extract the outputs and place it onto state data
 */

extern bool networkStreams;
class Vision : public SimulinkModule
{
    Q_OBJECT;
    public:
        Vision();
	void printStuff();
        QStringList subscriptions()
        {
                QStringList sub;
//                sub << ""; // subscribe to all
                sub << "Mode";
				sub << "Parameter.Vision.ModeSelect";
                return sub;
        }
	signals:
		void processVision();
    public slots:

        void dataIn(VDatum message);

    private slots:
        void init();
        void step();

    private:
        bool stopped;
		bool processingFrontCamera;
		bool processingDownCamera;
        QTimer *timer;  // work around to initialize values for statedata (possibly not used)
        QImage *targetedImageFront;
        QImage *targetedImageDown;
        QImageWriter *videoOutFront;
        QImageWriter *videoOutDown;
        QUdpSocket *videoSocketFront;
        QUdpSocket *videoSocketDown;
	int count;

 };

#endif // VISION_H
