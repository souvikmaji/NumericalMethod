#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define max(a,b,c) ((a>b)?((a>c)?a:c):((b>c)?b:c))
#define e 0.000005

int main()
{
  float *XN,*XO,*A,S1,S2,d,error;
int i,j,k,M=100,n;
	printf("Enter the no of variables : ");
	scanf("%d",&n);
	XN=(float*)malloc(n*sizeof(float));
	XO=(float*)malloc(n*sizeof(float));
	A=(float*)malloc(n*(n+1)*sizeof(float));
	printf("Enter the augmented matrix : \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<=n;j++)
		{
			scanf("%f",A+(n+1)*i+j);
		}
	}
	
	printf("\n\n\n");
	for(i=0;i<n;i++)
	{
		*(XN+i)=0;
	}
	printf("k\tX0\t\t X1\t\tX2\t\terror\n");
	for(k=0;k<M;k++)
	{
		for(i=0;i<n;i++)
		{
			*(XO+i)=*(XN+i);
		}
		for(i=0;i<n;i++)
		{
			S1=S2=0;
			for(j=0;j<=i-1;j++)
			{
				S1=S1+*(A+(n+1)*i+j)*(*(XN+j));
			}
			for(j=i+1;j<n;j++)
			{
				S2=S2+*(A+(n+1)*i+j)*(*(XN+j));
			}
			*(XN+i)=(*(A+(n+1)*i+n)-S1-S2)/(*(A+(n+1)*i+i));
		}
		d=(float)fabs(*(XN)-*(XO));
		
		for(i=1;i<n;i++)
		{
			if((float)fabs(*(XN+i))-*(XO+i)>d)
				d=(float)fabs(*(XN+i)-*(XO+i));
		}
		
		error = max((*(XN + 0) - *(XO + 0)),(*(XN + 1) - *(XO + 1)),(*(XN + 2) - *(XO + 2)));
		printf("%d\t%lf\t%lf\t%lf\t%f\n",k,*(XN + 0),*(XN + 1), *(XN + 2),error); 
		if(d<e)
			break;
	}
	//printf("%d\n",k);
	printf("\nThe root of the equation are : \n");
	for(i=0;i<n;i++)
	{
		printf("X(%d)	=	%f\n",i+1,*(XN+i));
	}
	
	return 0;
}


