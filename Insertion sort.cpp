#include<stdio.h>

int main()
{
    int i,j,k=5,temp;
    int a[5];

    printf("Enter 5 numbers: \n");

    for(i=0; i<k; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<k; i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    printf("After insertion sort: \n");

    for(i=0; i<k; ++i)
    {
        printf("%d\t",a[i]);
    }
}
