// lab7.c
//
// This is the outline for your program
// Please implement the functions given by the prototypes below and
// complete the main function to make the program complete.
// You must implement the functions which are prototyped below exactly
//  as they are requested.

#include <stdio.h>
#include <math.h>
#define PI 3.141592653589

//NO GLOBAL VARIABLES ALLOWED


//PRE: Arguments must point to double variables or int variables as appropriate
//This function scans a line of explore data, and returns
//  True when left button is pressed
//  False Otherwise
//POST: it modifies its arguments to return values read from the input line.
int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT);

// PRE: -1.0 <= x_mag <= 1.0
// This function computes the roll of the esplora in radians
// if x_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double roll(double x_mag);

// PRE: -1.0 <= y_mag <= 1.0
// This function computes the pitch of the esplora in radians
// if y_mag outside of -1 to 1, treat it as if it were 1 or -1
// POST: -PI/2 <= return value <= PI/2
double pitch(double y_mag);


// PRE: -PI/2 <= rad <= PI/2
// This function scales the roll value to fit on the screen
// POST: -39 <= return value <= 39
int scaleRadsForScreen(double rad);

// PRE: num >= 0
// This function prints the character use to the screen num times
// This function is the ONLY place printf is allowed to be used
// POST: nothing is returned, but use has been printed num times
void print_chars(int num, char use);

//PRE: -39 <= number <=39
// Uses print_chars to graph a number from -39 to 39 on the screen.
// You may assume that the screen is 80 characters wide.
void graph_line(int number);

int main()
{
	double x, y, z;			// magnitude values of x, y, and z accelerations
	int b_Up, b_Down, b_Left, b_Right;	// variables to hold the button statuses
	double roll_rad, pitch_rad;		// value of the roll measured in radians
	int scaled_valueP, scaled_valueR, return1 = 1, return2; 	// value of the roll adjusted to fit screen display
	int t, b_Extra1, b_Extra2, s, Setting;
	//insert any beginning needed code here
	return2 = 0;
	int i = 0,k = 0,p = 0;
	
	do
	{
		// Get line of input
		scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &t, &x, &y, &z, &b_Down, &b_Up, &b_Left, &b_Right, &b_Extra1, &s);
		//printf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d\n", t, x, y, z, b_Down, b_Up, b_Left, b_Right, b_Extra1, s);
		
		// check for button input
		
		return1 = read_acc(&x, &y, &z, &t, &b_Up, &b_Down, &b_Left, &b_Right);
		
		// calculate roll and pitch
		roll_rad = roll(x);
		if(roll_rad == 0){
			roll_rad = 1.0;
		}
		pitch_rad = pitch(y);
		if(pitch_rad == 0){
			pitch_rad = 1.0;
		}
		//printf("%lf\n", roll_rad);
		
		// switch between roll and pitch(up vs. down button)
		
		if(p == 0){
			return1 = 1;
			p++;
		}
		//to switch to roll
		if(return1 == 1){
			return2 = 1;
		}
		//to switch to pitch
		if(return1 == 2){
			return2 = 2;		
		}
		/*
		if(return2 == 2){
			printf("pitch\n");
		}else if(return2 == 1){
			printf("roll\n");
		}
		*/
		// Scale your output value
		
		scaled_valueP = scaleRadsForScreen(pitch_rad);
		scaled_valueR = scaleRadsForScreen(roll_rad);
		/*
		if(return2 == 2){
			printf("%d\n", scaled_valueP);
		}else if(return2 == 1){
			printf("%d\n", scaled_valueR);
		}
		*/
		// Output your graph line
		
		if(return2 == 2){
			graph_line(scaled_valueP);
		}else if(return2 == 1){
			graph_line(scaled_valueR);
		}
		
		if(return1 == 3){
			break;
		}
		fflush(stdout);
	} while (1); // Modify to stop when left button is pressed
	return 0;
}

int read_acc(double* a_x, double* a_y, double* a_z, int* time, int* Button_UP, int* Button_DOWN, int* Button_LEFT, int* Button_RIGHT){
	scanf("%d, %lf, %lf, %lf, %d, %d, %d, %d, %d, %d", &time, &a_x, &a_y, &a_z, &Button_DOWN, &Button_UP, &Button_LEFT, &Button_RIGHT);
	
	if(Button_UP == 1){
		return 1;
	}else if(Button_DOWN == 1){
		return 2;
	}else if(Button_LEFT == 1){
		return 3;
	}else{
		return 0;
	} 
}

double roll(double x){
	double roll = asin(x); 
	if(roll > 1){
		return 1;
	}else if(roll < -1){
		return -1;
	}
	else if(isnan(asin(x)) != 0 ){
		return 0;
	}
	return roll;
}

double pitch(double y){
	double pitch = asin(y);
	if(pitch > 1){
		return 1;
	}else if(pitch < -1){
		return -1;
	}
	else if(isnan(asin(y)) != 0 ){
		return 0;
	}
	return pitch;
}

int scaleRadsForScreen(double rad){
	
	int rads = rad * 39;
	return rads;
	
}

void print_chars(int num, char use){
	if(use == '0'){
		printf("%40c\n", use);
	}
	
	if(use == 'r'){
		for(int spaces = 39;spaces > 0;spaces--){
			printf(" ");
		}
		for(int i = num;i > 0;i--){
			printf("%c", use);
		}
		printf("\n");
	}
	
	if(use == 'l'){
		for(int spaces = (39 - fabs(num));spaces > 0;spaces--){
			printf(" ");
		}
		for(int i = fabs(num);i > 0;i--){
			printf("%c", use);
		}
		printf("\n");
	}
	
}

void graph_line(int number){
	
	char toUse;
	if(number < 0){
		toUse = 'l';
	}else if(number > 0){
		toUse = 'r';
	}else{
		toUse = '0';
	}
	print_chars(number, toUse);
	
}
