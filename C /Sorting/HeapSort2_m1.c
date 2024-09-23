//heap sort with 0 based index
//gfg reference -- iterative heap sort

#include<stdio.h>
void buildMaxHeap(int arr[], int n) 
{ 
  //here we started index with 1 to compare 1 index with 0
  //if we take 0 here then there is no way to compare that 0 index with 0 
  for(int i=1;i<n;i++)
  {
    // here child i.e.arr[i] is compared with its parent i.e.arr[i-1]/2
    //  for 0 based index formula to find parent ele. => [i-1]/2
    //  for 1 based index formula to find parent ele. => i/2
   if(arr[i] > arr[(i-1)/2])
   {
       // here we assigned i to j so that we can swap using j in this way segmentation fault can be avoided
       // *1) here j is indicating added ele. index
       int j = i;
      // *2) added ele. index j is compared with its parent   
       while(j>-1 && arr[j] > arr[(j-1)/2])
       {
           //swapping
           int temp=arr[j]; 
	       arr[j]=arr[(j-1)/2]; 
		   arr[(j-1)/2]=temp;
		   //here we are adding from downwards it goes upto root node and compares in this way
		   //in this way the added node is compared with parent nodes in its way
		   //now j is assigned with parent
		  //  *3) now j is indicating the parent ele. with which swapping has occured
		   j = (j-1)/2;
       }
   }
  }
}

void heapSort(int arr[], int n) 
{ 
	buildMaxHeap(arr, n); 
    // after building max heap we will now delete
    for(int i=n-1;i>0;i--)
    {
         // swap value of first indexed 
        // with last indexed 
        int temp=arr[0]; 
        arr[0]=arr[i]; 
        arr[i]=temp; 
        // maintaining heap property 
        // after each swapping 
        //here index points to the greater child ele.
        // j points to 0th index i.e. first ele.
        int j = 0, index; 
        do
        { 
            // index -> left child
            index = (2 * j + 1); 
              
            // if left child is smaller than 
            // right child point index variable 
            // to right child 
            // and here we are checking that index is < arraylastindex -1 i.e.if it is < last ele. and last ele. - 1 this last ele.-1 is bcz index is incremented by 1 for right child
            if (arr[index] < arr[index + 1] && 
                                index < (i - 1)) 
                index++; 
          // if parent is smaller than child 
            // then swapping parent with child 
            // having higher value 
            //again here we are checking index is not pointing to last ele.
            if (arr[j] < arr[index] && index < i) 
            { 
                int tem1=arr[j]; 
                arr[j]=arr[index]; 
                arr[index]=tem1; 
            }
            // now j points to that particular child index and recursively compares it with its child nodes
            j = index;
    }
    while(index < i);
    
    }
}
// driver code
int main() 
{ 
	int arr[] = {10, 20, 15, 17, 9, 21}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	
	printf("Given array: "); 
	for (int i = 0; i < n; i++) 
		printf("%d ", arr[i]); 
	printf("\n"); 

	heapSort(arr, n); 

	// print array after sorting 
	printf("Sorted array: "); 
	for (int i = 0; i < n; i++) 
		printf("%d ", arr[i]); 

	return 0; 
} 

