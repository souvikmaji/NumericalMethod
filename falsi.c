/*
Develop a C program to implement Regula-Falsi. Test your program to find a root of the following expression xsinx + cosx = 0.
Precision = 6 th place of decimal
Display the output in tabular form with columns:
i	(LowerBound)	(UppeBound)	c= (a+b)/2	f(c)	AbsoluteError	OrderofConvergence

The false position method differs from the bisection method only in the choice it makes for subdividing the interval at each iteration. It converges faster to the root because it is an algorithm which uses appropriate weighting of the intial end points x1 and x2 using the information about the function, or the data of the problem. In other words, finding x3 is a static procedure in the case of the bisection method since for a given x1 and x2, it gives identical x3, no matter what the function we wish to solve. On the other hand, the false position method uses the information about the function to arrive at x3.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14159265


double f(double x)
{
    double value = x*sin(x) + cos(x);
    return value;
}

double mod(double x)
{
        if(x<0)
            x = x*(-1);
        return x;
}

int main()
{
    double lowerPoint = 0;
    double upperPoint = PI;
    double root;
    double tempRoot = 3*PI;
    int i = 0;
	
    printf("i\tlowerpoint\tupperpoint\troot\t\t|root-temproot|\n");
    while(1)
    {
        root = ((lowerPoint*f(upperPoint)) - (upperPoint*f(lowerPoint)))/(f(upperPoint) - f(lowerPoint));
        if(f(root)==0 || mod(root - tempRoot) < 0.0000001)
            break;
        if(f(lowerPoint)*f(root) < 0)
            upperPoint = root;
        else
            lowerPoint = root;
        printf("%d\t%lf\t%f\t%f\t%f\n", i++,lowerPoint, upperPoint, root, mod(root - tempRoot));
        tempRoot = root;
    }

    printf("Final Answer:%f",root);
    return 0;
}
