#include "uEyeDriver.h"
#include <QDebug>
#include <QString>
#include <QTime>

UEyeDriver::UEyeDriver(void)
{
	m_nSizeX = 500;
	m_nSizeY = 500;
	m_nBitsPerPixel = 32;
	m_hCam = (HIDS) 0;
	INT nRet = is_InitCamera(*m_hCam, NULL);
	if (nRet != IS_SUCCESS)
	{
		qDebug() << "Failed to initialize camera";
	}
	//image =  new QImage();
}

void UEyeDriver::getImage()
{
	is_AllocImageMem(m_hCam, m_nSizeX, m_nSizeY, &m_nBitsPerPixel, &m_pcImageMemory);
	is_SetImageMem (m_hCam, m_pcImageMemory, m_lMemoryId);
	
	// display initialization
	is_SetImageSize (m_hCam, m_nSizeX, m_nSizeY);
	is_SetDisplayMode (m_hCam, IS_SET_DM_DIB);
	if( is_FreezeVideo( m_hCam, IS_WAIT ) != IS_SUCCESS )
	{	
		qDebug() << "ERROR";
	}
}

void UEyeDriver::convertToQImage()
{
	isSaveImage(m_hCam, "image.bmp")
	//image.loadFromData("image.bmp", 4);
}
