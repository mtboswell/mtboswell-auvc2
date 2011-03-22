#ifndef SERVER_JAUS_H
#define SERVER_JAUS_H

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
#include "jaus/mobility/sensors/velocitystatesensor.h"
#include "jaus/core/transport/judp.h"
#include "jaus/core/component.h"

/**
 * Communication layer between Brain/AUV and network (SAE JAUS interop version).
 * Powered by JAUS++ <http://active-ist.sourceforge.net/>
 * @author: Ben Guzzardi
 * @date 7/15/2010
 */

class JAUSServer : public QThread {
Q_OBJECT
	public:
		/**
		 * Constructor
		 */
		JAUSServer(int subsystemid, int nodeid, int compid);
		virtual ~JAUSServer();
		void run();
	private:
		JAUS::UShort mySubsystemID;
		JAUS::Byte myNodeID;
		JAUS::Byte myComponentID;

		JAUS::Component myComponent;
		JAUS::LocalPoseSensor* myLocalPoseSensor;
		JAUS::GlobalPoseSensor* myGlobalPoseSensor;
		JAUS::VelocityStateSensor* myVelocityStateSensor;
		JAUS::JUDP* myTransportService;
	public slots:
		void updateSensors(AUVSensors input);
};

#endif
