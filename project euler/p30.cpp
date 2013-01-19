//answer:443839

#include <iostream>
#include <cmath>
#define limit 1000000000
#define power 5
#define lld long long int
using namespace std;

bool ifsum(lld n)
{
	lld s=0, m=n, k;
	while(n!=0)
	{
		k = n%10;
		s += pow(k, power);
		if(s>m)
			return false;
		n/=10;
	}
	if(s==m)
		return true;
	return false;
} 

int main()
{
	lld i, sum=0;
	for(i=10 ; i<=limit ; i++)
	{
		if(ifsum(i))
		{
			cout<<i<<endl;
			sum+=i;
		}
	}
	cout<<"net sum is: "<<sum<<endl;
	return 0;
}
