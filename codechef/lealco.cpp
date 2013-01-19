#include <iostream>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	int t,n,m,k,array[18];
	scanf("%d",&t);
	loop(q,1,t)
	{
		scanf("%d %d %d",&n, &k, &m);
		loop(w,1,n)
			scanf("%d",&array[w]);
		max=-1;
		frequency=0;
		loop(w,1,k)
		{
			if(max<=array[w])
			{
				if(max==array[w])
					frequency++;
				else
					frequency=0;
				max=array[w];
			}
		}
	}
}
