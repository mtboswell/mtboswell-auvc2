#include <iostream>
#include <cassert>
#include "power.h"
#include "ports.h"
using namespace std;

int main(int argc, char* argv[])
{
//	assert(argc > 1);
	Power* thrusterPower = new Power(POWERPORT);
	cout << "Power Class Test" << endl;
	
	if(!thrusterPower->turnOn()) return 0;
	
	char state = 'r';
	
	while(state != 'q')
	{
        state = getchar();
		if(state == '0') thrusterPower->turnOff();
		else if(state == '1') thrusterPower->turnOn();
		
		//cout << "Voltage: " << thrusterPower->getVoltage() << endl;
		//cout << "Current: " << thrusterPower->getCurrent() << endl;
	}
	
	thrusterPower->turnOff();
	
	delete thrusterPower;
	
	return 0;
}
