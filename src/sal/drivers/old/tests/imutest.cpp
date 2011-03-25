#include "imu.h"
#include <iostream>
using namespace std;
int main()
{
	IMU* i = new IMU("/dev/ttyS0");
	imu_data d;
	for (int x = 0; x < 1000; x++)
	{
		usleep(100000);
		d = i->getData();
		cout<<"Heading: "<<d.yaw<<"  Pitch: "<<d.pitch<<"  Roll: "<<d.roll<<endl;
	}
	//sleep(10);
	delete i;
	return 0;
}
