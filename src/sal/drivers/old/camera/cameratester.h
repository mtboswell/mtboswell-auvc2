#ifndef CAMERATEST_H
#define CAMERATEST_H

#include <QMainWindow>
#include "ui_cameratester.h"
#include "qwebcam.h"
#include <QFileDialog>

class CameraTester : public QMainWindow, private Ui::MainWindow
{
	Q_OBJECT
	public:
		CameraTester(QMainWindow* parent = 0);

	private:
		QWebcam* camera;
		QThread* camThread;

		void selectDevice();

		void updateFrame(QImage*);


};

#endif
