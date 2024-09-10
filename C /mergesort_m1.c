#include<stdio.h>
// Function for merging arrays in sorted order
void merge(int a[],int lb,int mid,int ub)
{
 /* suppose lb=6,mid=8,ub=10
       here 1st subarray = 6 to 8
            2nd subarray = 9 to 10
    if 1st sub array size is upto mid then it is '8' size(but size we need is only for 6,7,8 index element i.e.'3' size)
    so formula used here is mid - lb i.e.8-6=2(since subtracting with lb we are getting one element less so we added 1)
*/
    int n1=mid-lb+1;//size of 1st subarray
/* for 2nd sub array we need size for 9 and 10 elements i.e 2
       thats why used ub - mid i.e. 10-8=2(since here size is correct we no need to add or subtract 1)
       Here we had known the before last element size i.e. 'mid' thats why we got exact size
       But in 1st sub array we dont knoe last element size thats why we took 1st array 1st element size i.e. 6 thats why we added '1'
*/
    int n2 =ub-mid;//size of 2nd sub array
    
    int LeftArray[n1],RightArray[n2];//temporary arrays
    
    // copy data to temporary arrays
    for(int i=0;i<n1;i++)
    LeftArray[i]=a[lb+i];
    for(int j=0;j<n2;j++)
    RightArray[j]=a[mid+1+j];
    
    int i=0; //intial index of 1st subarray
    int j=0; // intial index of 2nd subarray 
    int k=lb; // intial index of merged subarray
    
    while(i<n1 && j<n2)
    {
        if(LeftArray[i] <= RightArray[j])
        {
            a[k]=LeftArray[i];
            i++;
        }
        else
        {
            a[k]=RightArray[j];
            j++;
        }
        k++;
    }
    
    // push the remaining elements of 1st subarray
        while(i<n1)
        {
            a[k]=LeftArray[i];
            i++;
            k++;
        }
    
    
    //push the remaining elements of 2nd subarray
        while(j<n2)
        {
            a[k]=RightArray[j];
            j++;
            k++;
        }
}
    



// Function to divide the array
void mergeSort(int a[],int lb,int ub)
{
    if(lb<ub)
    {
        // Calculating mid in this way avoids overflow
        int mid = lb + ( ub - lb ) / 2;
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


