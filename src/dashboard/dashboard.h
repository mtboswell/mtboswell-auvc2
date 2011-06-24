#ifndef DASHBOARD_H_
#define DASHBOARD_H_

#include "ui_dashboard.h"
#include "../module/module.h"
#include "../src/misc/version.h"

#include <QMutexLocker>
#include <QGraphicsLineItem>
#include <QGraphicsView>
#include <QProcess>
#include <QVBoxLayout>
#include <QtGui>
#include <QTimer>
#include <QTime>

#include "videosocket.h"
#include "videowidget.h"

#include "parametereditor/doubleeditor.h"

#include "qwt_compass_rose.h"
#include "qwt_dial_needle.h"
#include "joystick/joystick.h"

static QHash<QString,QString> AUVState;


class Dashboard : public GuiModule, private Ui::DashboardWindow
{
	Q_OBJECT

	public:
		Dashboard(AUVC_State_Data* stateIn = 0);
		QStringList subscriptions(){
			QStringList sub;
			sub << ""; // subscribe to all
			return sub;
		}
		~Dashboard();
		bool isThread(){return false;}                

	signals:
		void setAddress(QString);
		void reconnect();
		//void receivedParam(QString, QString);
		void sync();

	public slots:
		// Receieve UDP Data
		void dataIn(VDatum datum);
		void HandleVideoFrame(QImage* frame);
		void HandleBitmapFrame(QImage* frame);


	private slots:
		void startAutonomousAction(bool sendToAUV = true);
		void startRCAction(bool sendToAUV = true);
		void stopAction(bool sendToAUV = true);
		void resetAction(bool sendToAUV = true);
		void killAction(bool sendToAUV = true);

		void logData(bool log);
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
        void updateJoystick();

		void saveParameters();
		void loadParameters();
		void loadParameter(QString param);
		void sendScript();

		// Keyboard Event Handler
		void keyPressEvent(QKeyEvent* event);

		// Gui Event Handlers

		void on_goAutonomousButton_clicked();
		void on_goRCButton_clicked();
		void on_stopButton_clicked();


		void on_syncButton_clicked();

		// Calibration
		void on_zeroDepthPushButton_clicked();
		void on_setActualDepthPushButton_clicked();

		// Brain state
		void on_stateComboBox_activated(int index); 

		// Tare state vectors
		void on_tareAccelPushButton_clicked();
                \
                void on_activate_joystick_clicked(bool);

		// RC
		//void on_goRCButton_toggled(bool rc);
		void on_desiredDepthSlider_valueChanged(double value);
		void on_desiredStrafeSlider_valueChanged(int value);
		void on_desiredSpeedSlider_valueChanged(int value);
		void on_desiredHeadingDial_valueChanged(double value);
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

		enum mode {STOPPED, AUTONOMOUS, RC, KILLED} currentMode;

		//VDataSocket* m_DS;
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
		int desiredHeading, desiredDepth, desiredSpeed, desiredStrafe;
		int desiredVideoStream;
		
		VideoWidget* videoWidget;

		//DataLogger* logger;
		QString currentState, currentSubState;

		//ParameterEditor* paramEditor;
		TreeModel *paramModel;
		void setupParamEdit();

                // Joystick
                QTimer *joystickTimer;
                joystick *js;

};

#endif
