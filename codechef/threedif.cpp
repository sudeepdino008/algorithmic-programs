#include <iostream>
#include <cstdio>
#define swap(x,y) x^=y^=x^=y
#define mod 1000000007
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	lld a,b,c,k;
	int q,t;
	scanf("%d",&t);
	loop(q,1,t)
	{//
		scanf("%lld %lld %lld",&a,&b,&c);
		
		if(a>b)
		{
			if(a<c)
			{
				swap(a,c);
				swap(b,c);
			}
			else if(b<c)
				swap(b,c);
		}
		else if(c>b)
			swap(a,c);
		else if(c>a)
		{swap(a,b);swap(c,b);}
		else
			swap(a,b);
		//cout<<a<<" "<<b<<" "<<c<<endl;
		if((a==1 && b==1 && c==1) || b==1)
		{
			printf("0\n");
			continue;
		}
		//cout<<a<<" "<<b<<" "<<c<<endl;
		k=((((c%mod)*((b-1)%mod))%mod)*((a-2)%mod))%mod;
		printf("%lld\n",k);
	}
	return 0;
}
