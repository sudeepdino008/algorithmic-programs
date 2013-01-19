//76576500


//2*3*5*7*11*13*17*19=223092870

#include <iostream>
#include <vector>
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

vector<int> prime;


lld n_factor(lld n)
{
	lld limit=sqrt(n),i,factor=1,c,max=-1;
	loop(i,0,limit)
	{
		if(n%prime[i]==0)
		{
			c=0;
			while(n%prime[i]==0)
			{
				c++;
				n/=prime[i];
			}
			factor*=(c+1);
		}

	}
	return factor;
}



int main()
{
	vector<int> v;
	v.push_back(-1);
	v.push_back(-1);

	lld i, sq=sqrt(10000000000),j;
	loop(i,2,sq)
		v.push_back(i);
	loop(i,0,sq)
	{
		if(v[i]!=-1)
		{
			for(j=2*i;j<=sq;j+=i)
				v[j]=-1;
		}
	}
	loop(i,1,sq)
	{
		if(v[i]!=-1)
			prime.push_back(v[i]);
	}
	lld s=prime.size(),c,max=-1;
	for(i=1;;i++)
	{
		c=n_factor((i*(i+1))/2);
		if(max<c)
		{
			cout<<((i*(i+1))/2)<<" "<<c<<endl;
			max=c;
			if(max>500)
				break;
		}
		
	}
	return 0;
}
