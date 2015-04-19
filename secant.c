/*

Develop a C program to implement Secant method. Test your program on the following:
e^x = 2x+1
The solution needs to be correct upto 4th place after the decimal point.
Display the result in this form :
i   x(i)   f(x(i))   absError   OrderOfConvergence
*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return (exp(x) -2*x -1);
}


int main()
{
	printf("Solution of e^x = 2x +1 using secants method\n");
	printf("Initial guess: 1\n");
    double veryOldRoot = 1, oldRoot = 3, newRoot;
    double oldError = 2;
    double newError;
    int i = 0;

    printf("i\tRoot\t\tf(Root)\t\tError\t\torder of convergence\n", i++, newRoot, f(newRoot), newError, log(newError)/log(oldError));
    do
    {
        newRoot = ((veryOldRoot*f(oldRoot) - oldRoot*f(veryOldRoot))/(f(oldRoot) - f(veryOldRoot)));
        newError = fabs(newRoot - oldRoot);
        printf("%d\t%f\t%f\t%f\t%f\n", i++, newRoot, f(newRoot), newError, log(newError)/log(oldError));
        veryOldRoot = oldRoot;
        oldRoot = newRoot;
        oldError = newError;
    }while((f(newRoot)!=0 )|| (fabs(newRoot - oldRoot) > 0.000001));

    printf("\n\nFinal Answer:%f\n", newRoot);
    return 0;
}
