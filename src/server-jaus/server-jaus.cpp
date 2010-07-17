#include "../configloader.h"
#include "../brain/brain.h"
#include "../auv/auvtypes.h"
#include "../model/parameters.h"
#include "../version.h"
#include "sidsocket.h"
#include <QThread>
#include <QTimer>
#include <QByteArray>
#include <QHostAddress>
#include <QStringList>
#include <QMutex>
#include "jaus/mobility/sensors/localposesensor.h"
#include "jaus/mobility/sensors/globalposesensor.h"
#include "jaus/mobility/sensors/velocitystatesensor.h"
#include "jaus/core/transport/judp.h"
#include "jaus/core/component.h"
#include "cxutils/cxutils.h"
#include "server-jaus.h"

/**
 * Communication layer between Brain/AUV and network (SAE-JAUS interop version).
 * Powered by JAUS++ <http://active-ist.sourceforge.net/>
 * @author: Ben Guzzardi
 * @date 7/15/2010
 */

JAUSServer::JAUSServer(int subsystemid = 116, int nodeid = 1, int compid = 1) {
	mySubsystemID = subsystemid;
	myNodeID = nodeid;
	myComponentID = compid;

	myLocalPoseSensor = new JAUS::LocalPoseSensor();
	myGlobalPoseSensor = new JAUS::GlobalPoseSensor();
	myVelocityStateSensor = new JAUS::VelocityStateSensor();
}

void JAUSServer::run() {
	JAUS::LocalPose lp;
	JAUS::GlobalPose gp;
	myLocalPoseSensor->SetSensorUpdateRate(5);
	myGlobalPoseSensor->SetSensorUpdateRate(5);
	myVelocityStateSensor->SetSensorUpdateRate(5);

	myTransportService = (JAUS::JUDP*)myComponent.TransportService();

	myComponent.AccessControlService()->SetTimeoutPeriod(0);
	myComponent.AddService(myGlobalPoseSensor);
	myComponent.AddService(myLocalPoseSensor);
	myComponent.AddService(myVelocityStateSensor);
	myComponent.DiscoveryService()->SetSubsystemIdentification(JAUS::Subsystem::Vehicle, "Barreleye");
	if (!myComponent.Initialize(JAUS::Address(mySubsystemID, myNodeID, myComponentID))) {
		std::cerr << "Failed to initialize JAUS component\n";
		return;
	}

	myTransportService->EnableLogging(true);
//	myTransportService->AddConnection("127.0.0.1", JAUS::Address(90,1,1));
	myTransportService->AddConnection("192.168.1.42", JAUS::Address(42,1,1));
	myComponent.ManagementService()->SetStatus(JAUS::Management::Status::Standby);
//	lp.SetX(1);
//	lp.SetY(2);
//	lp.SetZ(3);
	gp.SetYaw(0.0);
	myLocalPoseSensor->SetLocalPose(lp);
	exec();
}

JAUSServer::~JAUSServer() {
	myComponent.Shutdown();
}

void JAUSServer::updateSensors(AUVSensors input) {
	JAUS::GlobalPose gp;
	JAUS::VelocityState vs;
	imu_data dat = input.orientation;
    	gp.SetLatitude(38.253919);
   	gp.SetLongitude(-117.253919);
    	gp.SetAltitude(300);
	gp.SetPositionRMS(0.0);
	gp.SetAttitudeRMS(0.0);
	gp.SetRoll(0.0);
	gp.SetPitch(0.0);
	gp.SetYaw(CxUtils::CxToRadians(dat.yaw - 180.0));
	gp.SetTimeStamp(JAUS::Time::GetUtcTime());
	vs.SetVelocityX(CxUtils::CxToRadians(dat.yawrate));
//	vs.SetVelocityX(input.thrusterSpeeds[0]/127.0 + input.thrusterSpeeds[1]/127.0);
	vs.SetVelocityY(input.thrusterSpeeds[2]/127.0);
//	vs.SetVelocityY(dat.yaw);
	vs.SetVelocityZ(input.thrusterSpeeds[3]/127.0);
	vs.SetTimeStamp(JAUS::Time::GetUtcTime());
	myGlobalPoseSensor->SetGlobalPose(gp);
	myLocalPoseSensor->SetLocalPose(gp);
	myVelocityStateSensor->SetVelocityState(vs);

	qDebug("");
    myComponent.AccessControlService()->PrintStatus(); //std::cout << std::endl;
    myComponent.DiscoveryService()->PrintStatus(); //std::cout << std::endl;
    myComponent.TransportService()->PrintStatus();
    myComponent.ManagementService()->PrintStatus(); //std::cout << std::endl;
    //globalPoseSensor->PrintStatus(); std::cout << std::endl;
    myGlobalPoseSensor->PrintStatus(); //qDebug("\n");//std::cout << std::endl;
    myLocalPoseSensor->PrintStatus(); //qDebug("\n");//std::cout << std::endl;
    myVelocityStateSensor->PrintStatus(); //qDebug("\n");//std::cout << std::endl;
    //localWaypointListDriver->PrintStatus();
    //printTimeMs = JAUS::Time::GetUtcTimeMs();
}
