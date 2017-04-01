// CprE 185: Lab 3
// Problem 1: Mysterious Output

#include <stdio.h>

int main()
{
	int integerResult;
	double decimalResult;
	
	integerResult = 77 / 5;
	printf("The value of 77/5 is %d\n", integerResult);
	//%lf is saying that there should be a double there, but since integer division was used
	//there needs to be a %d.

	integerResult = 2 + 3;
	printf("The value of 2+3 is %d\n", integerResult);
	//In order to print the integer for the %d in the printf statement, you need to identify
	//it after a comma after the quotation mark.

	decimalResult = 1.0 / 22.0;
	printf("The value 1.0/22.0 is %lf\n", decimalResult);
	//%lf needs to be used to specify that a floating point value is going to be printed.
	
	return 0;
}

