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
    paramList["Vision_OutputImage"] = &VisionModel_U.OutputImage;
    paramList["Vision_DesiredPathDirection"] = &VisionModel_U.DesiredPathDirection;
    paramList["Vision_DesiredBuoyColor"] = &VisionModel_U.DesiredBuoyColor;
    paramList["Vision_DesiredTorpedoColor"] = &VisionModel_U.DesiredTorpedoColor;
    paramList["Vision_white_al"] = &VisionModel_U.white_al;
    paramList["Vision_white_au"] = &VisionModel_U.white_au;
    paramList["Vision_white_bl"] = &VisionModel_U.white_bl;
    paramList["Vision_white_bu"] = &VisionModel_U.white_bu;
    paramList["Vision_black_al"] = &VisionModel_U.black_al;
    paramList["Vision_black_au"] = &VisionModel_U.black_au;
    paramList["Vision_black_bl"] = &VisionModel_U.black_bl;
    paramList["Vision_black_bu"] = &VisionModel_U.black_bu;
    paramList["Vision_blue_al"] = &VisionModel_U.blue_al;
    paramList["Vision_blue_au"] = &VisionModel_U.blue_au;
    paramList["Vision_blue_bl"] = &VisionModel_U.blue_bl;
    paramList["Vision_red_al"] = &VisionModel_U.red_al;
    paramList["Vision_red_au"] = &VisionModel_U.red_au;
    paramList["Vision_red_bl"] = &VisionModel_U.red_bl;
    paramList["Vision_red_bu"] = &VisionModel_U.red_bu;
    paramList["Vision_orange_al"] = &VisionModel_U.orange_al;
    paramList["Vision_orane_au"] = &VisionModel_U.orane_au;
    paramList["Vision_orange_bl"] = &VisionModel_U.orange_bl;
    paramList["Vision_orange_bu"] = &VisionModel_U.orange_bu;
    paramList["Vision_yellow_al"] = &VisionModel_U.yellow_al;
    paramList["Vision_yellow_bl"] = &VisionModel_U.yellow_bl;
    paramList["Vision_yellow_bu"] = &VisionModel_U.yellow_bu;
    paramList["Vision_green_al"] = &VisionModel_U.green_al;
    paramList["Vision_green_au"] = &VisionModel_U.green_au;
    paramList["Vision_breen_bl"] = &VisionModel_U.breen_bl;
    paramList["Vision_green_bu"] = &VisionModel_U.green_bu;
    paramList["Vision_black_override"] = &VisionModel_U.black_override;
    paramList["Vision_white_override"] = &VisionModel_U.white_override;
    paramList["Vision_blue_override"] = &VisionModel_U.blue_override;
    paramList["Vision_red_override"] = &VisionModel_U.red_override;
    paramList["Vision_orange_override"] = &VisionModel_U.orange_override;
    paramList["Vision_yellow_override"] = &VisionModel_U.yellow_override;
    paramList["Vision_green_override"] = &VisionModel_U.green_override;

    VisionModel_initialize();
}

/**
 *  Quit running this module if we receive a VDatum.value of "STOP"
 */
void Vision::dataIn(VDatum datum)
{
    if(datum.id == "Mode")
	{
    	if(datum.value == "Stop") stopped = true;
    	else stopped = false;
	}
	else if (datum.id == "Parameter.Vision.ModeSelect") {
		qDebug() << "Changing ModeSelect to in Vision: " << datum.value.toInt();
		count = 0;
		switch (datum.value.toInt()) {
			case 0: processingFrontCamera = true; processingDownCamera = true; break;
			case 1: processingFrontCamera = true;  processingDownCamera = false; break;
			case 2: processingFrontCamera = false; processingDownCamera = true;  break;
			case 3: processingFrontCamera = true;  processingDownCamera = false; break;
			default: break;
		}
	}
}

