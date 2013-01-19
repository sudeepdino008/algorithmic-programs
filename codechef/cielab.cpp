#include <iostream>
#include <cstdlib>
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
	int a,b,k;
	a=input();
	b=input();
	k=a-b;
	k=(k%10!=0)?(k-1):(k+1);
	printf("%d\n",(k)?k:2);
	return 0;
}
