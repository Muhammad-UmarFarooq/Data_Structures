#include<stdio.h>


// Function for merging arrays in sorted order
void merge(int a[],int lb,int mid,int ub)
{
    int i=lb;
    int j=mid+1;
    int k=lb;
    // temp array
    int b[mid+ub];
    while(i<=mid && j<=ub)
    {
        if(a[i] <= a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    
    // push the remaining elements of mid+1 to ub
    if(i>mid)
    {
        while(j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    
    //push the remaining elements of lb to mid 
    else
    {
        while(i <= mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }
    
    // Now copy the temp b[] array elements to original a[] array
    for(k=lb;k<=ub;k++)
    {
        a[k]=b[k];
    }
}



// Function to divide the array
void mergeSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb + ub)/2;
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}


// Function to print the array
void printArray(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}


// Main function
int main()
{
    int a[]={12,31,25,8,32,17,40,42};
    int n=sizeof(a)/sizeof(a[0]);
    printf("Before sorting array elements are -\n");
    printArray(a,n);
    mergeSort(a,0,n-1);
    printf("After sorting array elements are -\n");
    printArray(a,n);
    return 0;
}


