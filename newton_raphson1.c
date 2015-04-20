/*
Develop a C program to implement Newton-Raphson method. Test your program on the following:
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
    return (exp(x) - 2*x -1);
}


double diff(double x)
{
        return (exp(x) - 2);
}



int main()
{

    printf("Solution for e^x = 2x+1 using newton raphson method\n");
    printf("Initial approximation:1\n");
    
    double newRoot, oldRoot = 1;
    double oldError = 2, newError;
    int i = 0;

    printf("i\tRoot\t\tf(Root)\t\tError\t\tOrder of convergence\n");

    while(1)
    {
            newRoot = oldRoot - (f(oldRoot)/diff(oldRoot));
            newError = fabs(newRoot - oldRoot);
            printf("%d\t%f\t%f\t%f\t%f\n", i++, oldRoot, f(oldRoot), newError, log(newError)/log(oldError));
            if(fabs(oldRoot - newRoot)<0.000001)
                break;
            oldRoot = newRoot;
            oldError = newError;

    }
    printf("\n\nFinal Answer:%f\n", newRoot);
    return 0;
}
