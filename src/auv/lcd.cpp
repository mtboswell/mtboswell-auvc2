#include "lcd.h"
#include <QDebug>

LCD::LCD(const QString & serialPort): SerialDevice(serialPort, BAUD9600) {
	updateTimer = new QTimer(this);
	connect(updateTimer, SIGNAL(timeout()), this, SLOT(update()));
	updateTimer->start(300);
	int messageTimeout = 5;
}

void LCD::addField(QString name, int length){
	fieldValues[name] = QString(length, ' ');
}

void LCD::dispField(QString name, QString value){
	fieldValues[name] = value;
}

void LCD::dispMessage(QString msg){
	//qDebug() << "Displaying LCD message: " << msg;
	message = msg;
	scrollPos = 0;
	msgLen = message.length();
	//if(msgLen > 0) QTimer::singleShot(7000, this, SLOT(removeMessage()));
}

void LCD::removeMessage(){
	dispMessage("");
}

void LCD::update(){
	// disp line 1, scroll
	if(msgLen <= LCD_ROW_LENGTH)
		line1 = message.leftJustified(LCD_ROW_LENGTH);
	else{
		if(scrollPos >= msgLen) scrollPos = 0;
		line1 = message.mid(scrollPos,LCD_ROW_LENGTH).leftJustified(LCD_ROW_LENGTH);
		scrollPos++;
	}

	line2 = QStringList(fieldValues.values()).join(" | ").left(LCD_ROW_LENGTH);
	
	// display fields
	display();
}

void LCD::display(){
	QByteArray serialData;
	if(line1 != prevLine1 || line2 != prevLine2) {
		serialData.append(0xFE);
		serialData.append(0x01);
		serialData.append(line1);
		serialData.append(line2);
		sendData(serialData);
		//qDebug() << "Displaying: " << serialData;
	}

	prevLine1 = line1;
	prevLine2 = line2;
}
