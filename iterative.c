/*Develop a c program to implement fixed point iteration. Apply the method on the following :
1) e^x - 4x^2 = 0

Keep check on whether the condition for convergence is satisfied through your program.
Display the output in a tabular form with the following information.

i		x(i)		|g'(x(i))|		f(x(i))		abs.error		OrderOfConvergence(OC)

Precision upto 6th decimal places.
Condition for convergence: |g'(x)| < 1 
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>


double G(double x)
{
	double value = exp(x);
	value = sqrt(value);
	value = value/2;
	return value;
}

double FunctionalValue(double x)
{
    double value = (exp(x) - 4*pow(x,2));
    return value;
}

int main()
{
    double oldR = 1;
    double newR;
    double diff;
    double oldAbsError, newAbsError;
    int i = 0;
	
    printf("Solution of e^x - 4x^2 = 0 using fixed point iteration\n");
    printf("Initial Approximation: 1\n");

    printf("i\tRoot\t\tG'(Root)\tF(Root)\t\tAbsoluteError\torderOfConvergence\n",newAbsError, log(newAbsError)/log(oldAbsError));

    do
    {
        newR = G(oldR);
        diff = newR/2;
        newAbsError = fabs(newR - oldR);
        printf("%d\t%f\t%f\t%f\t%f\t%f\n",i, oldR, diff, FunctionalValue(oldR), newAbsError, log(newAbsError)/log(oldAbsError));
        oldAbsError = newAbsError;
        i++;
        oldR = newR;



    }while(newAbsError>0.000001);
	printf("Final Answer: %f\n",oldR);
	return 0;
}
