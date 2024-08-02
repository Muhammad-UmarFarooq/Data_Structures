#include<stdio.h>
void swap(int* a,int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[],int lb,int ub)
{
    // initialize pivot to be the first element
    int pivot=arr[lb];
    int start=lb;
    int end=ub;
    
    while(start < end)
    {
        // condition 1: find the first element greater than the pivot (from starting)
        while(arr[start] <= pivot && start < ub)
        {
            start++;
        }
        // condition 2: find the first element smaller than the pivot (from last)
        while(arr[end] > pivot && end > lb)
        {
            end--;
        }
        if(start < end)
        {
            swap(&arr[start],&arr[end]);
        }
    }
    swap(&arr[lb],&arr[end]);
    return end;
}
void quicksort(int arr[],int lb,int ub)
{
    if(lb < ub)
    {
        // Call partition function to find partition index
        int partitionindex=partition(arr,lb,ub);
        
        // Recursively call quicksort() for left and right half based on partition index
        quicksort(arr,lb,partitionindex - 1);
        quicksort(arr,partitionindex + 1,ub);
    }
}
void main()
{
    int arr[]={19,7,15,12,16,18,4,11,13};
    int n=sizeof(arr) / sizeof(arr[0]);
    printf("Original array:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    // Calling quicksort() to sort the given array
    quicksort(arr,0,n-1);
    printf("\nSorted array: ");
     for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    
}
