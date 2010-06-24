#include "ui_dashboard.h"
#include "../src/configloader.h"
#include "../src/version.h"

#include <QMutexLocker>
#include <QGraphicsLineItem>
#include <QGraphicsView>
#include <QProcess>
#include <QVBoxLayout>
#include <QtGui>

#include "../src/server/sidsocket.h"
#include "videosocket.h"
#include "datalogger.h"
#include "videowidget.h"

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
		void broadcastAction();
		void connectToAddress();
		void connectToLocalhost();

		void disableDashboard(QString,QString);
		void enableDashboard();

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

		// RC
		void on_controlGroupBox_toggled(bool rc);
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
		
		// Camera
		void on_camPosXSpinBox_valueChanged(double value);
		void on_camPosYSpinBox_valueChanged(double value);

		// Video Streams
		void on_videoStreamComboBox_activated(int index);

/*
#define GEN_PARAM(guiParam,brainParam) \
void on_##guiParam##_editingFinished();
#include "parameters.def"
*/

		// controller gains
		void on_fwdVelocitySpinBox_editingFinished();
		void on_headingDGainSpinBox_editingFinished();
		void on_headingIGainSpinBox_editingFinished();
		void on_headingPGainSpinBox_editingFinished();
		void on_depthDGainSpinBox_editingFinished();
		void on_depthIGainSpinBox_editingFinished();
		void on_depthPGainSpinBox_editingFinished();
		void on_approachVelocitySpinBox_editingFinished();
		void on_fwdYGainD_editingFinished();
		void on_fwdYGainI_editingFinished();
		void on_fwdYGainP_editingFinished();
		void on_fwdXGainD_editingFinished();
		void on_fwdXGainI_editingFinished();
		void on_fwdXGainP_editingFinished();
		void on_downYGainD_editingFinished();
		void on_downYGainI_editingFinished();
		void on_downYGainP_editingFinished();
		void on_downXGainD_editingFinished();
		void on_downXGainI_editingFinished();
		void on_downXGainP_editingFinished();

		// Vision
		void on_pathHueHighSpinBox_editingFinished();
		void on_pathHueLowSpinBox_editingFinished();
		void on_pathSaturationSpinBox_editingFinished();
		void on_pathDepthSpinBox_editingFinished();
		void on_buoyMinEccentSpinBox_editingFinished();
		void on_buoyMaxEccentSpinBox_editingFinished();
		void on_buoyMinExtentSpinBox_editingFinished();
		void on_buoyMaxExtentSpinBox_editingFinished();
		void on_buoy1HueSpinBox_editingFinished();
		void on_buoy1SaturationSpinBox_editingFinished();
		void on_buoy1ValueSpinBox_editingFinished();
		void on_buoy2HueSpinBox_editingFinished();
		void on_buoy2SaturationSpinBox_editingFinished();
		void on_buoy2ValueSpinBox_editingFinished();

	private:
		SIDSocket* m_DS;
		VideoSocket* videoSocket;
		VideoSocket* bitmapSocket;
		QGraphicsScene* headingScene;
		QGraphicsLineItem* headingLine;
		QLabel* rateLabel;

		QPixmap videoPixmap; 
		QPixmap bwPixmap; 
		QImage videoFrame; 
		QImage bwFrame; 
		QStringList states;
		QStringList scripts;

		QProcess* process;
		int RC, desiredHeading, desiredDepth, desiredSpeed, desiredStrafe;
		double desiredCameraX, desiredCameraY;
		
		VideoWidget* videoWidget;

		DataLogger* logger;

};
