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
    while((ch >= '0' && ch <= '9') || ch==' ' || ch=='\n')
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}

int main()
{
	int t,ds,k,dt,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&ds,&dt,&d);
		k=d-ds-dt;
		if(k>=0)
			printf("%d\n",k);
		else if(dt>=ds+d)
			printf("%d\n",(dt-ds-d));
		else if(ds>=dt+d)
			printf("%d\n",(ds-dt-d));
		else
			printf("0\n");
	}
	return 0;
}