void Vision::printStuff()
{
    std::cout << "Vision_white_al"<< " " <<  VisionModel_U.white_al<< std::endl;
    std::cout << "Vision_white_au"<< " " <<  VisionModel_U.white_au<< std::endl;
    std::cout << "Vision_white_bl"<< " " <<  VisionModel_U.white_bl<< std::endl;
    std::cout << "Vision_white_bu"<< " " <<  VisionModel_U.white_bu<< std::endl;
    std::cout << "Vision_black_al"<< " " <<  VisionModel_U.black_al<< std::endl;
    std::cout << "Vision_black_au"<< " " <<  VisionModel_U.black_au<< std::endl;
    std::cout << "Vision_black_bl"<< " " <<  VisionModel_U.black_bl<< std::endl;
    std::cout << "Vision_black_bu"<< " " <<  VisionModel_U.black_bu<< std::endl;
    std::cout << "Vision_blue_al"<< " " <<  VisionModel_U.blue_al<< std::endl;
    std::cout << "Vision_blue_au"<< " " <<  VisionModel_U.blue_au<< std::endl;
    std::cout << "Vision_blue_bl"<< " " <<  VisionModel_U.blue_bl<< std::endl;
    std::cout << "Vision_red_al"<< " " <<  VisionModel_U.red_al<< std::endl;
    std::cout << "Vision_red_au"<< " " <<  VisionModel_U.red_au<< std::endl;
    std::cout << "Vision_red_bl"<< " " <<  VisionModel_U.red_bl<< std::endl;
    std::cout << "Vision_red_bu"<< " " <<  VisionModel_U.red_bu<< std::endl;
    std::cout << "Vision_orange_al"<< " " <<  VisionModel_U.orange_al<< std::endl;
    std::cout << "Vision_orane_au"<< " " <<  VisionModel_U.orane_au<< std::endl;
    std::cout << "Vision_orange_bl"<< " " <<  VisionModel_U.orange_bl<< std::endl;
    std::cout << "Vision_orange_bu"<< " " <<  VisionModel_U.orange_bu<< std::endl;
    std::cout << "Vision_yellow_al"<< " " <<  VisionModel_U.yellow_al<< std::endl;
    std::cout << "Vision_yellow_bl"<< " " <<  VisionModel_U.yellow_bl<< std::endl;
    std::cout << "Vision_yellow_bu"<< " " <<  VisionModel_U.yellow_bu<< std::endl;
    std::cout << "Vision_green_al"<< " " <<  VisionModel_U.green_al<< std::endl;
    std::cout << "Vision_green_au"<< " " <<  VisionModel_U.green_au<< std::endl;
    std::cout << "Vision_breen_bl"<< " " <<  VisionModel_U.breen_bl<< std::endl;
    std::cout << "Vision_green_bu"<< " " <<  VisionModel_U.green_bu<< std::endl;
    std::cout << "Vision_black_override"<< " " <<  VisionModel_U.black_override<< std::endl;
    std::cout << "Vision_white_override"<< " " <<  VisionModel_U.white_override<< std::endl;
    std::cout << "Vision_blue_override"<< " " <<  VisionModel_U.blue_override<< std::endl;
    std::cout << "Vision_red_override"<< " " <<  VisionModel_U.red_override<< std::endl;
    std::cout << "Vision_orange_override"<< " " <<  VisionModel_U.orange_override<< std::endl;
    std::cout << "Vision_yellow_override"<< " " <<  VisionModel_U.yellow_override<< std::endl;
    std::cout << "Vision_green_override"<< " " <<  VisionModel_U.green_override<< std::endl;
}

/**
 * Initialize this Simulink Module by displaying
 *  Called by: constructor
 *  Pre-condition: None
 *  Post-condition: stopped is false
 */
void Vision::init()
{
    count = 0;
    const int UPDATE_RATE = 1;    // num updates per seconds
    stopped = false;
    qDebug("Vision thread id: %d", (int) QThread::currentThreadId());

	//sets up the network stream if required
        if(networkStreams)
        {
                videoSocketFront = new QUdpSocket();
                videoSocketFront->connectToHost(QHostAddress(config("TargetedImageFront.address")), config("TargetedImageFront.port").toInt());
                videoOutFront = new QImageWriter(videoSocketFront, "jpeg");
                videoOutFront->setQuality(config("TargetedImageFront.quality").toInt());

                videoSocketDown = new QUdpSocket();
                videoSocketDown->connectToHost(QHostAddress(config("TargetedImageDown.address")), config("TargetedImageDown.port").toInt());
                videoOutDown = new QImageWriter(videoSocketDown, "jpeg");
                videoOutDown->setQuality(config("TargetedImageDown.quality").toInt());
	}
	
	processingFrontCamera = true;
	processingDownCamera = true;
	//Have vision run as fast as possible instead of on a timer
	//QObject::connect(this, SIGNAL(processVision()), this, SLOT(step()));
	//emit processVision();
    stepTimer->start(666);
    //stepTimer->start(1000 / UPDATE_RATE);  //This should be the last line in this function
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
             *  before executin the Simulink function
     */
    updateParameters();
    //printStuff();

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

	//qDebug() << "Vision:: Success";
    }
    else if (debug) std::cerr << "Vision::step(): Could not populate Simulink Camera parameters" << std::endl;
    // call the function
    VisionModel_step();

