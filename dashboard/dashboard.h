#include "ui_dashboard.h"
#include "auvtypes.h"
#include "brain.h"
#include "auv/camread.h"
#include <QMutex>
#include <QMutexLocker>

 class Dashboard : public QMainWindow, private Ui::DashboardWindow
 {
     Q_OBJECT

 public:
     Dashboard(QMainWindow *parent = 0, QMutex *mutex = 0);
     
 signals:
 	void startAUV();
 	void stopAUV();
 	void killAUV();
 	void resetAUV();
	void setDepth(double depth);
	void setState(int state);
     
 public slots:
     // Interface update slots
     void updateBrainView(ExternalOutputs_brain values);
     void updateSensorsView(AUVSensors values);
 	

 private slots:
     //void on_firstSpinBox_valueChanged(double value);
     //void on_secondSpinBox_valueChanged(double value);
     void startAction();
     void stopAction();
     void resetAction();
     void killAction();
     void recordVideo(bool record);
     
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
     
	// Calibration
	void on_zeroDepthPushButton_clicked();
	void on_setActualDepthPushButton_clicked();
     
    // Other
	void on_stateComboBox_activated(int index); 
     

 private:
	QMutex* modelMutex;  // Make it safe to access model data directly
 };
