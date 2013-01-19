//7652413

#include <iostream>
#include <vector>
#include <algorithm>
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
	lld i,j,n,y,max=-1;
	vector<int> dig;
	dig.push_back(1);
	for(i=2;i<=9;i++)
	{
		
		do
		{
			n=0;
			y=1;
			for(j=0;j<i-1;j++)
			{
				n+=dig[j]*y;
				y*=10;
			}
					
			if(ifPrime(n))
			{
				cout<<n<<endl;
				if(max<n)
					max=n;
			}
		}while(next_permutation(dig.begin(),dig.end()));
		for(j=0;j<i;j++)
			dig[j]=(j+1);
		dig.push_back(i);
	}
	cout<<"..........."<<max<<endl;
	return 0;
}
