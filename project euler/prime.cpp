#include <iostream>
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int ifPrime(int n)
{
    if(n==2)
        return true;
    int i,sq=sqrt(n);
    for(i=2;i<=sq;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

int main()
{
	lld i;
	for(i=2;i<=10000;i++)
	{
		if(ifPrime(i))
			cout<<i<<",";
	}
	return 0;
}
