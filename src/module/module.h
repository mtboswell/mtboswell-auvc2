/**
 * module.h - standardized interface for AUVC modules.
 * Each module has input signals and output signals. A module can subscribe to certain signals, which become its inputs, and may update certain signals, which become its outputs.
 * Simulink-based modules have more, see simulinkmodule.h.
 */
#ifndef MODULE_H
#define MODULE_H

 #include "../state/state.h"
 #include <QMap>
 #include <QThread>
 #include <QString>
 #include <QTimer>

class Module : public QThread
{
	Q_OBJECT
	public:
		/**
		 * Module() - Module constructor.
		 * Takes care of getting the config and state pointers.
		 * \param config pointer to the config data from configloader
		 * \param stateIn pointer to the shared state data
		 */
		Module(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QObject* parent = 0);
		/**
		 * Subscribe to data updates from the state database.
		 */
		QStringList subscriptions();

	public slots:
		// internally converted to dataIn(VDatum)
		void recvDatum(QString module, VDatum datum);

	signals:
		/**
		 * Data sender.
		 * Data sent via this signal will be propogated and broadcasted as far as possible via dataHub (state).
		 * \param Id data Identifier
		 * \param Data data
		 */
		void setData(VDatum datum);
		void setData(QString ID, QVariant value, QTime timestamp = QTime::currentTime, QVariant meta = QVariant());


	protected slots:
		/**
		 * dataIn() - receives data updates from dataHub.
		 * \param datum data data
		 */
		virtual void dataIn(VDatum datum)=0;
		/**
		 * step() - implement this function to do any work periodically.
		 * Gets called every 20ms (50Hz) by default.  Call stepTimer->setInterval([stepTimeInMs]) in your constructor to change.
		 */
		virtual void step(){}

	protected:
		/// config variable pointer
		QMap<QString, QString>* config;
		/// timer for step function
		QTimer* stepTimer;

};
#endif
