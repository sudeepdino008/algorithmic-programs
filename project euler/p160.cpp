//9376
//n

#include <iostream>
#define n 10
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

lld exponentiate(lld p, lld e)
{
	if(e==0)
		return 1;
	lld t;
	t=exponentiate(p,e/2);
	if(e%2==0)
		return (t*t)%100000;
	else
		return (t*t*p)%100000;
}


int main()
{
	lld i,j,p=1;
	loop(j,1,n)
	{
		loop(i,1,n)
		{
			p*=i;
			while(p%10==0)
				p/=10;
			if(p>100000)
				p=p%100000;
		}
	}
	//p=exponentiate(p,10000000);16864
	cout<<p<<endl;
}
