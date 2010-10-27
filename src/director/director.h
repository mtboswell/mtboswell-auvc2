

class Director : public QObject 
{
	Q_OBJECT
	public:
		Director(AUV* state, QMutex* stateMutex, QObject * parent = 0);


	public slots:
		start();
		
	signals:
		message(QString message);
		setCmd(QString action);

	private:
		loadScript(QFile script);
		addTask(Task* seq, int position = -1);

		 // cmdTree
		QMap<QString, QMap<QString, Action*>> cmdTree;

};
