#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;



int main()
{
	lld t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		if((n-1)%4!=0)
			printf("BOB\n");
		else 
			printf("ALICE\n");
			
	}
	return 0;
}
