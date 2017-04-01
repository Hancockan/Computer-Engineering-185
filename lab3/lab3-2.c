#include <stdio.h>
#include <math.h>

int main()
{
//No changes need to be made.
int integerResult = 6427 + 1725;
printf("6427 + 1725 = %d\n", integerResult);

//No changes need to be made.
integerResult = (6971 * 3925) - 95;
printf("(6971 * 3925) - 95 = %d\n", integerResult);

//The numbers are integers so the 12 / 5 won't come out to 2.4 and since the answer is a double
//it won't be correct.
double doubleResult = 79 + 12.0 / 5.0;
printf("79 + 12.0 / 5.0 = %.2lf\n", doubleResult);

//No changes need to be made.
doubleResult = 3640.0/107.9;
printf("3640.0 / 107.9 = %.2lf\n", doubleResult);

//Since integer division won't give the correct answer for the expression inside the parens, doubleResult
//needs to be used instead and the number need to be decimals.
doubleResult = (22.0/3.0) *3.0;
printf("(22.0 / 3.0) * 3.0 = %.2lf\n", doubleResult);

//The expression uses integer division even though the answer will be a double so
// the numbers need to be decimals.
doubleResult = 22.0/(3.0*3.0);
printf("22 / (3 * 3) = %.2lf\n", doubleResult);

//The expression uses integer division even though the answer will be a double so
// the numbers need to be decimals.
doubleResult = (22.0/3.0*3.0);
printf("22.0 / 3.0 * 3.0 = %.2lf\n", doubleResult);

//No changes need to be made.
doubleResult = (22.0/3) * 3.0;
printf("(22.0 / 3) * 3.0 = %.2lf\n", doubleResult);

//The answer is a decimal so doubleResult needs to be used instead of integerResult.
doubleResult = 22.0/(3*3.0);
printf("22.0/(3 * 3.0) = %.2lf\n", doubleResult);

//No changes need to be made.
doubleResult = 22.0/3.0 * 3.0;
printf("22.0/ 3.0 * 3.0 = %.2lf\n", doubleResult);

//No changes need to be made.
doubleResult = (M_PI) * (23.567/2.0) * (23.567/2.0);
printf("The area of a circle with circumference 23.567 is %.2lf units squared.\n", doubleResult);

//The 14 needs to be in decimal form because the answer expects a double.
doubleResult = 14.0 * 0.3048;
printf("14 feet converted to meters is %.2lf meters\n", doubleResult);

//No changes need to be made.
doubleResult = (76-32)/ 1.8;
printf("76 degrees fahrenheit is %.2lf degrees Centigrade.\n", doubleResult);


return 0;
}