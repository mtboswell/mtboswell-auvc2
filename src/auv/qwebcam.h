/***************************************************************************
 *   Copyright (C) 2008 by Stephane List                                   *
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

#ifndef QWEBCAM_H
#define QWEBCAM_H

#include <QObject>
#include <QImage>
#include <QTimer>
#include <QDebug>

#include <cv.h>
#include <highgui.h>

class QWebCam : public QObject
{
		Q_OBJECT
	public:	
		QWebCam(QWidget * parent=0);	
		~QWebCam();		
		static QImage Ipl2QImage(const IplImage *newImage);	
	signals:
		void newFrame(QImage);
	private slots:
		void captureLoop();			
	private:
		QImage  qImage_;
		QTimer timer_;
		IplImage* image_;
		CvCapture* capture_;
		int counter_;
};

#endif

