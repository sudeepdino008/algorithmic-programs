//748317

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
	lld i,n,y,count=0,s=0;
	for(i=10;;i++)
	{
		n=i;
		do{
			if(ifPrime(n))
				n/=10;
			else
				break;
		}while(true && n!=0);
		if(n==0)
		{
			//cout<<i<<endl;
			n=i;
			if(n<100)
				y=100;
			else if (n>100 && n<1000)
				y=1000;
			else if(n>1000 && n<10000)
				y=10000;
			else if(n>10000 && n<100000)
				y=100000;
			else if(n>100000 && n<1000000)
				y=1000000;
			else if(n>1000000 && n<10000000)
				y=10000000;
			do
			{
				if(ifPrime(n%y))
					y/=10;
				else
					break;
			}while(true && y>=10);
			if(y<10)
			{
				cout<<i<<endl;
				count++;
				s+=i;
			}
		}
		if(count==11)
			break;
	}
	cout<<endl<<"......."<<s<<endl;
	return 0;
}
