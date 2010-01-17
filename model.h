#include <QObject>
#include <QMutex>
#include <QMutexLocker>
#include <QThread>
#include <QTimer>
#include <QMutexLocker>
#include "auv/auvtypes.h"
#include "auv/camread.h"
#include "brain/brain.h"      /* Model's header file */
#include "brain/rtwtypes.h"                  /* MathWorks types */

static boolean_T OverrunFlag = 0;
		
		
class Model : public QThread 
{

	Q_OBJECT

	public:
		Model(QMutex* mutex);
		~Model();
		
	signals:
		void outputReady(ExternalOutputs_brain Output);
		
	public slots:
		void updateSensorsInput(AUVSensors values);

	private slots:
		// rt_OneStep should be called every 0.2 seconds (or 0.02 seconds, depending on the model)
		void rt_OneStep(void);
		
	protected:
		void run();
		
	private:
		QTimer *modelTimer;
		QMutex *modelMutex;
		int stepTime;
		struct camframe myframe;

};
