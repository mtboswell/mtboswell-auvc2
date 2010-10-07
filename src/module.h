/**
 * module.h - standardized interface for AUVC modules.
 * Each module has several common components: inputs, outputs, parameters, and messaging.
 * Simulink-based modules have more, see simulinkmodule.h.
 */
#ifndef MODULE_H
#define MODULE_H

 #include "state.h"
 #include <QMap>

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
		Module(QMap<QString, QString>* configIn, AUV_State* stateIn, QObject* parent = 0);

	public slots:
		/**
		 * messageIn() - received messages from dataHub.
		 * Should be implemented to parse messages in the SID format.
		 * Default implementation ignores all messages.
		 * \param Id data Identifier
		 * \param Data data data
		 */
		virtual void messageIn(QString Id, QString Data){}
		/**
		 * setParameter() - set a module parameter.
		 * Default implementation ignores all parameters.
		 * \param name name of the parameter to set
		 * \param value value of parameter (numeric)
		 */
		virtual void setParameter(QString name, double value){}
		/**
		 * setParameter() - overloaded version of above to deal with non-double params.
		 * Default implementation ignores all parameters.
		 * \param name name of parameter to set
		 * \param value value to set parameter to
		 */
		virtual void setParameter(QString name, QString value){}

	signals:
		/**
		 * Message sender.
		 * Messages sent via this signal will be propogated and broadcasted as far as possible via dataHub.
		 * \param Id data Identifier
		 * \param Data data
		 */
		void messageOut(QString ID, QString Data);
		/**
		 * Parameter sender.
		 * I think this is a viable option for sending the parameters to the dashboard.
		 */
		void parameters(QMap<QString, double> params);

	private slots:
		/**
		 * step() - implement this function to do any work periodically.
		 * Gets called every 20ms (50Hz) by default.  Call stepTimer->setInterval([stepTimeInMs]) in your constructor to change.
		 */
		void step(){}

	private:
		/// timer for step function
		QTimer* stepTimer;
		/// state variable pointer
		AUV_State* state;
		/// config variable pointer
		QMap<QString, QString>* conf;

};
#endif
