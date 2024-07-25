class insertionsort_m1
{
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
    public static void main(String args[])
    {
        int a[]={7,5,3,1,2};
        int n=a.length;
        // display unsorted array
        System.out.println("the unsorted array is:");
        printarray(a);
        // insertion sort
        for(int i=0;i<n;i++)
        {
            int current=a[i];
            int j=i-1;
            while(j>=0 && current<a[j])
            {
                a[j+1]=a[j];
                j--;
            }
            a[j+1]=current;
        }
        // display sorted array
        System.out.println("the sorted array is:");
        printarray(a);
    }
}