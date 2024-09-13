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
 
 int main()
 {
     int H[]={5,8,3,7,10,2,15,11};
     for(int i=0;i<=7;i++)
       Insert(H,i);
     return 0;
 }
