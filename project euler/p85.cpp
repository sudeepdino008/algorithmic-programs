//2772

#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

lld compute(lld n, lld m)
{
	return (n*m*(n+1)*(m+1))/4;
}


int main()
{
	lld i,j,min=100000000,c;
	loop(i,1,100000)
	{
		loop(j,1,i)
		{
			c=compute(i,j);
			if(c>1999984)
				break;
		}
		if(c>1999984  && min>c)
		{
			min=c;
			cout<<i<<" "<<j<<" "<<(i*j)<<" "<<c<<endl;
		}
	}
	return 0;
}
