#include<iostream>
using namespace std;

int fibonacci(int);

int main()
{


  int n;
  cout<<"enter n\n";
  cin>>n;
  cout<<"nth fibonacci is:"<<fibonacci(n)<<endl;
  return 0;
}


int fibonacci(int n){
  //cout<<n<<endl;
  int fn,fn1;
  if (n==1)
    return 1;
  else if(n==2)
    return 1;

  else if(n%2==1){
    fn1=fibonacci((n+1)/2);
    fn=fibonacci((n-1)/2);
    return (fn*fn+fn1*fn1);
  }
  else{
    fn=fibonacci(n/2);
    fn1=fibonacci((n/2)+1);
    return (fn*(2*fn1-fn));
  }
    
  
}
