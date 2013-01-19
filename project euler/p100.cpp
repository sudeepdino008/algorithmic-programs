#include <iostream>
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;


int main()
{
	lld i,k,p,t;
	for(i=1;;i++)
	{
		if(i%10!=2 && i%10!=3 && i%10!=7)
		{
			k=i*i*8+1;
			p=sqrt(k);
			if(p*p==k)
			{
				t=1+2*i;
				if((t+p)%2==0)
					cout<<i<<" "<<((t+p)/2)<<" "<<(p-1)<<" "<<(p+1)<<endl;
				if((i+(t+p)/2)>1000000000000 || (i+(t-p)/2)>1000000000000)
					break;
			}
		}
	}
	return 0;
}
