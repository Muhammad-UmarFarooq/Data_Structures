#include <stdio.h>
void main()
{
    int n, i, j, temp, a[50];
    printf("enter how many elements:");
    scanf("%d", &n);
    printf("enter elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The sorted elements are:");
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {   
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}