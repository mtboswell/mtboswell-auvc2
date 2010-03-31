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
		void on_fwdVelocitySpinBox_valueChanged(double value);
		void on_headingDGainSpinBox_valueChanged(double value);
		void on_headingIGainSpinBox_valueChanged(double value);
		void on_headingPGainSpinBox_valueChanged(double value);
		void on_depthDGainSpinBox_valueChanged(double value);
		void on_depthIGainSpinBox_valueChanged(double value);
		void on_depthPGainSpinBox_valueChanged(double value);
		void on_approachVelocitySpinBox_valueChanged(double value);
		void on_buoyDepthDGainSpinBox_valueChanged(double value);
		void on_buoyDepthIGainSpinBox_valueChanged(double value);
		void on_buoyDepthPGainSpinBox_valueChanged(double value);
		void on_buoyHeadingDGainSpinBox_valueChanged(double value);
		void on_buoyHeadingIGainSpinBox_valueChanged(double value);
		void on_buoyHeadingPGainSpinBox_valueChanged(double value);
		void on_pathHeadingPGainSpinBox_valueChanged(double value);
		void on_pathHeadingIGainSpinBox_valueChanged(double value);
		void on_pathHeadingDGainSpinBox_valueChanged(double value);
		void on_pathYPGainSpinBox_valueChanged(double value);
		void on_pathYIGainSpinBox_valueChanged(double value);
		void on_pathYDGainSpinBox_valueChanged(double value);


		// Vision
		void on_pathHueHighSpinBox_valueChanged(double value);
		void on_pathHueLowSpinBox_valueChanged(double value);
		void on_pathSaturationSpinBox_valueChanged(double value);
		void on_buoyHueHighSpinBox_valueChanged(double value);
		void on_buoyHueLowSpinBox_valueChanged(double value);
		void on_buoySaturationSpinBox_valueChanged(double value);
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

		QProcess* process;

};
