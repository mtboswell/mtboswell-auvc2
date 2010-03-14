/**
 * Model thread - interface between the Simulink model ("Brain") and everything else
 * Author: Micah Boswell
 * Created: 2009-06-08
 * Description: Creates a thread that runs the brain. Sets up a timer that calls the model
 * step function at the proper interval, and arranges for inputs and outputs.  There is also
 * a parameter update function.
 */

#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QTimer>
#include <QMutexLocker>
#include <QTime>
#include <QHash>
#include "../auv/auvtypes.h"
#include "../auv/camread.h"
#include "../brain/brain.h"      /* Model's header file */
#include "parameters.h"
#include "../brain/rtwtypes.h"                  /* MathWorks types */

		
class Model : public QThread 
{

	Q_OBJECT

	public:
		Model(QMutex* mutex);
		~Model();
		
	signals:
		// Emitted at the end of every brain processing cycle. duration measures
		// the time from the end of one cycle to the end of the next.
		// If duration > BRAIN_STEP_TIME, an overrun has occurred
		void outputReady(ExternalOutputs_brain Output, int duration);
		
	public slots:
		// Reads sensor data emitted from AUV
		void updateSensorsInput(AUVSensors values);
		// Deprecated, use setInput("State", ) instead
		void setState(int state);
		// Deprecated, use setRecordVideo() instead
		void startRecordVideo(){record_video = true;}
		void stopRecordVideo(){record_video = false;}
		// Enables/disables video recording.  This is handled here because 
		// the camera is accessed directly from the brain to save bandwidth
		void setRecordVideo(bool rec){record_video = rec;}
		// These simply set the model data values based on the name->pointer lookup hashes
		void setParam(QString name, double value);
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
		struct camframe myframe;
		bool record_video;
		QTime stepTimer;
		// signals overrun, currently everything crashes when an overrun happens
		boolean_T OverrunFlag;

};
