#include <iostream>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;


inline int input( )
{
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}

int main()
{
	lld t,n;
	char* a[]={"Yes","No"};
	t=input();
	while(t--)
		n=input(),puts(a[(n&(~n+1))==n]);
	return 0;
}
