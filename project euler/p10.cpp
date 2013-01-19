//142913828922


#include <iostream>37550402023
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int ifPrime(int n)
{
	if(n==1)
		return false;
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
	lld i,s=0;
	loop(i,1,2000000)
	{
		if(ifPrime(i))
			s+=i;
	}
	cout<<s<<endl;
	return 0;
}
