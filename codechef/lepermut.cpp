#include <iostream>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	int t,n,w,i,j;
	bool flag;
	scanf("%d",&t);
	loop(w,1,t)
	{
		scanf("%d",&n);
		int arr[n+1];
		loop(i,1,n)
			scanf("%d",&arr[i]);
		if(n==1 || n==2)
		{
			printf("YES\n");
			continue;
		}
		flag=false;
		loop(i,1,n-2)
		{
			loop(j,i+2,n)
			{
				if(arr[i]>arr[j])
				{
					flag=true;
					break;
				}
			}
			if(flag==true)
				break;
		}
		if(flag==true)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
