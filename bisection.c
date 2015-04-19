/*Assignment 2
Develop a C program to implement Bisection method. Test your program to find root of the following equation.
xsin(x) + cos(x) = 0
x is in the interval (0, pi)
The solution needs to be correct up to the 6th place after decimal point
Display the output in a tabular form with the following information

i		a		b		m		f(m)		abs.error		OC

*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.14159265

double F(double x)
{
    double value = x*sin(x) + cos(x);
    return value;
}

int main()
{
    printf("Bisection Method for solution of xsinx + cosx = 0\n");
    printf("x is in the interval of (0, PI)\n");
    double lowerBound = 0;
    double upperBound = PI;
    double midPoint = (lowerBound + upperBound)/2;
    double interval;
    int i =0;
    printf("i\tlowerbound\tupperbound\tmidpoint\tf(mid)\t\tinterval\n");
    while(1)
    {
        interval = upperBound - lowerBound;
        if(F(midPoint)==0 || interval < 0.000001) {
            break;
        }
        printf("%d\t%f\t%f\t%f\t%f\t%f\n", i, lowerBound, upperBound, midPoint, F(midPoint), interval);
        if(F(midPoint)*F(lowerBound)<0){
                upperBound = midPoint;
        }
        else{
                lowerBound = midPoint;
        }
        i++;
        midPoint = (lowerBound + upperBound)/2;
    }
    printf("Final Answer: %f\n", midPoint);
    return 0;
}
