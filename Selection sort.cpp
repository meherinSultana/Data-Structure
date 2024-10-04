#include<stdio.h>

int main()
{
    int i,j,p,mvalue,pos,n=5;
    int a[5];
    printf("Enter 5 numbers: \n");

    for(i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0; i<(n-1); i++)
    {
        mvalue=a[i];
        pos=i;
        for(j=i; j<n; j++)
        {
            if(a[j]<mvalue)
            {
                mvalue=a[j];
                pos=j;
            }
        }
        p=a[i];
        a[i]=a[pos];
        a[pos]=p;
    }
    printf("After selection sort: \n");
    for(i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
}
