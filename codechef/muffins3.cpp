#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n,t,i;
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		printf("%d\n",((n>>1)+1));
	}
	return 0;
}
