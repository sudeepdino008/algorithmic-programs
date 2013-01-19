#include <iostream>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int next(int n)
{
	n+=(n==0);
	n--;
	n|=n>>1;
	n|=n>>2;
	n|=n>>4;
	n|=n>>8;
	n|=n>>16;
	n|=n>>32;
	n++;
	return n;
}

int main()
{
	int t,n,y,m,k,i;
	scanf("%d",&t);
	loop(i,1,t)
	{
		scanf("%d",&n);
		m=n;
		k=0;
		while(m!=0)
		{
			k++;
			y=next(m);
			y=(y==m)?y:y>>1;
			y=(y>2048)?2048:y;
			m-=y;
			
		}
		printf("%d\n",k);
	}
	return 0;
}
