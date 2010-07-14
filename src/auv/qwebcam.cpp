/***************************************************************************
 *   Copyright (C) 2008, 2009 by Stephane List                             *
 *   slist@lilotux.net                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

#include "qwebcam.h"

QWebCam::QWebCam(QObject * parent):QObject(parent),
	timer_(this),
	counter_(0)
{
	capture_ = cvCaptureFromCAM(-1);
	if (!capture_) {
		qDebug()<<"cannot get webcam...";
		return;
	}	
	cvGrabFrame(capture_);                    
	//recupere une image, pour voir les dimensions et redimensionner
	image_ = cvRetrieveFrame(capture_);
	qDebug() << "Image size : " << image_->width << "x" << image_->height;

	timer_.start(10);
	connect(&timer_,SIGNAL(timeout()), this,SLOT(captureLoop()));
}

QWebCam::~QWebCam()
{
	cvReleaseCapture( &capture_ );
	//	qDebug() << "nb frames :" << counter_;
}

QImage QWebCam::Ipl2QImage(const IplImage *newImage)
{
	QImage qtemp;
	if (newImage && cvGetSize(newImage).width > 0)
	{
		int x;
		int y;
		char* data = newImage->imageData;

		qtemp= QImage(newImage->width, newImage->height,QImage::Format_RGB32 );
		for( y = 0; y < newImage->height; y++, data +=newImage->widthStep )
			for( x = 0; x < newImage->width; x++)
			{
				uint *p = (uint*)qtemp.scanLine (y) + x;
				*p = qRgb(data[x * newImage->nChannels+2],
						data[x * newImage->nChannels+1],data[x * newImage->nChannels]);
			}
	}
	return qtemp;	
}

void QWebCam::captureLoop(){
	if ( !capture_ ) return;
	cvGrabFrame(capture_);
	image_ = cvRetrieveFrame(capture_);
	if (image_) {
		qImage_ = Ipl2QImage(image_);
		emit newFrame(qImage_);
		//emit newFrame(QPixmap::fromImage(qImage_));
	}
}

bool QWebCam::pause(){
	cvReleaseCapture( &capture_ );
	return true;
}
bool QWebCam::unpause(){
	capture_ = cvCaptureFromCAM(-1);
	if (!capture_) {
		qDebug()<<"cannot get webcam...";
		return false;
	}	
	cvGrabFrame(capture_);                    
	//recupere une image, pour voir les dimensions et redimensionner
	image_ = cvRetrieveFrame(capture_);
	qDebug() << "Image size : " << image_->width << "x" << image_->height;
	return true;
}
