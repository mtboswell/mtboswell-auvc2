#include "cameratester.h"

CameraTester::CameraTester(QMainWindow* parent) : QMainWindow(parent)
{
	setupUi(this);

	camera = new QWebcam("/dev/video");
	connect(camera, SIGNAL(frameReady(QImage*)), this, SLOT(updateFrame(QImage*)));

	camThread = new QThread(this);
	camera->moveToThread(camThread);
}

void CameraTester::updateFrame(QImage* frame){
	label->setPixmap(QPixmap::fromImage(*frame).scaled(label->size(),Qt::KeepAspectRatio));
}

void CameraTester::selectDevice(){
	QString dev = QFileDialog::getOpenFileName(this,
	     tr("Open Camera"), "/dev/");
}