//    real_T PathState;                    /* '<Root>/PathState' */
//    real_T BuoyColors[100];              /* '<Root>/BuoyColors' */
//    real_T FireAuthorization;            /* '<Root>/FireAuthorization' */
//    real_T TargetType;                   /* '<Root>/TargetType' */
//    real_T TargetSize[19200];            /* '<Root>/TargetSize' */

    setData("Vision.Output.TargetSelect", VisionModel_Y.TargetSelect);
    setData("Vision.Output.MaintainHeading", VisionModel_Y.MaintainHeading);
    setData("TargetData.Position.X", VisionModel_Y.TargetX);
    setData("TargetData.Position.Y", VisionModel_Y.TargetY);
    setData("TargetData.Position.Z", VisionModel_Y.TargetZ);
    setData("TargetData.Position.Bearing", VisionModel_Y.TargetYaw);
    setData("Vision.Output.DesiredTargetX", VisionModel_Y.DesiredTargetX);      // redundant
    setData("Vision.Output.DesiredTargetY", VisionModel_Y.DesiredTargetY);      // redundant
    setData("Vision.Output.DesiredTargetZ", VisionModel_Y.DesiredTargetZ);      // redundant
    setData("Vision.Output.DesiredTargetYaw", VisionModel_Y.DesiredTargetYaw);  // redundant
    setData("Vision.Output.TargetDetected", VisionModel_Y.TargetDetected);
    setData("Vision.Output.PathState", VisionModel_Y.PathState);
    setData("Vision.Output.FireAuthorization", VisionModel_Y.FireAuthorization);
    setData("Vision.Output.TargetType", VisionModel_Y.TargetType);

//    setData("Vision.Output.MeasuredZ", VisionModel_Y.MeasuredZ);                // sensor
//    setData("Vision.Output.MeasuredYAccel", VisionModel_Y.MeasuredYAccel);      // sensor
//    setData("Vision.Output.MeasuredYaw", VisionModel_Y.MeasuredYaw);            // sensor
//    setData("Vision.Output.MeasuredYawRate", VisionModel_Y.MeasuredYawRate);    // sensor
//    if (value("Command")=="DeadReckon")
//    {
//        setData("DeadReckon.Depth", VisionModel_Y.DesiredZ);
//        setData("DeadReckon.ForwardSpeed", VisionModel_Y.DesiredXVelocity);
//        setData("DeadReckon.Heading", VisionModel_Y.DesiredYaw);
//    }
//    setData("Vision.Output.TargetDetected", VisionModel_Y.TargetDetected);      //custom output
//    setData("Vision.Output.PathState", VisionModel_Y.PathState);                //custom output
//    setData("Vision.Output.BuoyColors", VisionModel_Y.BuoyColors);              //custom output
//    setData("Vision.Output.FireAuthorization", VisionModel_Y.FireAuthorization);//custom output

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
	//qDebug() << networkStreams << f_height << f_width << processingFrontCamera;
    if (networkStreams && f_height == 160 && f_width == 120 && processingFrontCamera)
    {
        targetedImageFront = new QImage(60, 80, QImage::Format_RGB32);
        //used for streaming the targeted image
        for (int i = 0; i < f_height; i = i + 2)
        {
            for (int j = 0; j < f_width; j = j + 2)
            {
                int index = j*(f_height)+i;
                QRgb col;
		//std::cout << VisionModel_Y.R_forward_out[index] << " ";
                col = qRgb(VisionModel_Y.R_forward_out[index] * 255.0, VisionModel_Y.G_forward_out[index] * 255.0, VisionModel_Y.B_forward_out[index] * 255.0);
                targetedImageFront->setPixel(j/2, i/2, col);
            }
        }
		targetedImageFront->save("targetedFront.bmp");
		//qDebug() << "Writing targeted front image to comptuer";
        videoOutFront->write(*targetedImageFront);
        targetedImageFront->~QImage();
    }
    if (networkStreams && d_height == 160 && d_width == 120 && processingDownCamera)
    {
        targetedImageDown = new QImage(80, 60, QImage::Format_RGB32);
        //used for streaming the targeted image
        for (int i = 0; i < d_height; i = i + 2)
        {
            for (int j = 0; j < d_width; j = j + 2)
            {
                int index = j*(d_height)+i;
                QRgb col;
                col = qRgb(VisionModel_Y.R_down_out[index] * 255.0, VisionModel_Y.G_down_out[index] * 255.0, VisionModel_Y.B_down_out[index] * 255.0);
                targetedImageDown->setPixel(j/2, i/2, col);
            }
        }
        videoOutDown->write(*targetedImageFront);
        targetedImageDown->~QImage();
    }
//	qDebug() << "Finished Vision";
	//usleep(3000000);
	//emit processVision();
}
