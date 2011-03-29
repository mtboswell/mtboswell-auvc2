
#ifndef CAMERA_H
#define CAMERA_H

#include "/usr/include/ueye.h"
#include <QImage>
#include <QThread>
#include <QTimer>
#include <QString>
#include <QByteArray>
#include <QPixmap>
#include "module.h"
#include <QDebug>

/**
 * Camera Module.
 */
class Camera : public Module 
{
	Q_OBJECT;
	public:
		Camera(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
		
	public slots:
		
		//These fucntions are currently not redefined from module.h
		//ignores all messages and data updates from StateData
		
		// void messageIn(QString message);
		// void messageIn(VDatum message);
		// void newData(QString ID, QVariant value);
		void captureImage();

	signals:
	
		void messageOut(QString ID, QVariant Data);
		void messageOut(VDatum message);
		void parameters(QMap<QString, double> params);

	private slots:
		
		void step();

	private:
		
		HIDS m_hCam;
		int m_nRenderMode, m_lMemoryID, m_nSizeX, m_nSizeY, m_nBitsPerPixel;
		int fps;
		char* m_pcImageMemory;
		char* byteStorage;
		// localx etc. for testing purposes only (see is_SetAOI())
		INT localx, localy, localx2, localy2;
		QImage* qimage;
		QPixmap qpixmap;
		QByteArray imageArray;
		


};

#endif
