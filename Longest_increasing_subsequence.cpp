#include<iostream>
#include<vector>
#include<algorithm>
#define MAX(x,y) (((x)>(y))?(x):(y))
using namespace std;
int n;
int longest_increasing_subsequence(vector<int>&, vector<int>&);
int main()
{
  int i,a;
  vector<int> v,vs;
  cout<<"enter n: ";
  cin>>n;
  v.push_back(0);
  vs.push_back(0);
  cout<<"enter n values:\n";
  for(i=0;i<n;i++)
    {
      cin>>a;
      v.push_back(a);
    }
  //cout<<"hello1\n";
  vs=v;
  //cout<<"hello2\n";
  sort(vs.begin(),vs.end());
  //cout<<"hello3\n";
  cout<<"longest_increasing subsequence is: "<<longest_increasing_subsequence(v,vs)<<endl;
  return 0;
}
int longest_increasing_subsequence(vector<int>& v,vector<int>& vs)
{
  vector<int> s;
  int a[n+1][n+1],i,j,max=0;
  for(i=0;i<=n;i++)
    {
      a[i][0]=0;
      a[0][i]=0;
    }
  //cout<<"hello1\n";
  for(i=1;i<=n;i++)
    {
      for(j=1;j<=n;j++)
	  {
		  //a[i][j]=MAX(MAX(a[i-1][j-1],a[i][j-1]),a[i-1][j]);
		  a[i][j]=MAX(a[i-1][j],a[i][j-1]);
		  if(v[j]==vs[i])
			  a[i][j]=a[i-1][j-1]+1;
		  if(a[i][j]>max)
			  max=a[i][j]; 
	  }
    }
  i=j=n;
  while(i>=1 && j>=1)
  {
	  if(v[j]==vs[i])
	  {
		  s.push_back(v[j]);
		  i--;
		  j--;
	  }
	  else if(a[i-1][j]>a[i][j-1])
		  i--;
	  else
		  j--;
  }
  /*for(i=0;i<=n;i++)
    {
      for(j=0;j<=n;j++)
	cout<<a[i][j]<<" ";
      cout<<endl;
      }*/
  int len=s.size();
  for(i=len-1;i>=0;i--)
	  cout<<s[i]<<" ";
  cout<<endl;
  //cout<<"hello2\n";
  return a[n][n];
}
