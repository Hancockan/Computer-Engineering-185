/* Lab 5 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1


/* Put your lab 4 functions prototypes here, as well as the prototype for lab 5 */

double mag(double ax, double ay, double az);
int Orientation(double ax, double ay, double az);
int close_to(double tolerance, double point, double value);




const double tolerance = 0.1;
int i = 0;

int main(void) {
	int t, b1, b2, b3, b4, b5, s;
	double ax, ay, az; 	
	int k = 0;


	while (TRUE) {
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &ax, &ay, &az, &b1, &b2, &b3, &b4, &b5, &s );	
		k = i;

		//printf("Echoing output: %d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", t, ax, ay, az, b1, b2, b3, b4, b5, s);

/* 
		printf("At %d ms, the acceleration's magnitude was: %f\n", t, mag(ax, ay, az));  
		
		You would be wise (mainly save time) if you copy your code to calculate the magnitude from last week
		 (lab 4) to this section.  You will also need to copy your prototypes and functions to the appropriate sections
		 in this program.   
*/

		
	//double magnitude = mag(ax, ay, az);
	if(mag(ax, ay, az) > 1.3){
		continue;
	}
	
	if(Orientation(ax, ay, az) != k){
		
		if(Orientation(ax, ay, az) == 1) printf("TOP\n");
		if(Orientation(ax, ay, az) == 2) printf("BOT\n");
		if(Orientation(ax, ay, az) == 3) printf("RIGHT\n");
		if(Orientation(ax, ay, az) == 4) printf("LEFT\n");
		if(Orientation(ax, ay, az) == 5) printf("FRONT\n");
		if(Orientation(ax, ay, az) == 6) printf("BACK\n");
	} 
	
	
	//printf("magnitude: %lf\n", magnitude);
	
	}

    return 0;
}

int close_to(double tolerance, double point, double value){
	
	if((value < (point + tolerance)) && (value > (point - tolerance))){
		
		return 1;
		
	} else {
		
		return 0;
		
	}
	
}

double mag(double ax, double ay, double az){
	
	double magnitude = sqrt((pow(ax, 2.0) + pow(ay, 2.0) + pow(az, 2.0)));
	
	return magnitude;

}

int Orientation(double ax, double ay, double az){
	
	double val1 = 0.0;
	double val2 = 1.0;
	double val3 = -1.0;
	if(close_to(tolerance, ax, val1) && close_to(tolerance, az, val2)){
		//printf("TOP\n");
		i = 1;
	}
	if(close_to(tolerance, ax, val1) && close_to(tolerance, az, val3)){
		//printf("BOT\n");
		i = 2;
	}
	if(close_to(tolerance, ax, val3) && close_to(tolerance, az, val1)){
		//printf("RIGHT\n");
		i = 3;
	}
	if(close_to(tolerance, ax, val2) && close_to(tolerance, az, val1)){
		//printf("LEFT\n");
		i = 4;
	}
	if(close_to(tolerance, ax, val1) && close_to(tolerance, ay, val2)){
		//printf("FRONT\n");
		i = 5;
	}
	if(close_to(tolerance, ax, val1) && close_to(tolerance, ay, val3)){
		//printf("BACK\n");
		i = 6;
	}
	return i;
	
}




