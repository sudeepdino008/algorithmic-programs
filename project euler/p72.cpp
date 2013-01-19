//303963552391


#include <iostream>
#include <vector>
#include <cmath>
#define limit 1000000
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

vector<lld> prime;

lld common(lld n)
{
	lld i=0,p=n,k;
	while(n!=1)
	{
		
		if(n%prime[i]==0)
		{
			do
			{
				n/=prime[i];
			}while(n%prime[i]==0);
			p/=prime[i];
			p*=(prime[i]-1);
			
		}
		i++;
	}
	return p;
}


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
	lld i,sum=0,c;

	loop(i,1,limit)
	{
		if(ifPrime(i))
			prime.push_back(i);
	}
	cout<<"done!!!!"<<endl;
	//cout<<endl<<endl<<common(11)<<" "<<common(36)<<" \n\n";
	
	loop(i,2,limit)
	{
		c=common(i);
		//cout<<i<<"............ "<<c<<endl;
		sum+=c;
	}
	
	cout<<"\n\n........sum="<<sum<<endl;
	return 0;
}
