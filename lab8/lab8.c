#include <stdio.h>


#define MAXPOINTS 10000

// compute the average of the first num_items of buffer
double avg(double buffer[], int num_items){

	double average = 0.0;
	
	for(int i = 0;i < num_items;i++){ 
		
		average = (average + buffer[i]);
		
	}
	average = average/num_items;
	return average;
	
}
	

//update the max and min of the first num_items of array
void maxmin(double array[], int num_items, double* max, double* min);

//shift length-1 elements of the buffer to the left and put the 
//new_item on the right.
void updatebuffer(double buffer[], int length, double new_item){
	
	for(int i = 1;i <= length;i++){	
		buffer[i - 1] = buffer[i];
	}
	
	buffer[length] = new_item;
	
}


int main(int argc, char* argv[]) {

	double x[MAXPOINTS], y[MAXPOINTS], z[MAXPOINTS];
	double ax, ay, az;
	int BUTTON_LEFT, BUTTON_RIGHT, BUTTON_UP, BUTTON_DOWN, EXTRA_1, EXTRA_2;
	double avgx = 0.0, avgy = 0.0, avgz = 0.0;
	int lengthofavg = 0;
	int i = 0;
	if (argc>1) {
		sscanf(argv[1], "%d", &lengthofavg );
		printf("You entered a buffer length of %d\n", lengthofavg);
	}
	else {
		printf("Enter a length on the command line\n");
		return -1;
	}
	if (lengthofavg <1 || lengthofavg >MAXPOINTS) {
		printf("Invalid length\n");
		return -1;
	}

	do{
		scanf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &ax, &ay, &az, &BUTTON_DOWN, &BUTTON_UP, &BUTTON_LEFT, &BUTTON_RIGHT, &EXTRA_1, &EXTRA_2);
		//printf("%lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", ax, ay, az, BUTTON_DOWN, BUTTON_UP, BUTTON_LEFT, BUTTON_RIGHT, EXTRA_1, EXTRA_2);
		fflush(stdout);
		x[i] = ax;
		y[i] = ay;
		z[i] = az;
		
		if(i > lengthofavg - 1){
			updatebuffer(x, lengthofavg, x[i]);
		}
		if(i > lengthofavg - 1){
			updatebuffer(y, lengthofavg, y[i]);
		}
		if(i > lengthofavg - 1){
			updatebuffer(z, lengthofavg, z[i]);
		}
		
		if(i > (lengthofavg - 2)){
			avgx = avg(x, lengthofavg);
		}
		if(i > (lengthofavg - 2)){
			avgy = avg(y, lengthofavg);
		}
		if(i > (lengthofavg - 2)){
			avgz = avg(z, lengthofavg);
		}
		printf("%lf, %lf, %lf, %lf, %lf, %lf\n", ax, ay, az, avgx, avgy, avgz);
		
		i++;
	}while(1);
	
	/* Put your code here */


}

