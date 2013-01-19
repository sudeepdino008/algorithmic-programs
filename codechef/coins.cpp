#include <iostream>
#include <cstdio>
#include <map>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

map<int,int> coin;

lld answer(lld n)
{
	if(coin[n]!=0)
		return coin[n];
	int a = answer(n/2)+answer(n/3)+answer(n/4);
	if(a<n)
	{
		coin[n]=n;
		return coin[n];
	}
	coin[n]=a;
	return a;
}
int main()
{
	
	lld i,n,w;
	loop(w,1,10)
	{
		scanf("%lld",&n);
		printf("%lld\n",answer(n));
	}
	return 0;
}
