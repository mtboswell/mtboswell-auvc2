#ifndef __MODEL_H
#define __MODEL_H

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QTimer>
#include <QMutexLocker>
#include <QTime>
#include <QHash>
#include <QImage>
#include <QColor>
#include "../auv/auvtypes.h"
//#include "../auv/camread.h"
#include "../brain/brain.h"      /* Model's header file */
#include "parameters.h"
#include "../brain/rtwtypes.h"                  /* MathWorks types */

/**
 * Interface between the Simulink model ("Brain") and everything else.
 * @author: Micah Boswell
 * @date: 2009-06-08
 * Creates a thread that runs the brain. Sets up a timer that calls the model
 * step function at the proper interval, and arranges for inputs and outputs.  There is also
 * a parameter update function.
 */
		
class Model : public QThread 
{

	Q_OBJECT

	public:
		/**
		 * Constructor
		 * @param mutex QMutex for protecting access to model data (parameters and such).
		 */
		Model(QMutex* mutex);
		~Model();
		
	signals:
		/** 
		 * Emitted at the end of every brain processing cycle. 
		 * @param duration measures
		 * the time from the end of one cycle to the end of the next.
		 * If duration > BRAIN_STEP_TIME, an overrun has occurred
		 */
		void outputReady(ExternalOutputs_brain Output, int duration);
		void status(QString);
		void error(QString);
		
	public slots:
		// Reads sensor data emitted from AUV
		void updateSensorsInput(AUVSensors values);

		void updateVideoFrame(QImage frame);

		// Deprecated, use setInput("State", ) instead
		void setState(int state);

		// Deprecated, use setRecordVideo() instead
		void startRecordVideo(){record_video = true;}
		void stopRecordVideo(){record_video = false;}
		
		// deprecated, video is now recorded in server thread
		// Enables/disables video recording.  This is handled here because 
		// the camera is accessed directly from the brain to save bandwidth
		void setRecordVideo(bool rec){record_video = rec;}

		/**
		 * Set Model Parameters.
		 * These simply set the model data values based on the name->pointer lookup hashes
		 * If the parameter doesn't exist, the call does nothing.
		 * @param name name of the parameter to set. 
		 * @param value Value to set the parameter to.
		 */
		void setParam(QString name, double value);
		/**
		 * Set Model Inputs.
		 * These simply set the model data values based on the name->pointer lookup hashes
		 * If the input doesn't exist, the call does nothing.
		 * @param name name of the input to set. 
		 * @param value Value to set the input to.
		 */
		void setInput(QString name, double value);

	private slots:
		// rt_OneStep should be called every 1/f seconds, which is BRAIN_STEP_TIME seconds 
		void rt_OneStep(void);
		
	protected:
		// starts the thread, do not call directly, gets called from start()
		void run();
		
	private:
		QTimer *modelTimer;
		QMutex *modelMutex;
		// stepTime is deprecated, use BRAIN_STEP_TIME
		int stepTime;
		//struct camframe myframe;
		bool record_video;
		QTime stepTimer;
		// signals overrun, currently everything crashes when an overrun happens
		boolean_T OverrunFlag;

};

#endif
