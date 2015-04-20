/*
Develop a C program to invert a Non-Singular Matrix by Gauss-Jordan Method. 
Arrange for verification of the product of the matrix and the generated inverse.
Test the program on the following matrix:
1 5 3
1 3 2
2 4 −6
*/

#include <stdio.h>
#include <math.h>

int main()
{
        int n, i, j, k, l, m;
        printf("\nEnter the order of the matrix:");
        scanf("%d", &n);
        float a[n][n];
        float b[n][n];
        float c[n][n];
        float d[n][n];
        float x;
        
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        printf("\nEnter element %d of row %d:", j+1,i+1);
                        scanf("%f",&a[i][j]);
                }
        }
        
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        d[i][j]=a[i][j];
                }
        }
        
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                c[i][j]=0;
                }
        }
        
        for(i=0;i<n;i++){
                for(j=0;j<n;j++) {
                        if(i==j){
                        b[i][j]=1;
                        }
                         else{
                                b[i][j]=0;
                         }
                 }
        }
        
        for(j=0;j<n;j++){
                for(i=0;i<n;i++){
                        if(i!=j){
                                x=d[i][j];
                                for(k=0;k<n;k++){
                                        d[i][k]=d[i][k]-((d[j][k]*x)/d[j][j]);
                                        b[i][k]=b[i][k]-((b[j][k]*x)/d[j][j]);
                                }
                        }
                }
        }
        
        for(i=0;i<n;i++){
                if(d[i][i]==0){
                printf("The given matrix is not non-singular.\n");
                return 0;
                }
        }
        
        for(i=0;i<n;i++){
                x=d[i][i];
                for(j=0;j<n;j++){
                d[i][j]=d[i][j]/x;
                b[i][j]=b[i][j]/x;
                }
        }
        
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        for(k=0;k<n;k++){
                                c[i][j]+=(a[i][k]*b[k][j]);
                        }
                }            
        }
        
        printf("The given matrix A:\n");
        for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                        printf("%f	",a[i][j]);
                }
         printf("\n");
         }
         printf("The inverse matrix B:\n");
        
        for(i=0;i<n;i++){
                for(j=0;j<n;j++) {
                  printf("%f	",b[i][j]);
                 }
                 printf("\n");
        }
        
        printf("The product of A and B i.e. C:\n");
        for(i=0;i<n;i++) {
                for(j=0;j<n;j++){
                printf("%f	",fabs(c[i][j]));
                }
         printf("\n");
        }
        
        return 0;
}
