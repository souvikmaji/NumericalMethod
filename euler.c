/*
Develop a C program to implement Euler’s Method of numerical solution of first order
differential equations.

Produce the output of the program in the following format:
x       y(Computed)     y(Actual Value)         AbsoluteError
*/
#include <stdio.h>
#include <math.h>
/*
#define f(x,y) ((2*(x)*(x)) + (2*(y)))
#define sol(x) ((1.5*(exp(2*(x)))) - (x*x) - (x) - 0.5)
*/
double f(double x, double y)
{
        return ((2*(x)*(x)) + (2*(y)));
}

double sol(double x)
{
        return ((1.5*(exp(2*(x)))) - (x*x) - (x) - 0.5);
}

int main(){
      double y0 = 1,x0 = 0;

      double h = 0.1;

      printf("x\t      y(computed)\ty(actual)\tabs_error");

      do{

         double yact = sol(x0);
         double error = fabs(yact - y0);

         printf("\n%lf\t%lf\t%lf\t%lf",x0,y0,yact,error);

         y0 = y0 + (h * f(x0,y0));
         x0 = x0 + h;
       }while(x0 < 1);
      printf ("\n");
      return 0;
}

