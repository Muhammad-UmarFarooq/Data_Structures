#include <stdio.h>
void main()
{
    int n, i,current, j, a[50];

    // input from user
    printf("enter how many elements:");
    scanf("%d", &n);
    printf("enter elements:");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    //insertion sort
    for(i=0;i<n;i++)
    {
      current=a[i];
      j=i-1;
      while(j>=0 && current<a[j])
      {
        a[j+1]=a[j];
        j--;
      }
      a[j+1]=current;
    }
    
    //print sorted array
    printf("The sorted elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}