#include <stdio.h>
void main()
{
    int a[5]={5,4,1,2,6};
    printf("the unsorted elements are:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nThe sorted elements are:\n");
    for (int i = 0; i < 5 - 1; i++)
    {
        for (int j = 0; j < 5 - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {   
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }
}