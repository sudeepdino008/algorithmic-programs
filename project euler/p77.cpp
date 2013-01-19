//71

#include <iostream>
#include <vector>
#include <cmath>
#define psize 1229
#define lprime 9973
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

vector<lld> prime;
lld array[lprime][psize-1],n;


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

lld function(lld i, lld j)
{
	if(i<prime[j] || (n==i && i==prime[j]))
		return 0;
	if(i==prime[j])
		return 1;
	if(array[i][j]!=-1)
		return array[i][j];
	array[i][j]=function(i,j+1)+function(i-prime[j],j);
	return array[i][j];
}

int main()
{
	lld i,j;
	loop(i,1,10000)
	{
		if(ifPrime(i))
			prime.push_back(i);
	}
	
	

	lld k,max=-1;
	loop(i,0,1228)
	{
		loop(j,0,psize-1)
		{
			loop(k,0,psize-1)
				array[j][k]=-1;
		}
		n=i;
		k=function(n,0);
		cout<<".........."<<n<<" "<<k<<endl;
		if(max<k)
		{
			max=k;
		
		}
	}
	cout<<max<<endl;


	return 0;
}
