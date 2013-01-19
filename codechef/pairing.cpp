#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stack>
#include <algorithm>
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
	int t,n,m,w;

	struct store{
		int index;
		bool occured;
	}occ[10000];
	struct array{
		int f1,f2;
	}arr[10000];

	t=input();
	while(t--)
	{
		n=input();
		m=input();
		stack<int> position;
		loop(w,0,m-1)
		{
			arr[w].f1=input();
			arr[w].f2=input();
			occ[w].index=w;
			occ[w].occured=false;
		}
		
		for(w=m-1;w>=0;w--)
		{
			if(occ[arr[w].f1].occured==false && occ[arr[w].f2].occured==false)
			{
				position.push(w);
				occ[arr[w].f1].occured=occ[arr[w].f2].occured=true;
			}
		}
		
		while(!position.empty())
		{
			printf("%d ",position.top());
			position.pop();
		}
		printf("\n");
	}
	return 0;
}
