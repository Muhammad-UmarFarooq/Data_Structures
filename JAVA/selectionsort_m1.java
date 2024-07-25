import java.util.*;
class selectionsort_m1{
  // method to print array
 public static void printarray(int arr[])
 {
   int n=arr.length;
    for(int i=0;i<n;i++)
    {
      System.out.print(arr[i]+" ");
    }
    System.out.println();
 }
//  main method
 public static void main(String args[])
 {
    int a[]={8,4,2,9,1};
    int n=a.length;
    int min,i,j,temp;
    // display unsorted array
    System.out.println("the unsorted array is:");
    //calling method
    printarray(a);
    //selectionsort
    for(i=0;i<n;i++)
    {
      min=i;
      for(j=i+1;j<n;j++)
      {
         if(a[j]<a[min])
         {
         min=j;
           }
     }
      if(min!=i)
      {
        //swapping
         temp=a[i];
         a[i]=a[min];
         a[min]=temp;
      }
    }
    //display sorted array
    System.out.println("the sorted array is:");
    //calling sorted array
    printarray(a);
 }
}