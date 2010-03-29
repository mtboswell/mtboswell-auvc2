#ifndef LOGGER
#define LOGGER
#include <QObject>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>
#include <QMap>
#include <QTimer>
#include <QDebug>

class DataLogger: public QObject 
{
	Q_OBJECT
	public:
		/**
		 * DataLogger object constructor
		 * 
		 * @param parent Parent object, which must have an event loop
		 * @param logFile Name of file to log data in
		 * @param delay Number of ms to wait for all data to be added.
		 * @param timeStep Number of ms between each log write
		 * @param delimiter String that delimits each data value in the log file
		 */
		DataLogger(QObject* parent, QString logFile, int delay = 3000, 
			int timeStep = 1000, QString delimiter = ", ")
			:QObject(parent)
			{

			qDebug() << "Using Logfile:" << logFile;
			file = new QFile(logFile, this);
			delim = delimiter;

			if (!file->open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
				qDebug() << "Cannot open log file";
				return;
			}

			out = new QTextStream(file);
			headerModified = true;
			enabled = false;
/*
			foreach(QString key, cols){
				data[key] = "";
			}

			//out << cols.join(delim);
			// This may be necessary if the column headers are in the wrong order:
			// out << ((QStringList)data.keys()).join(delim);
*/

			logTimer = new QTimer(this);
			logTimer->setInterval(timeStep);
			connect(logTimer, SIGNAL(timeout()), this, SLOT(writeToLogFile()));

			QTimer::singleShot(delay, logTimer, SLOT(start()));
			
		}

	public slots:
		void enable(bool enable){
			enabled = enable;
		}
		void logData(QString key, QString value){
			if(!data.contains(key)) headerModified = true;
			data[key] = value;
		}

	private slots:
		void writeHeader(){
			qDebug() << "Writing Log Header";
			*out << ((QStringList)data.keys()).join(delim) << endl;
			//qDebug() << ((QStringList)data.keys()).join(delim);
			headerModified = false;
		}
		void writeToLogFile(){
			if(!enabled) return;
			if(headerModified) writeHeader();
			//qDebug() << "Writing Log Data";
			*out << ((QStringList)data.values()).join(delim) << endl;
		}

	private:
		bool enabled;
		QMap<QString, QString> data;
		QTimer* logTimer;
		QFile* file;
		QString delim;
		QTextStream* out;
		bool headerModified;
		
};

#endif
