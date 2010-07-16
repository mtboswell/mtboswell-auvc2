#include <iostream>
#include <math.h>

using namespace std;

#define PI 3.14159265

int main (int argc, char * const argv[]) {

	//variables
	double dist_a[360];
	double dist_b[360];
	double dist_c[360];
	double diff_ba[360];
	double diff_bc[360];
	double diff_ca[360];
	double angle[360];
	double range[360];
	double distance = 10, difference = 10, angle_out = 0;
	
	//triangular array
	double aX = 1;
	double aY = 0;
	double bX = -1;
	double bY = 0;
	double cX = 0;
	double cY = sqrt(3);
    
	//inputs check
	double radius = 10.0;
	int bearing = 0;
	if(argc >= 2) radius = atof(argv[1]);
	if(argc >= 3) bearing = atoi(argv[2]);
	while(bearing>360) bearing -= 360;
	while(bearing<0) bearing += 360;
	
	double x=0,y=0;
	
	//calculat location of given source
	x = radius*cos(double(bearing*PI/180));
	y = radius*sin(double(bearing*PI/180));
	
	//generate distances
	dist_a[bearing] = sqrt((x-aX)*(x-aX) + (y-aY)*(y-aY));
	dist_b[bearing] = sqrt((x-bX)*(x-bX) + (y-bY)*(y-bY));
	dist_c[bearing] = sqrt((x-cX)*(x-cX) + (y-cY)*(y-cY));
	
	//calculate TDOA
	diff_ba[bearing] = dist_b[bearing] - dist_a[bearing];
	diff_bc[bearing] = dist_b[bearing] - dist_c[bearing];
	diff_ca[bearing] = dist_c[bearing] - dist_a[bearing];
	
	//calculate angle based on TDOA
	angle[bearing] = acos(diff_ba[bearing]/2)*180/PI;
	if (diff_bc[bearing] < diff_ca[bearing]) angle[bearing] = 360 - angle[bearing];
	
	//guess range
	range[bearing] = acos(diff_bc[bearing]/2)*180/PI + 60;
	if(diff_bc[bearing]>1 && diff_ca[bearing]<1 && diff_ca[bearing]>-1) range[bearing] = 120 - range[bearing];
	if(diff_bc[bearing]<1 && diff_ca[bearing]>1) range[bearing] = 480 - range[bearing];
	difference = angle[bearing]-range[bearing];
	angle_out = angle[bearing];
	
	//calculate range based on error difference
	double epic = 5.729 * cos( (angle[bearing]-30)*PI/180 );
	distance = epic*10/difference;
	//look up distance error
	/*
	 for(distance=10; distance<1000; distance++){
		x = distance*cos(double(angle[bearing]*PI/180));
		y = distance*sin(double(angle[bearing]*PI/180));
		dist_a[bearing] = sqrt((x-aX)*(x-aX) + (y-aY)*(y-aY));
		dist_b[bearing] = sqrt((x-bX)*(x-bX) + (y-bY)*(y-bY));
		dist_c[bearing] = sqrt((x-cX)*(x-cX) + (y-cY)*(y-cY));
		diff_ba[bearing] = dist_b[bearing] - dist_a[bearing];
		diff_bc[bearing] = dist_b[bearing] - dist_c[bearing];
		diff_ca[bearing] = dist_c[bearing] - dist_a[bearing];
		angle[bearing] = acos(diff_ba[bearing]/2)*180/PI;
		if (diff_bc[bearing] < diff_ca[bearing]) angle[bearing] = 360 - angle[bearing];
		range[bearing] = acos(diff_bc[bearing]/2)*180/PI + 60;
		if(diff_bc[bearing]>1 && diff_ca[bearing]<1 && diff_ca[bearing]>-1) range[bearing] = 120 - range[bearing];
		if(diff_bc[bearing]<1 && diff_ca[bearing]>1) range[bearing] = 480 - range[bearing];
		if(difference>(angle[bearing]-range[bearing])) break;
	}
	 */
		
	cout << "bearing: " << bearing << " radius: " << radius << " angle: " << angle_out << " range: " << distance << endl;
	
	if(argc >=4){
		if(strcmp(argv[3],"r")==0){
			for(radius=10; radius<1000; radius++){
				x = radius*cos(double(bearing*PI/180));
				y = radius*sin(double(bearing*PI/180));
				dist_a[bearing] = sqrt((x-aX)*(x-aX) + (y-aY)*(y-aY));
				dist_b[bearing] = sqrt((x-bX)*(x-bX) + (y-bY)*(y-bY));
				dist_c[bearing] = sqrt((x-cX)*(x-cX) + (y-cY)*(y-cY));
				diff_ba[bearing] = dist_b[bearing] - dist_a[bearing];
				diff_bc[bearing] = dist_b[bearing] - dist_c[bearing];
				diff_ca[bearing] = dist_c[bearing] - dist_a[bearing];
				angle[bearing] = acos(diff_ba[bearing]/2)*180/PI;
				if (diff_bc[bearing] < diff_ca[bearing]) angle[bearing] = 360 - angle[bearing];
				range[bearing] = acos(diff_bc[bearing]/2)*180/PI + 60;
				if(diff_bc[bearing]>1 && diff_ca[bearing]<1 && diff_ca[bearing]>-1) range[bearing] = 120 - range[bearing];
				if(diff_bc[bearing]<1 && diff_ca[bearing]>1) range[bearing] = 480 - range[bearing];
				cout << radius << " " << bearing << " " << angle[bearing] << " " << range[bearing] << " " << angle[bearing]-range[bearing] << endl;
			}
		}
		
		if(strcmp(argv[3],"p")==0){
			for(bearing = 0; bearing < 360; bearing++){
				x = radius*cos(double(bearing*PI/180));
				y = radius*sin(double(bearing*PI/180));
				dist_a[bearing] = sqrt((x-aX)*(x-aX) + (y-aY)*(y-aY));
				dist_b[bearing] = sqrt((x-bX)*(x-bX) + (y-bY)*(y-bY));
				dist_c[bearing] = sqrt((x-cX)*(x-cX) + (y-cY)*(y-cY));
				diff_ba[bearing] = dist_b[bearing] - dist_a[bearing];
				diff_bc[bearing] = dist_b[bearing] - dist_c[bearing];
				diff_ca[bearing] = dist_c[bearing] - dist_a[bearing];
				angle[bearing] = acos(diff_ba[bearing]/2)*180/PI;
				if (diff_bc[bearing] < diff_ca[bearing]) angle[bearing] = 360 - angle[bearing];
				range[bearing] = acos(diff_bc[bearing]/2)*180/PI + 60;
				if(diff_bc[bearing]>1 && diff_ca[bearing]<1 && diff_ca[bearing]>-1) range[bearing] = 120 - range[bearing];
				if(diff_bc[bearing]<1 && diff_ca[bearing]>1) range[bearing] = 480 - range[bearing];
				//cout << bearing << " " << dist_a[bearing] << " " << dist_b[bearing] << " " << dist_c[bearing] << endl;
				cout << bearing << " " << diff_ba[bearing] << " " << diff_bc[bearing] << " " << diff_ca[bearing]  << " " << angle[bearing] << " " << range[bearing] << " " << angle[bearing]-range[bearing] << endl;
			}
		}
	}

	if(argc >= 4){
		FILE *pipe = popen("gnuplot -persist","w");
		fprintf(pipe, "load 'plot.txt'\n");
	}
	
    return 0;
}
