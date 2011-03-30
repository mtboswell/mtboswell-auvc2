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
 #include <QMainWindow>

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
		 * Subscribe to data updates from the state database by returning
		 * a QStringList with the data IDs you want from here.
		 * Default implementation has none
		 */
		virtual QStringList subscriptions(){return QStringList();}

		/// Return true from this function if you want a module to run in its own thread.
		virtual bool isThread(){return true;}


	protected slots:
		/**
		 * dataIn() - receives data updates from dataHub.
		 * \param datum data data
		 */
		virtual void dataIn(VDatum datum){}


		/**
		 * Data sender.
		 * Data sent via this method will be propogated and broadcasted as far as possible via dataHub (state).
		 * \param Id data Identifier
		 * \param Data data
		 */
		void setData(QString ID, QVariant value, QTime timestamp = QTime::currentTime(), QVariant meta = QVariant());
		void setData(VDatum);
		void setData(QList<VDatum>);

		/**
		 * init() - implement this function to do any work when the application starts.
		 */
		virtual void init(){}

		/**
		 * step() - implement this function to do any work periodically.
		 * Call stepTimer->start([stepTimeInMs]) in your constructor to activate.
		 */
		virtual void step(){}

	protected:

		/**
		 * Read values from state data.
		 */
		QVariant value(QString ID);
		bool boolValue(QString ID);
		int intValue(QString ID);
		double doubleValue(QString ID);
		QString stringValue(QString ID);
		bool available(QString ID);
		QTime timestamp(QString ID);

		/// config variable pointer
		QMap<QString, QString>* config;
		/// timer for step function
		QTimer* stepTimer;



	/* Ignore everything below this line ******************************************************************/
	private slots:
		void run();
	private:
		AUVC_State_Data* state;
	public slots:
		/// internally converted to dataIn(VDatum)
		void recvDatum(QString module, VDatum datum);
	signals:
		/// internally converted from setData(QString...
		void sendData(VDatum datum);
};

/// GuiModule is copypasted from Module with the following differences:
/// Inherits from QMainWindow instead of QThread
/// isThread() is not virtual and returns false
/// state is protected instead of private
class GuiModule : public QMainWindow
{
	Q_OBJECT
	public:
		/**
		 * Module() - Module constructor.
		 * Takes care of getting the config and state pointers.
		 * \param config pointer to the config data from configloader
		 * \param stateIn pointer to the shared state data
		 */
		GuiModule(QMap<QString, QString>* configIn, AUVC_State_Data* stateIn, QWidget* parent = 0);
		/**
		 * Subscribe to data updates from the state database by returning
		 * a QStringList with the data IDs you want from here.
		 * Default implementation has none
		 */
		virtual QStringList subscriptions(){return QStringList();}

		/// Return true from this function if you want a module to run in its own thread.
		bool isThread(){return false;}

	public slots:
		/// internally converted to dataIn(VDatum)
		void recvDatum(QString module, VDatum datum);

	signals:
		/// internally converted from setData(QString...
		void sendData(VDatum datum);

	protected slots:
		/**
		 * dataIn() - receives data updates from dataHub.
		 * \param datum data data
		 */
		virtual void dataIn(VDatum datum){}
		/**
		 * Data sender.
		 * Data sent via this method will be propogated and broadcasted as far as possible via dataHub (state).
		 * \param Id data Identifier
		 * \param Data data
		 */
		void setData(QString ID, QVariant value, QTime timestamp = QTime::currentTime(), QVariant meta = QVariant());
		void setData(VDatum);
		void setData(QList<VDatum>);
		/**
		 * step() - implement this function to do any work periodically.
		 * Call stepTimer->start([stepTimeInMs]) in your constructor to activate.
		 */
		virtual void step(){}

	protected:

		/**
		 * Read values from state data.
		 */
		QVariant value(QString ID);
		bool boolValue(QString ID);
		int intValue(QString ID);
		double doubleValue(QString ID);
		QString stringValue(QString ID);

		/// config variable pointer
		QMap<QString, QString>* config;
		/// timer for step function
		QTimer* stepTimer;

		AUVC_State_Data* state;
};

#endif
