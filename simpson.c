/*
Develop a C program to implement Simpson’s 1/3 rd Rule.
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
    float e=.00005;  //precession
    float val;
    int i=0,n=1,count=0;
    printf("Enter x0,xn :");
    scanf("%f%f",&x0,&xn);
    val=err-err_old;
    printf("i\tn\tI\t\tabs err\t\t(abs error - old abs error)\n");
    
    while(!((count>0)&&(val<e)))
    {
        h=(xn-x0)/n;
        s_old=s;
        s=y(x0)+y(xn)+4*y(x0+h);
        for(i=3;i<=n-1;i+=2)
        {
            s+=4*y(x0+i*h)+2*y(x0+(i-1)*h);
        }
        s*=(h/3);
        err_old=err;
        err=s-s_old;
        val=fabs(fabs(err)-fabs(err_old));
        if(count>=2)
                printf("%d\t%d\t%f\t%f\t%f\n",count,n,s,fabs(err),val);
        else if(count==0)
                printf("%d\t%d\t%f\tNA\t\tNA\n",count,n,s);
        else
                printf("%d\t%d\t%f\t%f\tNA\n",count,n,s,fabs(err));
        count++;
        n++;
    }
    printf("\n\nI = %f\n",s);
    return 0;
}

