#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
using namespace std;



int main()
{
	int t,n,i;
	scanf("%d",&t);
	loop(i,1,t)
	{
		scanf("%d",&n);
		printf("%d\n",(n>>1)<<1);
	}
	return 0;
}
