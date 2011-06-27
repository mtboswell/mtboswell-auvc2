#include "vision.h"
#include <iostream>

// These are the desired MAX values for (width, height) for both cameras.
// These are a poor man's error checking test so we don't write past array bounds
// Technically, these values are set in the Simulink module: VisionModel.mdl.
// Consult your Vision guru (David as of this writing)
const int FORWARD_CAM_MAX_WIDTH = 120;
const int FORWARD_CAM_MAX_HEIGHT = 160;
const int DOWNWARD_CAM_MAX_WIDTH = 160;
const int DOWNWARD_CAM_MAX_HEIGHT = 120;

Vision::Vision() : SimulinkModule()
{
    // Updated manually from files: 2.bmp, 3.bmp, see step() function below
//    paramList["Vision_R_forward_in"] = &VisionModel_U.R_forward_in;
//    paramList["Vision_G_forward_in"] = &VisionModel_U.G_forward_in;
//    paramList["Vision_B_forward_in"] = &VisionModel_U.B_forward_in;

//    paramList["Vision_R_down_in"] = &VisionModel_U.R_down_in;
//    paramList["Vision_G_down_in"] = &VisionModel_U.G_down_in;
//    paramList["Vision_B_down_in"] = &VisionModel_U.B_down_in;

    paramList["Vision_ModeSelect"] = &VisionModel_U.ModeSelect;
    paramList["Vision_DesiredPathDirection"] = &VisionModel_U.DesiredPathDirection;
    paramList["Vision_DesiredBuoyColor"] = &VisionModel_U.DesiredBuoyColor;
    paramList["Vision_DesiredTorpedoColor"] = &VisionModel_U.DesiredTorpedoColor;
    paramList["Vision_ProceedToSecondTarget"] = &VisionModel_U.ProceedToSecondTarget;
    paramList["Vision_DefaultTargetShape"] = &VisionModel_U.DefaultTargetShape;
    paramList["Vision_DefaultTargetColor"] = &VisionModel_U.DefaultTargetColor;
    paramList["Vision_ScaleForwardR"] = &VisionModel_P.Gain_Gain;
    paramList["Vision_ScaleForwardG"] = &VisionModel_P.Gain1_Gain;
    paramList["Vision_ScaleForwardB"] = &VisionModel_P.Gain2_Gain;
    paramList["Vision_ScaleForwardH"] = &VisionModel_P.Gain3_Gain;
    paramList["Vision_ScaleForwardS"] = &VisionModel_P.Gain4_Gain;
    paramList["Vision_ScaleForwardV"] = &VisionModel_P.Gain5_Gain;
    paramList["Vision_IterSegmentThresh"] = &VisionModel_P.Constant2_Value;
    VisionModel_initialize();
}

/**
 *  Quit running this module if we receive a VDatum.value of "STOP"
 */
void Vision::dataIn(VDatum datum)
{
    if(datum.id != "Mode") return;
    if(datum.value == "Stop") stopped = true;
    else stopped = false;
}

/**
 * Initialize this Simulink Module by displaying
 *  Called by: constructor
 *  Pre-condition: None
 *  Post-condition: stopped is false
 */
void Vision::init()
{
    const int UPDATE_RATE = 1;    // num updates per seconds
    stopped = false;
    qDebug("Vision thread id: %d", (int) QThread::currentThreadId());
    stepTimer->start(1000 / UPDATE_RATE);

	//sets up the network stream if required
	if(networkStreams) {
		videoSocket = new QUdpSocket();
		videoSocket->connectToHost(QHostAddress(config("TargetedImage.address")), config("TargetedImage.port").toInt());
		videoOut = new QImageWriter(videoSocket, "jpeg");
		videoOut->setQuality(config("TargetedImage.quality").toInt());
	}

	//Have vision run as fast as possible instead of on a timer
	QObject::connect(this, SIGNAL(processVision()), this, SLOT(step()));
	//emit processVision();
}

