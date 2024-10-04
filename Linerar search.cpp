#include<stdio.h>

int main()
{
    int a[5], i, key, flag;

    printf("Enter five elements ");
    for(i=0; i<5; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter to search ");
    scanf("%d", &key);

    for(i=0; i<6; i++)
    {
        if(a[i]==key)
            flag = 1;
    }
    if(flag == 1)
        printf("Found.");

    else
        printf("Not found.");
}
