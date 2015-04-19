/*
Develop a C program to implement Gaussian Elimination Method. Test the program on
the following system of linear equations:
        x1 + x2 − x3 + x4 = 2
        2x1 + x2 + x3 − 3x4 = 1
        3x1 − x2 − x3 + x4 = 2
        5x1 + x2 + 3x3 − 2x4 = 7
After elimination of each variable, display the augmented co-efficient matrix.
Incorporate pivoting in the program.
(Answer: x 1 = x 2 = x 3 = x 4 = 1 )
*/


# include <stdio.h>
# include <math.h>
int main()
{
    int i, j, k, n, iteration=0 ;
    float a[20][20],x[20] ;
    double s, p ;
    printf("Enter the number of equations : ") ;
    scanf("%d", &n) ;
    printf("\nEnter the co-efficients of the equations :\n\n") ;
    for(i = 0 ; i < n ; i++)
    {
        for(j = 0 ; j < n ; j++)
        {
            printf("a[%d][%d] = ", i, j) ;
            scanf("%f", &a[i][j]) ;
        }
        printf("b[%d] = ", i) ;
        scanf("%f", &a[i][n]) ;
    }
    
    
        printf("Augmented co-efficient matrix:\n");
        for(i = 0 ; i < n ; i++)
        {
                
                for(j = 0 ; j < n ; j++)
                {
                        printf("%f ",a[i][j]) ;
                }
                printf("%f\n", a[i][n]) ;
        }
        printf("\n");
       
    
    for(k = 0 ; k < n - 1 ; k++)
    {
        for(i = k + 1 ; i < n ; i++)
        {
            p = a[i][k] / a[k][k] ;
            for(j = k ; j < n + 1 ; j++)
            a[i][j] = a[i][j] - p * a[k][j] ;
        }
       printf("Augmented co-efficient matrix after %d elimination:\n",++iteration);
        for(i = 0 ; i < n ; i++)
        {
                for(j = 0 ; j < n ; j++)
                {
                        printf("%f ",a[i][j]) ;
                }
                printf("%f\n", a[i][n]) ;
        }
        printf("\n");
        
    }
    x[n-1] = a[n-1][n] / a[n-1][n-1] ;
    for(i = n - 2 ; i >= 0 ; i--)
    {
        s = 0 ;
        for(j = i + 1 ; j < n ; j++)
        {
            s += (a[i][j] * x[j]) ;
            x[i] = (a[i][n] - s) / a[i][i] ;
        }
    }
    printf("\nThe result is :\n") ;
    for(i = 0 ; i < n ; i++)
        printf("\nx[%d] = %.2f", i + 1, x[i]) ;
    printf("\n");
    return 0 ;
}
