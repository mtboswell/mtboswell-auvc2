// This application gathers data from the depth sensor and outputs the average at each tested depth to output.txt

#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <fstream>
#include "depthMaestro.h"
using namespace std;

int main(int argc, char *argv[]){
	std::cout << "Preparing to gather depth sensor data\n";
	float depths[11];
	int i = 0;
	int k = 0;
	ofstream output;
	output.open("output.txt");
	
	Maestro* maestro = new Maestro();
	for (i = 0; i < 11; i++) {
		std::cout << "Please move the AUV to a stable depth of " << i << " feet.\nPress return key when ready\n";
		std::getchar();
		qDebug() << "Gathering data";
		depths[i] = 0;
		for (k = 0; k < 2500; k++) {
			depths[i] += maestro->getDepth();
		}
		depths[i] = depths[i] / 2500.0;
		output << i << " feet :\t" << depths[i] << "\n"; 
		qDebug() << " Done!\n";
	}
	output.close();
	std::cout << "Test Completed\n";
	return 0;
}
