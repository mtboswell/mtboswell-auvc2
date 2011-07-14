#include <iostream>
#include <cassert>
#include "ports.h"
#include "pololu.h"
using namespace std;

int main(int argc, char* argv[])
{
//	assert(argc > 1);
	Pololu* p = new Pololu(POLOLUPORT);
	cout << "Pololu Class Test" << endl;
	int sn, val;
	char mode;
	//sn = 5;
	while(cin)
	{
		cin >> mode;
		cin>>sn;
		//sn = 1;
		cin>>val;
		if(val == 0)
		    break;
		if(mode == 's')
			if(!p->setPosAbs(sn,val)) cout << "Fail" << endl;
		if(mode == 'm')
			if(!p->setTrexSpeed(sn, val)) cout << "Fail" << endl;
		if(val == 0)
		    break;
	}
	
	/*if (p->setPosAbs(1, 4000))
	{
		cout<<"Data sent."<<endl;
	}
	else
	{
		cout<<"Send failed."<<endl;
	}*/
	delete p;
	
	return 0;
}
