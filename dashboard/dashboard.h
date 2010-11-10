#include "ui_dashboard.h"
#include "../src/configloader.h"
#include "../src/version.h"

#include <QMutexLocker>
#include <QGraphicsLineItem>
#include <QGraphicsView>
#include <QProcess>
#include <QVBoxLayout>
#include <QtGui>
#include <QTimer>
#include <QTime>

#include "../src/server/sidsocket.h"
#include "videosocket.h"
//#include "datalogger.h"
#include "videowidget.h"

#include "parametereditor/treemodel.h"
#include "parametereditor/doubleeditor.h"

#include "qwt_compass_rose.h"
#include "qwt_dial_needle.h"

static QHash<QString,QString> AUVState;


class Dashboard : public QMainWindow, private Ui::DashboardWindow
{
	Q_OBJECT

	public:
		Dashboard(QMainWindow *parent = 0);
		~Dashboard();

	signals:
		void sendSID(QString key, QString value);
		void setAddress(QString);
		void receivedParam(QString, QString);

	public slots:
		// Receieve UDP Data
		void handleAUVParam(QString id, QString value);
		void HandleVideoFrame(QImage* frame);
		void HandleBitmapFrame(QImage* frame);


	private slots:
		void startAction();
		void stopAction();
		void resetAction();
		void killAction();

		void logData(bool log);
		void logCmd(QString, QString);
		void recordVideo(bool record);

		//! \todo Implement turn off feature
		void turnOffAUVAction();

		void reconnectAction();
		void unbroadcastAction();
		void connectToAddress();
		void connectToLocalhost();

		void disableDashboard(QString,QString);
		void enableDashboard();
		void checkForDataTimeout();

		void saveParameters();
		void loadParameters();
		void loadParameter(QString param);
		void sendScript();

		// Keyboard Event Handler
		void keyPressEvent(QKeyEvent* event);

		// Gui Event Handlers

		void on_goButton_clicked();
		void on_stopButton_clicked();
		void on_whiteBalancePushButton_clicked();

		// Calibration
		void on_zeroDepthPushButton_clicked();
		void on_setActualDepthPushButton_clicked();

		// Brain state
		void on_stateComboBox_activated(int index); 

		// Tare state vectors
		void on_tareAccelPushButton_clicked();

		// RC
		void on_goRCButton_toggled(bool rc);
		void on_useInertialCheckBox_stateChanged(int state);
		void on_desiredDepthSlider_valueChanged(int value);
		void on_desiredStrafeSlider_valueChanged(int value);
		void on_desiredSpeedSlider_valueChanged(int value);
		void on_desiredHeadingDial_valueChanged(int value);
		void on_desiredHeadingSpinBox_editingFinished();
		void on_desiredDepthSpinBox_editingFinished();
		void on_desiredSpeedSpinBox_editingFinished();
		void on_desiredStrafeSpinBox_editingFinished();
		void on_setAllZeroButton_clicked();
		void on_runScriptPushButton_clicked();
		void on_actuateMechPushButton_clicked(); 
		
		// Video Streams
		void on_videoStreamComboBox_activated(int index);

	private:
		SIDSocket* m_DS;
		VideoSocket* videoSocket;
		VideoSocket* bitmapSocket;
		QGraphicsScene* headingScene;
		QGraphicsLineItem* headingLine;
		QLabel* rateLabel;
		QTime* timeSinceLastDataReceived;
		QTimer* dataTimeoutTimer;

		QPixmap videoPixmap; 
		QPixmap bwPixmap; 
		QImage videoFrame; 
		QImage bwFrame; 
		QStringList states;
		QStringList scripts;

		QProcess* process;
		int RC, desiredHeading, desiredDepth, desiredSpeed, desiredStrafe;
		int desiredVideoStream;
		
		VideoWidget* videoWidget;

		//DataLogger* logger;
		QString currentState, currentSubState;

		//ParameterEditor* paramEditor;
		TreeModel *paramModel;
		void setupParamEdit();

};
