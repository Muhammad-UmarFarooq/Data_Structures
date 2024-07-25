#include <stdio.h>
void main()
{
    // declare & initialize variables
    int a[10];
    int n, i, j, min, temp;
    // taking input from user
    printf("enter how many values you want to enter:\n");
    scanf("%d", &n);
    printf("enter the values:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // selection sort
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    // display sorted array
    printf("\nthe sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}