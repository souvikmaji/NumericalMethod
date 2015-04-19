/*

Assignment 5:

 The function   x^3 - 2x^2- 4x + 8 = 0  has a double root at x=2. How
 would you change your program to apply Newton-Raphson method to solve the
 above eqn. at x=2.
 The solution needs to be correct upto 3 decimal places. Take an initial
 guess of x0 = 1.2

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x)
{
    return (x*x*x - 2*x*x - 4*x + 8);
}


double diff(double x)
{
        return (3*x*x - 4*x - 4);
}



int main()
{

    printf("Solution of x^3 - 2x^2- 4x + 8 = 0 using newton Raphson\n");
    printf("Initial guess = 1.2\n");
    double newRoot, oldRoot = 1.2;
    double oldError = 2, newError;
    int i = 0;

    printf("i\troot\t\tf(root)\t\tError\t\torder of convergence\n");


    do
    {
            newRoot = oldRoot - (f(oldRoot)/diff(oldRoot));
            newError = fabs(newRoot - oldRoot);
            printf("%d\t%f\t%f\t%f\t%f\n", i++, oldRoot, f(oldRoot), newError, log(newError)/log(oldError));
            
            oldRoot = newRoot;
            oldError = newError;

    }while(newError > 0.0000001);
    printf("\n\nFinal Answer:%f\n", newRoot);
    return 0;
}
