#include <iostream>
#include <cstdio>
#include <cstdlib>
#define loop(a,s,e) for(a=s;a<=e;a++)
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
	int n,c,t,w,i,s,y;
	t=input();
	loop(w,1,t)
	{
		n=input();
		c=input();
		s=0;
		loop(i,1,n)
		{
			y=input();
			s+=y;
		}
		if(s<=c)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
