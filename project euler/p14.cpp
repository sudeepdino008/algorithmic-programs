//837799

#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

lld chain(lld n)
{
	lld c=0;
	while(n!=1)
	{
		if(n%2==0)
			n/=2;
		else
			n=3*n+1;
		c++;
	}
	return c;
}

int main()
{
	lld i,max=-1,c;
	cout<<"......"<<chain(13)<<endl;
	loop(i,1,1000000)
	{
		c=chain(i);
		if(max<c)
		{
			cout<<i<<" "<<c<<endl;
			max=c;
		}
	}
	return 0;
}
