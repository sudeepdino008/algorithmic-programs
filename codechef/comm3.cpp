#include <iostream>
#include <cstdio>
#include <cstdlib>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;




int main()
{
	lld t,n,d12,d23,d13,x1,x2,x3,y1,y2,y3;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		scanf("%lld %lld",&x1,&y1);
		scanf("%lld %lld",&x2,&y2);
		scanf("%lld %lld",&x3,&y3);
		n=n*n;
		d12=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
		d23=(x2-x3)*(x2-x3)+(y2-y3)*(y2-y3);
		d13=(x1-x3)*(x1-x3)+(y1-y3)*(y1-y3);
		if((d12<=n && d13<=n) || (d12<=n && d23<=n) ||(d13<=n && d23<=n))
			printf("yes\n");
		else
			printf("no\n");

	}
	return 0;
}
