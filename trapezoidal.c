/*
Develop a C program to implement Trapezoidal Rule for numerical integration. In each
iteration, the program computes the integral by doubling the number of intervals.
The program terminates when the desired precision is achieved.
Test on:
1 
∫ 1/(1+x) dx
0 

The computed value needs to be correct upto the 4 th decimal place
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

float y(float x)
{
    return 1/(1+x);
}

int main()
{
    float x0,xn,h,s=0,s_old=0,err=0,err_old=0;
    float e=.00005;  
    int i=0,n=1,count=0;
    printf("Enter x0,xn :");
    scanf("%f%f",&x0,&xn);
    printf("i\tn\tI\t\terror\n");
    
    while(!((count>0)&&(fabs(err-err_old)<e)))
    {
        h=(xn-x0)/n;
        s_old=s;
        s=y(x0)+y(xn);
        for(i=1;i<=n-1;i++)
        {
            s+=2*y(x0+i*h);
        }
        s*=(h/2);
        err_old=err;
        err=fabs(s-s_old);
        if(count)
            printf("%d\t%d\t%f\t%f\n",i,n,s,err);
        else
            printf("%d\t%d\t%f\t--------\n",i,n,s);
        count++;
        n++;
    }
    printf("\n\nI = %f\n",s);
    
    return 0;
}
