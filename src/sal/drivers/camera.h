
#ifndef CAMERA_H
#define CAMERA_H

#include "ueye.h"
#include "vdatum.h"
#include <QImage>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QString>
#include <QByteArray>
#include <QPixmap>
#include <QDebug>
#include <QHostAddress>
#include <QUdpSocket>
#include <QImageWriter>
//#include "../../state/vdatum.h" out for testing


 /**
  * Struct containing all the variables for the camera.
  * A struct is created and filled in the SAL using the config files and passed
  * to the camera object in its constructor.
  **/
 struct CameraParams {
	int x, y, pixelclock, fps, identity; // identity: 0 for forward camera, 1 for downward camera
	QString serial; // camera serial number to connect to 
 };

/**
 * Camera Module.
 */
class Camera : public QObject
{
	Q_OBJECT
	public:
		Camera(CameraParams* params, QObject* parent = 0);

	signals:
		void qPixmapReady(QPixmap);
		void qImageReady(QImage);
		void dataReady(VDatum);

	public slots:
		void step();
		
	private:
		
		void init();
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
		QUdpSocket* videoSocket;
		QImageWriter* videoOut;
		QTimer* timer;
		


};

#endif
