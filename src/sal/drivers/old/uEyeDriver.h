#ifndef UEYE_H
#define UEYE_H
#define HIDS unsigned long
//#include "sensor.h"
#include "/usr/include/ueye.h"
//#include <QImage>

class UEyeDriver
{
	public:
		UEyeDriver(void);
		void getImage();
		void convertToQImage();
	private:
		HIDS m_hCam;
		int m_nRenderMode, m_lMemoryID, m_nSizeX, M_nSizeY, m_nBitsPerPixel, m_pcImageMemory;
		//QImage image;
};
#endif

