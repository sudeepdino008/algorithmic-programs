//21035

#include <iostream>
#include <vector>
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

bool ifPrime(lld n)
{
	if(n==2)
		return true;
	
	lld sq=sqrt(n), i;
	for(i=2;i<=sq;i++)
	{
		if(n%i==0)
			return false;
	}
	return true;
}

int main()
{
//	
	vector<int> prime;
	lld n,size,y=1,p,remainder;
	loop(n,1,300000)
	{
		if(ifPrime(n))
			prime.push_back(n);
	}
	size=prime.size();
	//cout<<prime.size()<<endl;
	loop(n,1,size)
	{
		p=prime[n-1];
		remainder = (n%2==1)?((2*n*p)%(p*p)):2;
		if(remainder>y)
		{
			cout<<n<<" "<<remainder<<" "<<prime[n-1]<<endl;
			y*=10;
		}
	}
	return 0;
}
