#include<stdio.h>
void main()
{
    int n;
    int i,j,arr[30];
    printf("enter the number of the array which you want to print: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the elements arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("\t%d",arr[i]);

    }
    getch();
}
