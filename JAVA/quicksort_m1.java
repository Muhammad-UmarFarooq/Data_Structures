public class QuickSort
{
    public static int partition(int arr[],int lb,int ub)
    {
        int pivot=arr[ub];
        int i=lb-1;
        
        for(int j=lb;j<ub;j++)
        {
            if(arr[j] < pivot)
            {
                i++;
                // swap
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
        i++;
        int temp=arr[i];
        arr[i]=pivot;
        arr[ub]=temp;
        return i;
        
    }
    public static void quickSort(int arr[],int lb,int ub)
    {
        if(lb < ub)
        {
            int pidx=partition(arr,lb,ub);
            quickSort(arr,lb,pidx - 1);
            quickSort(arr,pidx + 1,ub);
        }
    }
    public static void main(String args[])
    {
        int[] arr={6,3,9,5,2,8};
        int n=arr.length;
         // print original array
    System.out.println("Original array:");
    for(int i=0;i<n;i++)
    {
        System.out.println(arr[i]);
    }
        quickSort(arr,0,n-1);
    // print sorted array
     System.out.println("Sorted array:");
    for(int i=0;i<n;i++)
    {
        System.out.println(arr[i]);
    }
    }
}
