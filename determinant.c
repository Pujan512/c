#include<stdio.h>
#include<math.h>

int determin(int arr[][50] , int p)
{
    int i=0,j=0,k,det,a[50][50][50];
    if (p==1)
    {
        return arr[0][0];
    }

    if(p==2)
    {
        det=arr[i][j]*arr[i+1][j+1]-arr[i][j+1]*arr[i+1][j];
        return det;
    }
    
if (p>=3)
    {
        for (int k = 1; k <= p; k++)
        {
            for (i=1; i<p; i++)
            {
                for (j=0; j<p; j++)
                    {
                        if(j==k-1)
                        {
                            continue;
                        }
                        else
                       {
                        if(k==p)
                        {
                            a[k][i-1][j]=arr[i][j];
                        }
                        else
                        {
                            if(j<=k-1)
                            {
                               a[k][i-1][j]=arr[i][j]; 
                            }
                            else
                            {
                                a[k][i-1][j-1]=arr[i][j];
                            }
                        }
                       }
                    }
                
            }
            
        }
        k=1,i=0,j=0,det=0;
            for ( j = 0; j < p; j++)
            {
                det=det+(pow(-1,j))*(arr[0][j]*determin(a[k],p-1));
                k++;
            }
            
        
        return det;
    }
    


}

int main()
{
    int a[50][50],n,ans;
    printf("Enter order for square matrix:");
    scanf("%d",&n);
    printf("Enter values for matrix:");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
        }
        
    }
    ans = determin(a, n);
    printf("The determinant of matrix:\n");
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ",a[i][j]);
            
        }

        printf("\n");
    }
    printf("=%d",ans);
    return 0;
}
