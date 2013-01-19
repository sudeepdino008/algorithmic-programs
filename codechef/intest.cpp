#include <iostream>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	lld n,k,w,t,count=0;
	scanf("%lld %lld",&n, &k);
	loop(w,1,n)
	{
		scanf("%lld",&t);
		if(t%k==0)
			count++;
	}
	printf("%lld\n",count);
	return 0;
}
