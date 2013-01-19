#include <iostream>
#include <cmath>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	int t,n,x,L,f,time,k,w,y;
	scanf("%d",&t);
	loop(w,1,t)
	{
		time=0;
		scanf("%d",&n);
		scanf("%d %d %d",&x,&L,&f);
		time=x+L;
		loop(y,2,n)
		{
			scanf("%d %d %d",&x,&L,&f);
			if(time<=x)
				time=L+x;
			else
			{
				k=(time-x)/f;
				if((time-x)%f!=0)
					k++;
				/*k=ceil((time-x)/f);
				if(k*f!=time-x)
				k++;*/
				time=x+k*f+L;
			}
		}
		printf("%d\n",time);
	}
	return 0;
}
