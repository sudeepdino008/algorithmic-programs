//180180


#include <iostream>
#define lld long long int
#define loop(a,s,e) for(a=s;a<=e;a++)
using namespace std;

int main()
{
	lld k,n, max=-1, nmax,count=0;
	loop(n,1,10000000)
	{
		count=0;
		//cout<<"to..............."<<n<<endl<<endl;
		loop(k,1,n)
		{	
			if((n*n)%k==0)
			{
				count++;
				//cout<<(n+k)<<" "<<((n*(n+k))/k)<<endl;
			}
		}
		if(count>max)
		{
			cout<<n<<" "<<count<<endl;
			max=count;
			nmax=n;
			if(count>1000)
				break;
		}
	}
	cout<<"max count: "<<max<<"\nvaalue of n: "<<nmax<<endl;
	return 0;
}
