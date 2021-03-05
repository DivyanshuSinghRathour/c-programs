#include<stdio.h>
void main()
{
    int arr[2][2][2],i,j,k;
    printf("Enter the elements of the matrix: \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
            for(k=0;k<2;k++)
            {
                scanf("%d",&arr[i][j][k]);
            }
        }
    }
    printf("MATRIX IS: \n");
    for(i=0;i<2;i++)
    {
        printf("\n");
        for(j=0;j<2;j++)
        {
            printf("\n");
            for(k=0;k<2;k++)
            {
                printf("\tarr[%d][%d][%d] = %d",i,j,k,arr[i][j][k]);
            }
        }
    }
}
