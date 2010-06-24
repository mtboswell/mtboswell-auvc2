#ifndef LCD_H 
#define LCD_H

#include "serialdevice.h"
#include <QString>
#include <QMap>
#include <QList>
#include <QStringList>

#define LCD_ROW_LENGTH 16
#define LCD_ROWS 2

/**
 * Displays AUV data on a SparkFun LCD module
 */
class LCD : public SerialDevice
{
	Q_OBJECT
	public:
		LCD(const QString & serialPort);
		
		void addField(QString name, int length);

	public slots:
		// displays a message on the top line of the LCD
		void dispMessage(QString message);
		// displays data on the bottom line of the LCD
		void dispField(QString name, QString value);

	private slots:
		void update();
		void removeMessage();

	private:
		// updates LCD text if it has changed
		void display();
		// scrolls top line to the left
		QTimer* updateTimer;
		QString message;
		QString line1, prevLine1;
		QString line2, prevLine2;
		QMap<QString, QString> fieldValues;
		int scrollPos;
		int msgLen;
		int timeout;
	
};

#endif
