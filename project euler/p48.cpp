//9110846700


#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

lld calc(lld n)
{
	lld i,p=1;
	loop(i,1,n)
	{
		p*=n;
		p%=10000000000;
	}
	return p;
}

int main()
{
	lld i,s=0;
	loop(i,1,1000)
	{
		s+=calc(i);
		s%=10000000000;
	}
	cout<<s<<endl;
	return 0;
}
