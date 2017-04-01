/* Lab 4 Wrapper Program */

#include <stdio.h>
#include <math.h>

#define TRUE 1

/* Put your function prototypes here */
int ButtonsPressed(int a, int b, int c, int d, int e);

int main(void) {
	int a, b, c, d, e, f, g;
	 	
	while (TRUE) {
		
		scanf("%d, %d, %d, %d, %d, %d", &a, &b, &c, &d, &e, &f);
		printf("%d %d %d %d %d %d\n", a, b, c, d, e, f);
		fflush(stdout);
		printf("Buttons Pressed: %d\n", ButtonsPressed(a, b, c, d, e));
		
		
	}

return 0;

}

int ButtonsPressed(int a, int b, int c, int d, int e){

	int count = 0;
	if(a == 1){
		count++;
	}
	if(b == 1){
		count++;
	}
	if(c == 1){
		count++;
	}
	if(d == 1){
		count++;
	}
	if(e == 1){
		count++;
	}
	return count;
}

/* Put your functions here */

