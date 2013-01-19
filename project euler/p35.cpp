//55

#include <iostream>
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

bool ifPrime(lld n)
{
    if(n==1)
        return false;
    if(n==2)
        return true;
    lld i,sq=sqrt(n);
    for(i=2;i<=sq;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}



int main()
{

	lld i,y,m,z,n,count=0;
	loop(i,1,1000000)
	{
		if(i<10)
			y=0;
		else if(i>=10 && i<100)
			y=1;
		else if(i>=100 && i<1000)
			y=2;
		else if(i>=1000 && i<10000)
			y=3;
		else if(i>=10000 && i<100000)
			y=4;
		else if(i>=100000 && i<1000000)
			y=5;
		z=y;
		n=i;
		m=pow(10,y);
		while(ifPrime(n) && z!=0)
		{
			
			n=(n/m)+((n%m)*10);
			z--;
		}
		
		if(z==0 && ifPrime(n))
		{
			cout<<i<<endl;
			count++;
		}
	}
	cout<<" \n\n.............  "<<count<<endl;
	return 0;
}
