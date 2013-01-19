//40730

#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;



bool perfect(lld n)
{
	lld fact[]={1,1,2,6,24,120,720,5040,40320,362880};
	lld c=n,s=0;
	while(c!=0)
	{
		s+=fact[c%10];
		c/=10;
	}
	return (s==n);
	
}


int main()
{
	lld i,s=0;
	loop(i,10,100000000)
	{
		if(perfect(i))
		{
			cout<<i<<" "<<endl;
			s+=i;
		}
	}
	cout<<"\nsum: "<<s<<endl;
	return 0;
}
