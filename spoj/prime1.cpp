#include <iostream>
#include <cmath>
using namespace std;

bool ifprime(int n)
{
	if(n==1)
		return false;
	int i,s=sqrt(n);
	for(i=2;i<=s;i++)
	{
		if(n%i==0)
			return false;
		
	}
	return true;
}

int main()
{
	int i,t,n,m,j;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>m>>n;
		for(j=m;j<=n;j++)
		{
			if(ifprime(j))
				cout<<j<<"\n";
		}
		cout<<"\n";
	}
}
