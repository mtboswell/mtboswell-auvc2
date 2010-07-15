#include "videosocket.h"
#include <QDebug>

#define MAX_FRAME_SIZE 100000

VideoSocket::VideoSocket(QString remoteAddr, unsigned short remotePort, unsigned short localPort, QObject* parent):QThread(parent) {
	socket = new QUdpSocket();
//	qDebug() << "Binding to port";
	socket->bind(localPort, QUdpSocket::ShareAddress);
        connect(socket, SIGNAL(readyRead()),
             this, SLOT(readPendingDatagrams()));

//	qDebug() << "Initializing reader";
//	reader = new QImageReader(socket, "jpeg");
	image = QImage(640, 480, QImage::Format_RGB32);

	static const char soi_data[] = {0xFF, 0xD8};
	static const char eoi_data[] = {0xFF, 0xD9};

	SOI = QByteArray::fromRawData(soi_data, sizeof(soi_data));
	EOI = QByteArray::fromRawData(eoi_data, sizeof(eoi_data));

	validFrame = false;

}

VideoSocket::~VideoSocket() {
	quit();
	wait();
}

void VideoSocket::run(){
/*	forever{
		socket->waitForReadyRead();
		qDebug() << "Reading image";
		image = reader->read();
		if(!image.isNull()) emit frameReady(&image);
		else qDebug() << "Failed to read image because:" << reader->errorString();
	}*/
	exec();
}

void VideoSocket::readPendingDatagrams()
{
        while (socket->hasPendingDatagrams()) {
                QByteArray datagram;
                datagram.resize(socket->pendingDatagramSize());
                QHostAddress sender;
                quint16 senderPort;

                socket->readDatagram(datagram.data(), datagram.size(),
                                 &sender, &senderPort);

                processDatagram(datagram, sender, senderPort);
        }
}


// called for every new incoming udp datagram
void VideoSocket::processDatagram(QByteArray datagram, QHostAddress fromAddr, quint16 fromPort){
	//qDebug() << "Processing Datagram:" << datagram;
	imageData.append(datagram);
	if(!validFrame && (imageData.startsWith(SOI) || datagram.contains(SOI))) {
		imageData = imageData.mid(imageData.indexOf(SOI));
		validFrame = true;
	}
	if(validFrame && (imageData.endsWith(EOI) || datagram.contains(EOI))){
		int soiPos = imageData.indexOf(SOI);
		int eoiPos = imageData.indexOf(EOI);
		if(soiPos > eoiPos) validFrame = false;
		if(soiPos == -1) validFrame = false;
		if(eoiPos == -1) validFrame = false;
		if(validFrame) {
			//qDebug() << "Found good frame";
			static QByteArray frame = imageData.mid(soiPos, eoiPos - soiPos + 1);
			image.loadFromData(frame, "jpeg");
			imageData = imageData.mid(eoiPos+1);
			validFrame = false;
			emit frameReady(&image);
		}else{
			qDebug() << "Invalid Image data";
		}
	} 
}

