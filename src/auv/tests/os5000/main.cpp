#include <QDebug>
#include "../../os5000.h"
int main()
{
	OS5000* o = new OS5000("/dev/ttyS1");
	double yaw;
	for (int x = 0; x < 1000; x++)
	{
		usleep(100000);
		yaw = o->heading();
		qDebug() << yaw;
	}
	delete o;
	return 0;
}
