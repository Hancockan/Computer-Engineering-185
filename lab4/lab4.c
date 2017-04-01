/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */

double mag(double ax, double ay, double az);
int minutes(int t);
int seconds(int t);
int millis(int t);



int main(void) {
	int t;
	double  ax, ay, az; 	


	while (TRUE) {
		scanf("%d,%lf,%lf,%lf", &t, &ax, &ay, &az);	

/* CODE SECTION 0 */
		printf("Echoing output: %8.3lf, %7.4lf, %7.4lf, %7.4lf\n", (t/1000.0), ax, ay, az);

/* CODE SECTION 1 */
		printf("At %d ms, the acceleration's magnitude was: %lf\n", 
			t, mag(ax, ay, az));  
/* 	CODE SECTION 2 */
		printf("At %d minutes, %d seconds, and %d milliseconds it was: %lf\n", 
		minutes(t), seconds(t), millis(t), mag(ax,ay,az));

	}

return 0;
}

double mag(double ax, double ay, double az){
	
	double magnitude = sqrt((pow(ax, 2.0) + pow(ay, 2.0) + pow(az, 2.0)));
	
	return magnitude;
}

int minutes(int t){
	int minutes = (t/60000);
	return minutes;
}

int seconds(int t){
	int seconds = ((t % 60000)/1000);
	return seconds;
}

int millis(int t){
	int millis = ((t % 60000) % 1000);
	return millis;
}

/* Put your functions here */


