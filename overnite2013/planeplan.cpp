#include <iostream>
#include <cstdlib>
#include <cstdio>
#define swap(k1,k2) (k1^=k2^=k1^=k2)
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
	int n,m,count=0,i,k1,k2,j,flag;
	n=input();
	m=input();
	
	loop(i,0,m-1)
	{
		k1=input();
		k2=input();
	}
	printf("%d\n",(n-m-1));
	return 0;
}
