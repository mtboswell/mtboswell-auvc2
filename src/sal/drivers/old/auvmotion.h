#ifndef AUVMOTION_H
#define AUVMOTION_H

#include <QThread>



class AUVMotion : public QThread
{
	Q_OBJECT
	public:
		AUVMotion(Pololu* actuators, QObject* parent = 0);
		~AUVMotion();

		/**
		 * Set motion relative to current position.
		 * Set absolute to go to an absolute position.
		 * @param desiredHeading Desired heading in degrees (-180 to 180). By default relative to current heading.  In absolute mode it's relative to north (0 to 360).
		 * @param desiredDepth Desired depth in feet, by default relative to current depth.  In absolute mode, should only be a positive number, as it means feet below surface.
		 * @param forwardVelocity Forward velocity as a percentage (-1 to 1).  This is open-loop, so call holdPos() to actually stop.
		 * @param strafeVelocity Lateral velocity as a percentage (-1 to 1).  This is also open loop.
		 * @param absolute Sets the motion to absolute mode.  Parameters are then relative to their respective zero values.
		 */
		void setMotion(short int desiredHeading, float desiredDepth, float forwardVelocity, float strafeVelocity, bool absolute = false);
		/**
		 * Set only Heading
		 * See documentation for setMotion()
		 */
		void setHeading(short int desiredHeading, bool absolute = false);
		/**
		 * Set only Depth
		 * See documentation for setMotion()
		 */
		void setDepth(float desiredDepth, bool absolute = false);
		/**
		 * Set only Forward
		 * See documentation for setMotion()
		 */
		void setForwardVelocity(float forwardVelocity, bool absolute = false);
		/**
		 * Set only Strafe
		 * See documentation for setMotion()
		 */
		void setStrafeVelocity(float strafeVelocity, bool absolute = false);

		/**
		 * Holds current position.
		 * Call this if you want the vehicle to stop where it is.
		 * Sets desiredHeading and desiredDepth to current sensor values, and sets forwardVelocity and strafeVelocity to zero.
		 */
		void holdPos();

		void setParameter(QString dimension, QString param, double value);

	private:

		short int m_desiredHeading;
		float m_desiredDepth;
		float m_forwardVelocity;
		float m_strafeVelocity

		QTimer* PIDTimer;

		PIDController* headingPID;
		PIDController* depthPID;

};

#endif
