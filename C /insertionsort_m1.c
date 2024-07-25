#include<stdio.h>
// function to sort an array using insertion sort
void insertionsort(int arr[],int n)
{
    int i,current,j;
    for(i=0;i<n;i++)
    {
        current=arr[i];
        j=i-1;
        /* move elements of arr[] that are greater than current 
        element,to one position ahead of their current position*/
        while(j>=0 && arr[j]>current)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=current;
    }
}
//function to print array
void printarray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
// main function 
int main()
{
    int arr[]={12,11,13,5,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("the unsorted array is:\n");
    //calling function
    printarray(arr,n);
    //calling function
    insertionsort(arr,n);
    printf("\nthe sorted array is:\n");
    // calling function
    printarray(arr,n);
    return 0;
}