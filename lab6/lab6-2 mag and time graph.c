#include <stdio.h>
#include <math.h>

#define TRUE 1
#define Gravity 9.8

double mag(double ax, double ay, double az);
int close_to(double TOL, double point, double value);
void printStuff();

int k = 0;
double TOL = 0.2;

int main(void) {
	int t, b1, b2, b3, b4, b5, s, i = 0;
	double ax, ay, az, secondsFalling, distanceFallen, time, position; 	
	double velocity, velocity1, velocity2;
	int percentageDiff = 0;

	printStuff();
	
	while (TRUE) {
		scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);	
		
		k++;
		
		if((k % 10) == 0){
			printf(".");
			fflush(stdout);
		}
		
		if(close_to(TOL, mag(ax, ay, az), 0.1)){
			while(close_to(TOL, mag(ax, ay, az), 0.1)){
				scanf("%d, %lf, %lf, %lf", &t, &ax, &ay, &az);
				time = (double)i/500.0;
				if(i == 0){
					velocity = 0.0;
					position = 0.0;
					fflush(stdout);
					printf("\nI'm falling");
					fflush(stdout);
					i++;
				}
				i++;
				if((i % 10) == 0){
					fflush(stdout);
					printf("!");
					fflush(stdout);
				}
				velocity = velocity + (Gravity) * (1-mag(ax,ay,az)) * (((double)i/500.0) - time);
				position = position + (velocity) * (((double)i/500.0) - time);
				
			}
			
			secondsFalling = ((double) i / 500.0);
			distanceFallen = 0.0 + (0.0 * 0.0) + (1.0/2.0)*(9.8)*((secondsFalling) * (secondsFalling));
			printf("\nCompensating for air resistance, the fall was %lf meters.\n", position);
			percentageDiff = 100 - ((position * 100) / distanceFallen);
			printf("This is %d percent less than computed before.\n", percentageDiff);
			break;
		}
		
	}
	
	return 0;
	
}



double mag(double ax, double ay, double az){
	
	double magnitude = sqrt((pow(ax, 2.0) + pow(ay, 2.0) + pow(az, 2.0)));
	
	return magnitude;

}

int close_to(double TOL, double point, double value){
	
	if((point < (value + TOL)) && (point > (value - TOL))){
		return 1;
	} else {
		return 0;
	}
	
}

void printStuff(){
	fflush(stdout);
	printf("Ok, I'm receiving data.\n");
	fflush(stdout);
	printf("I'm waiting");
	fflush(stdout);
	
}
