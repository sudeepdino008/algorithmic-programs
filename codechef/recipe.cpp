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

inline int hcf(int a, int b)
{
	return (b)?(hcf(b,a%b)):a;
}

int main()
{
	int t,n,result,w;
	t=input();
	while(t--)
	{
		n=input();
		int arr[n+1];
		loop(w,1,n)
			arr[w]=input();
		result=hcf(arr[1],arr[2]);
		loop(w,3,n)
		{
			result=hcf(result,arr[w]);
			if(result==1)
				break;
		}
		loop(w,1,n)
			printf("%d ",arr[w]/result);
		printf("\n");
	}
	return 0;
}
