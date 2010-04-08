#include "ui_dashboard.h"
#include "../config.h"
#include "DashSocket.h"
#include "VideoSocket.h"
#include <QMutexLocker>
#include <QGraphicsLineItem>
#include <QGraphicsView>
#include <QProcess>
#include <QVBoxLayout>
#include <QtGui>

static QHash<QString,QString> AUVState;

class Dashboard : public QMainWindow, private Ui::DashboardWindow
{
	Q_OBJECT

	public:
		Dashboard(QMainWindow *parent = 0);

	signals:
		void sendParam(QString key, QString value);
		void setAddress(QString);

	public slots:
		// Receieve UDP Data
		void HandleAUVParam(QString type, QString name, QString value);
		void HandleVideoFrame(QImage* frame);
		void HandleBitmapFrame(QImage* frame);


	private slots:
		void startAction();
		void stopAction();
		void resetAction();
		void killAction();
		void logData(bool log);
		void recordVideo(bool record);
		void reconnectAction();
		void turnOffAUVAction();
		void broadcastAction();
		void connectToAddress();

		// Gui Event Handlers

		// controller gains
		void on_fwdVelocitySpinBox_editingFinished();
		void on_headingDGainSpinBox_editingFinished();
		void on_headingIGainSpinBox_editingFinished();
		void on_headingPGainSpinBox_editingFinished();
		void on_depthDGainSpinBox_editingFinished();
		void on_depthIGainSpinBox_editingFinished();
		void on_depthPGainSpinBox_editingFinished();
		void on_approachVelocitySpinBox_editingFinished();
		void on_buoyDepthDGainSpinBox_editingFinished();
		void on_buoyDepthIGainSpinBox_editingFinished();
		void on_buoyDepthPGainSpinBox_editingFinished();
		void on_buoyHeadingDGainSpinBox_editingFinished();
		void on_buoyHeadingIGainSpinBox_editingFinished();
		void on_buoyHeadingPGainSpinBox_editingFinished();
/*
		void on_pathHeadingPGainSpinBox_editingFinished();
		void on_pathHeadingIGainSpinBox_editingFinished();
		void on_pathHeadingDGainSpinBox_editingFinished();
		void on_pathYPGainSpinBox_editingFinished();
		void on_pathYIGainSpinBox_editingFinished();
		void on_pathYDGainSpinBox_editingFinished();
*/


		// Vision
		void on_pathHueHighSpinBox_editingFinished();
		void on_pathHueLowSpinBox_editingFinished();
		void on_pathSaturationSpinBox_editingFinished();
		void on_buoyHueHighSpinBox_editingFinished();
		void on_buoyHueLowSpinBox_editingFinished();
		void on_buoySaturationSpinBox_editingFinished();
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
		void on_desiredHeadingSpinBox_valueChanged(int value);
		void on_setAllZeroButton_clicked();
		void on_runScriptPushButton_clicked();


	private:
		DashSocket m_DS;
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

};
