#include<stdio.h>
#include <math.h>

#define F(x,y)  (x)*(x)+(y)
int main()
{
  double y0,x0,y1,x1,y1_0,a,n,h,f,f1;
  int j,count,flag;
 
  printf("\nEnter the value of x0: ");
  scanf("%lf",&x0);
  printf("\nEnter the value of y0: ");
  scanf("%lf",&y0);
  printf("\nEnter the value of h: ");
  scanf("%lf",&h);
  printf("\nEnter the value of last point: ");
  scanf("%lf",&n);
  for(x1=x0+h,j=1; x1<=n+h; x1=x1+h,j++)
  {
    count=0;
    flag=0;
    f=F(x0,y0);
    y1_0 = y0 + (h * f);
    printf("\n\n * * y%d_0 = %.3lf * *",j,y1_0);
     do
      {
    count++;
    f=F(x0,y0);
    f1=F(x1,y1_0);
    y1 = y0 + h/2 * ( f + f1);
    printf("\n\n * * x = %.3lf => y%d_%d = %.3lf * *",x1,j,count,y1);
    if(fabs(y1-y1_0)<0.00001)
     {
      printf("\n\n\n\n * * * * y%d = %.3lf * * * *\n\n",j,y1);
      flag=1;
     }
    else
      y1_0 = y1;
      }while(flag!=1);
    y0 = y1;
  }
return 0;
}
