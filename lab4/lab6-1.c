

#include <stdio.h>
#include <math.h>

#define TRUE 1

/

double mag(double ax, double ay, double az);




int main(void) {
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	


		printf("Echoing output: %lf, %7.4lf, %7.4lf, %7.4lf\n", (t/1000.0), ax, ay, az);

return 0;
}

double mag(double ax, double ay, double az){
	
	double magnitude = sqrt((pow(ax, 2.0) + pow(ay, 2.0) + pow(az, 2.0)));
	
	return magnitude;
}

