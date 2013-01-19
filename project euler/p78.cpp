//55374

#include <iostream>
#include <cmath>
#define size 1000000
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	lld p[size],i,j,k1,k2,y=1;
	loop(i,0,size-1)
		p[i]=0;
	p[1]=p[0]=1;
	loop(i,2,size-1)
	{
		
		j=1;
		while(true)
		{
			k1=(j*(3*j-1))/2;
			k2=(j*(3*j+1))/2;
			if(k1<=i)
			{
				//cout<<"jjjj"<<k1<<endl;
				if(j%2==0)
					p[i]-=p[i-k1];
				else
					p[i]+=p[i-k1];
			}
			if(k2<=i)
			{
				//				cout<<"jjjj"<<k2<<endl;
				if(j%2==0)
					p[i]-=p[i-k2];
				else
					p[i]+=p[i-k2];
			}
			p[i]%=1000000;
			if(k1>i) 
				break;
			j++;

		}
		if(p[i]==0)
		{
			cout<<i<<" "<<p[i]<<endl;
			break;
		}
		
		
	}
	return 0;
}
