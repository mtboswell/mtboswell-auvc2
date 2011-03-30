
#ifndef CAMERA_H
#define CAMERA_H

#include "/usr/include/ueye.h"
#include <QImage>
#include <QThread>
#include <QTimer>
#include <QString>
#include <QByteArray>
#include <QPixmap>
#include <QDebug>
#include <QThread>

/**
 * Camera Module.
 */
class Camera : public QThread 
{
	Q_OBJECT;
	public:
		Camera(QObject* parent = 0);

	signals:
		void qPixmapReady(QPixmap);
		void qImageReady(QImage);

	protected slots:
		void captureImage();

		void run();
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
