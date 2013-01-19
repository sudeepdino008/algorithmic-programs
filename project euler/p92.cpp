//8581146

#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define limit 10000000
#define lld long long int
using namespace std;

lld square(lld n)
{
	lld sum=0;
	while(n!=0)
	{
		sum+=(n%10)*(n%10);
		n/=10;
	}
	return sum;
}

int main()
{
	lld i, count=0, n;
	for(i=1;i<=limit;i++)
	{
		n = square(i);
		while(n!=89 & n!=1)
			n=square(n);
		if(n==89)
		{
			//cout<<i<<" ";
			count++;
		}
	}
	cout<<"count is:"<<count<<endl;
	return 0;
}
