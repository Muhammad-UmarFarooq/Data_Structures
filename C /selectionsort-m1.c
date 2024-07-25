#include<stdio.h>
void main()
{
    int a[]={8,3,1,4,5};
    int i,j,min,temp;
    //display unsorted array
    printf("the unsorted array is:\n");
    for ( i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);        
    }
   //selection sort

    for ( i = 0; i < 5; i++)
    {
        // set current element as minimum
        min=i;
        // check the element to be minimum
        for ( j = i+1; j < 5; j++)
        {
           if(a[j]<a[min])
           {
           min=j;
           }
        }
        // swap the minimum element with the current element
        if(min!=i)
        {
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
        
    }
    // display sorted array
    printf("\nthe sorted array is:\n");     
    for(i=0;i<5;i++)
        {
            printf("%d ",a[i]);
        }

    
}