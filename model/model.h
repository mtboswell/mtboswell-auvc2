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
		void outputReady(ExternalOutputs_brain Output, int duration);
		
	public slots:
		void updateSensorsInput(AUVSensors values);
		void setState(int state);
		void startRecordVideo(){record_video = true;}
		void stopRecordVideo(){record_video = false;}
		void setRecordVideo(bool rec){record_video = rec;}
		void setParam(QString name, double value);
		void setInput(QString name, double value);

	private slots:
		// rt_OneStep should be called every 1/f seconds, which is 0.2 seconds (or 0.02 seconds, depending on the model)
		void rt_OneStep(void);
		
	protected:
		void run();
		
	private:
		QTimer *modelTimer;
		QMutex *modelMutex;
		int stepTime;
		struct camframe myframe;
		bool record_video;
		QTime stepTimer;
		boolean_T OverrunFlag;

};
