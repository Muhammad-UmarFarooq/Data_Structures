import java.util.*;
class bubblesort_m1
{
  // method to print array
  public static void printarray(int arr[])
  {
  for(int i=0;i<arr.length;i++)
    {
      System.out.print(arr[i]+" ");
    }
    System.out.println();
  }
  // main method
  public static void main(String args[])
  {
    int a[]={8,4,2,9,1};
    int n=a.length;
    //dispaly unsorted array
    System.out.println("the unsorted array is:");
    //calling method
    printarray(a);
    //bubble sort
    for(int i=0;i<n-1;i++)
    {
      for(int j=0;j<n-1-i;j++)
      {
        if(a[j]>a[j+1])
        { 
           //swapping
         int temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
        }
        
      }
    }
    //display sorted array
    System.out.println("the sorted array is:");
    //calling method
    printarray(a);
    
  }
}