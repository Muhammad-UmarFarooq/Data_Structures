//heap sort with 1 based index
//abdul bari sir reference
#include<stdio.h>
 void Insert(int A  [],int n)
 {
    //  i stores arrays adding element index
    //  temp stores data to be inserted 
     int i=n,temp;
     temp=A[i];
     
     while(i>1 && temp>A[i/2])
     {
        //  If temp is > parent then parent is stored in temp position
         A[i]=A[i/2];
        //  Here i points to parent index after assigning parent to temp position
         i=i/2;
     }
     A[i]=temp;
 }
 int Delete(int A[],int n)
 {
     int i,j,x,temp,val;
    //  val-> deleting ele.
     val=A[1];
    //  x indicates last element to be replaced with deleted root element
    x=A[n];
    // last element copied to 1st position
    A[1]=A[n];
    // 1st position ele. copied to last position(which is to be deleted)
    A[n]=val;
    // i = 1st position ele. & j=left child
    i=1,j=i*2;
    // as we have deleted heap tree by 1 ele. that's why we wriiten n-1
    while(j<n-1)
    {
        // if right child > left child update j as right child by j+1
        if(A[j+1]>A[j])
        {
            j=j+1;
        }
        // if parent is < largest child ele. then swap
        if(A[i]<A[j])
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
            // after this again compare the replaced parent ele. with its childs
            // i -> replaced parent ele. which is noe at j position
            i=j;
            // j -> left child
            j=2*j;
        }
        // if A[i] is not less
        // break exits the loop
        else
            break;
    }
    return val;
}
 
 int main()
 {
     int H[]={0,10,20,30,25,5,40,35};
     for(int i=2;i<=7;i++)
       Insert(H,i);
     for(int i=1;i<=7;i++)
       printf("%d ",H[i]);
      printf("\n");
      for(int i=7;i>1;i--)
      {
         Delete(H,i); 
      }
     for(int i=1;i<=7;i++)
       printf("%d ",H[i]);
      printf("\n");
     
     return 0;
 }
