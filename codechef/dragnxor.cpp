#include <iostream>
#include <cstdio>
#include <cstdlib>
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

inline int count_ones(int a, int n)
{
	int c=0;
	while(n--)
			c+=(a&(1<<n))>>n;
	return c;
}

int main()
{
	int t,n,a,b,result,ao,bo;
	t=input();
	while(t--)
	{
		n=input();
		a=input();
		b=input();
		ao=count_ones(a,n);
		bo=count_ones(b,n);
		if(ao+bo<=n)
			result=(1<<(n-ao-bo))*((1<<(ao+bo))-1);
		else
			result=(1<<(ao+bo-n))*((1<<(2*n-ao-bo))-1);
		printf("%d\n",result);
		
	}
	return 0;
}
