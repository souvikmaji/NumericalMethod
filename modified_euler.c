/*
Develop a C program to implement Modiefied Euler’s Method of numerical solution of first order differential equations.

Produce the output of the program in the following format:
x       y(Computed)     y(Actual Value)         AbsoluteError
*/
#include <stdio.h>
#include <math.h>

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

      double y1 = y0 + (h * f(x0,y0));
      double x1 = x0 + h;
      printf("x\t\ty(computed)\ty(actual)\tabs_error");

      do{

         double yact = sol(x1);
         double error = fabs(yact - y1);
         x0 = x1;
         y0 = y1;
         printf("\n%lf\t%lf\t%lf\t%lf",x1,y1,yact,error);

         y1 = y0 + h*(f(x0,y0) + f(x1,y1))/2;
         //x1 = x1 + h;
         
         //h = h/2;
       }while((sol(x1) - y1));
      printf ("\n");
      return 0;
}

