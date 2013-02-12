#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <climits>
#define round_int(n) floor(n+0.5)
#define round_up(n,s) round_int(n*pow(10,s))/pow(10,s) 
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;


inline lld input( )
{
    lld n=0;
    lld ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}

inline lld combine(lld n)
{
	lld i,p=1;
	for(i=2*n;i>=n+1;i--)
		p=((p*i)/(2*n+1-i));
	
	return (p/(n+1))%10000;
}

int main()
{
	lld t,n;
	t=input();
	while(t--)
	{
		n=input();
		printf("%lld\n",combine(n-1));
	}
	return 0;
}
