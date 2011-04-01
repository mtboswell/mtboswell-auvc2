#include "adc.h"
#include "ports.h"
#include "calibration.h"
#include <iostream>
using namespace std;

int main()
{
	ADC* adc = new ADC(ARDUINOPORT, 9600);
	int depth = 0;
	for (int x=0; x<100; x++)
	{
		depth = adc->getValue("DEPTH");	
		cout<<(float) ((float)(depth-DEPTHZERO))/DEPTHSCALE<<'\t'<< "ft" 
			<< "  Sensor reading: " << depth << endl;
//		cout<<(float) adc->getValue("GO")<<'\t'<< "GO" << endl;

/*			adc->getValue("B")<<'\t'<<
			adc->getValue("C")<<'\t'<<
			adc->getValue("D")<<'\t'<<
			adc->getValue("E")<<'\t'<<
			adc->getValue("F")<<'\t'<<
			adc->getValue("G")<<'\t'<<
			adc->getValue("H")<<'\t'<<
			adc->getValue("I")<< endl;
*/
		usleep(50000);
	}
	delete adc;
	return 0;
}