/**
 *  Called a set number of times every UPDATE_RATE seconds (see init()).
 *  WARNING: this is where we populate the Simulink inputs ... IT IS POSSIBLE to
 *  write past the VisionModel_U.R_forward_in (and other flavors) arrays.
 */
void Vision::step()
{
	
	//qDebug() << "Starting Vision";
    /**
     *  Queries the AUVC state data and makes sure we have the most current inputs
     *  before executing the Simulink function
     */
    updateParameters();

    // pull latest image from hard drive
    QImage *forwardCam = &(value("Camera.Forward.Frame").value<QImage>());
    QImage *downwardCam = &(value("Camera.Downward.Frame").value<QImage>());

    if (forwardCam == NULL || downwardCam == NULL)
        return;

    int f_width = forwardCam->width();
    int f_height = forwardCam->height();
    int d_width = downwardCam->width();
    int d_height = downwardCam->height();

//        std::cerr << "forward [w,h]" << f_width << " " << f_height << "  --- downward [w,h]" << d_width << " " << d_height << std::endl;
    if (f_width > FORWARD_CAM_MAX_WIDTH || f_height > FORWARD_CAM_MAX_HEIGHT || d_width > DOWNWARD_CAM_MAX_WIDTH || d_height > DOWNWARD_CAM_MAX_HEIGHT)
    {
        std::cerr << "Vision::step(): ERROR! Forward/Downward Camera Width/Height mismatch (got something larger)" << std::endl;
        return;
    }

    if (f_width > 0 && f_height > 0 && d_width > 0 && d_height > 0)
    {
        // populate image arrays for Simulink VisionModel.mdl
        for (int i = 0; i < f_height; ++i)
        {
            for (int j = 0; j < f_width; ++j)
            {
                int index = j*(forwardCam->height())+i;
                QColor forward_rgb = forwardCam->pixel(j, i);
                VisionModel_U.R_forward_in[index] = forward_rgb.red();
                VisionModel_U.G_forward_in[index] = forward_rgb.green();
                VisionModel_U.B_forward_in[index] = forward_rgb.blue();
            }
        }

        for (int i = 0; i < d_height; ++i)
        {
            for (int j = 0; j < d_width; ++j)
            {
                int index = j*(downwardCam->height())+i;
                QColor downward_rgb = downwardCam->pixel(j, i);
                VisionModel_U.R_down_in[index] = downward_rgb.red();
                VisionModel_U.G_down_in[index] = downward_rgb.green();
                VisionModel_U.B_down_in[index] = downward_rgb.blue();
            }
        }
    }
    else if (debug) std::cerr << "Vision::step(): Could not populate Simulink Camera parameters" << std::endl;

    // call the function
    VisionModel_step();

    // set the outputs of the function
    setData("TargetOptions.TargetSelect", VisionModel_Y.TargetSelect);
    setData("TargetData.Found", VisionModel_Y.TargetFound);
    setData("TargetOptions.MaintainHeading", VisionModel_Y.MaintainHeading);
    setData("TargetData.Position.X", VisionModel_Y.TargetX);
    setData("TargetData.Position.Y", VisionModel_Y.TargetY);
    setData("TargetData.Position.Z", VisionModel_Y.TargetZ);
    setData("TargetData.Position.Bearing", VisionModel_Y.TargetYaw);
    setData("Vision.Output.DesiredTargetX", VisionModel_Y.DesiredTargetX);      // redundant
    setData("Vision.Output.DesiredTargetY", VisionModel_Y.DesiredTargetY);      // redundant
    setData("Vision.Output.DesiredTargetZ", VisionModel_Y.DesiredTargetZ);      // redundant
    setData("Vision.Output.DesiredTargetYaw", VisionModel_Y.DesiredTargetYaw);  // redundant
    setData("Vision.Output.MeasuredZ", VisionModel_Y.MeasuredZ);                // sensor
    setData("Vision.Output.MeasuredYAccel", VisionModel_Y.MeasuredYAccel);      // sensor
    setData("Vision.Output.MeasuredYaw", VisionModel_Y.MeasuredYaw);            // sensor
    setData("Vision.Output.MeasuredYawRate", VisionModel_Y.MeasuredYawRate);    // sensor
    setData("DeadReckon.Depth", VisionModel_Y.DesiredZ);
    setData("DeadReckon.ForwardSpeed", VisionModel_Y.DesiredXVelocity);
    setData("DeadReckon.Heading", VisionModel_Y.DesiredYaw);
    setData("Vision.Output.TargetDetected", VisionModel_Y.TargetDetected);      //custom output
    setData("Vision.Output.PathState", VisionModel_Y.PathState);                //custom output
    setData("Vision.Output.BuoyColors", VisionModel_Y.BuoyColors);              //custom output
    setData("Vision.Output.FireAuthorization", VisionModel_Y.FireAuthorization);//custom output

    //    setData("TargetOptions.TargetSelect", VisionModel_Y.TargetSelect);
    //    setData("TargetData.Found", VisionModel_Y.TargetFound);
    //    setData("TargetOptions.MaintainHeading", VisionModel_Y.MaintainHeading);
    //    setData("TargetData.Position.X", VisionModel_Y.TargetX);
    //    setData("TargetData.Position.Y", VisionModel_Y.TargetY);
    //    setData("TargetData.Position.Z", VisionModel_Y.TargetZ);
    //    setData("TargetData.Position.Bearing", VisionModel_Y.TargetYaw);
    //    setData("Vision.Output.DesiredTargetX", VisionModel_Y.DesiredTargetX);
    //    setData("Vision.Output.DesiredTargetY", VisionModel_Y.DesiredTargetY);
    //    setData("Vision.Output.DesiredTargetZ", VisionModel_Y.DesiredTargetZ);
    //    setData("Vision.Output.DesiredTargetYaw", VisionModel_Y.DesiredTargetYaw);
    //    setData("Vision.Output.MeasuredZ", VisionModel_Y.MeasuredZ);
    //    setData("Vision.Output.MeasuredYAccel", VisionModel_Y.MeasuredYAccel);
    //    setData("Vision.Output.MeasuredYaw", VisionModel_Y.MeasuredYaw);
    //    setData("Vision.Output.MeasuredYawRate", VisionModel_Y.MeasuredYawRate);
    //    setData("Vision.Output.DesiredZ", VisionModel_Y.DesiredZ);
    //    setData("Vision.Output.DesiredXVelocity", VisionModel_Y.DesiredXVelocity);
    //    setData("Vision.Output.DesiredYaw", VisionModel_Y.DesiredYaw);
    //    setData("Vision.Output.TargetDetected", VisionModel_Y.TargetDetected);
    //    setData("Vision.Output.PathState", VisionModel_Y.PathState);
    //    setData("Vision.Output.BuoyColors", VisionModel_Y.BuoyColors);
    //    setData("Vision.Output.FireAuthorization", VisionModel_Y.FireAuthorization);

	if (networkStreams) {
		targetedImage = new QImage(120, 160, QImage::Format_RGB32);
		
		
		//used for streaming the targeted image
		for (int i = 0; i < f_height; ++i)
		{
			for (int j = 0; j < f_width; ++j)
		    {
				int index = j*(f_height)+i;
				QRgb col;
				col = qRgb(VisionModel_Y.R[index] * 255.0, VisionModel_Y.G[index] * 255.0, VisionModel_Y.B[index] * 255.0);
				targetedImage->setPixel(j, i, col);
			}
		}
		videoOut->write(*targetedImage);
		targetedImage->~QImage();
	}
//	qDebug() << "Finished Vision";
	//usleep(3000000);
	//emit processVision();
}
