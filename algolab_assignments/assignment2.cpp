#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#define random ((double)rand()/(double)RAND_MAX)
void merge(double* input, int p, int r);
void merge_sort(double* input, int p, int r);
bool ispresent(double com,double* r,int n);
int binSearch(double target, double* list , int n);
using namespace std;
int main(){
  int n;
  srand((unsigned int)time(NULL));
  //cout<<random<<endl;
  cout<<"enter n\n";
  cin>>n;
  int i,c=0,count=0,max=0;
  double ansl,left,right,t;
  double x[n+1],y[n+1],com[2*n+2];
  for(i=0;i<n;i++)
    {
      x[i]=com[c++]=random;
      y[i]=com[c++]=random;
      if(y[i]<x[i]){t=x[i];x[i]=y[i];y[i]=t;}
      cout<<x[i]<<" "<<y[i]<<endl;
      
    }
  merge_sort(x,0,n-1);
  merge_sort(x,0,n-1);
  merge_sort(com,0,2*n-1);
  /*for(i=0;i<n;i++)cout<<x[i]<<" "<<y[i]<<endl;
    cout<<endl;*/
  //if(ispresent(x[0],x,0))cout<<"\nis present"<<endl;
  for(i=0;i<2*n;i++){
    if(binSearch(com[i],x,n)){
      count++;
      ansl=com[i];
    }
     if(binSearch(com[i],y,n)){
      if(count>max){
      max=count;
      left=ansl;
      right=com[i];
      }
      count--;
   
    }
   

  }
  cout<<"answer: "<<max<<" "<<left<<" "<<right<<endl;



  
  return 0;

}
  void merge(double* array, int p, int r)
{
    int mid = floor((p + r) / 2);
    int i1 = 0;
    int i2 = p;
    int i3 = mid + 1;

    
    double temp[r-p+1];

    
    while (i2 <= mid && i3 <= r)
        if (array[i2] <array[i3] )
            temp[i1++] = array[i2++];
        else
            temp[i1++] = array[i3++];

   
    while (i2 <= mid)
        temp[i1++] = array[i2++];

   
    while (i3 <= r)
        temp[i1++] =array[i3++];

   
    for (int i = p; i <= r; i++)
        array[i] = temp[i-p];
}

void merge_sort(double* array, int p, int r)
{
    if ( p < r )
    {
        int mid = floor((p + r) / 2);
        merge_sort(array, p, mid);
        merge_sort(array, mid + 1, r);
        merge(array, p, r);
    }
}

int binSearch(double target, double* list , int n) {

    
     int low = 0, mid, high = n-1;

     //binary search loop
     while (low <= high)
       {
	 //compute mid
	 mid = (low + high) / 2;
	 //check target against list[mid]
	 if (target < list[mid])
	   //if target is below list[mid] reset high
	   high = mid - 1;
	 else if (target > list[mid])
	   //if target is below list[mid]) reset low
	   low = high + 1;
	 else
	   //if target is found set low to exit the loop
	   low = high + 1;
       }

     //return true if target found, false if not found
     if (target == list[mid])
       return true;
     else
       return false;

 }
