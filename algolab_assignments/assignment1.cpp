#include<iostream>
using namespace std;
int n,k;
int function(int arr[],int,int,int);
int main()
{
 
  cout<<"n=";
  cin>>n;
  cout<<"k=";
  cin>>k;
  int arr[n+1];
  arr[1]=1;
  cout<<"The possibilities are:\n";
  cout<<"Total number of possibilities=: "<<function(arr,1,1,0)<<endl;
}
int function(int* arr,int i,int size,int count)
{
  // IF END OF ARRAY REACHED, PRINT ARRAY
  if(size==n)
    {
      for(int j=1;j<=n;j++)cout<<arr[j]<<" ";
      cout<<endl;
      return 1;
    }

  else if(i<=k)
    {
      
      if((n-size)>(k-i))                                 //CHECKING IF DUPLICATION IS ANYMORE ALLOWED
	{
	  arr[size+1]=i;
	  count+=function(arr,i,size+1,0);
	}
      if(i+1<=k)                                         //MOVING ON WITH i 
      {
	arr[size+1]=i+1;
	count+=function(arr,i+1,size+1,0);
      }
    }
  return count;                                           //RETURNING THE VALUE OF COUNT
}
