//333082500

#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

lld remainder(lld a)
{
	lld i,max,max_n,c,n,value=-1;
	max=2;
	for(n=1;n<=2000;n+=2)
	{
		if(n%2==0)
			c=2;
		else
		{
			c=(2*a*n)%(a*a);
			if(value==-1)
				value=c;
			else if(value==c)
				break;
		}
		//cout<<"..."<<c<<endl;
		if(max<c)
		{
			max=c;
			max_n=n;
		}
	}
	//cout<<a<<" "<<max<<" "<<max_n<<endl;
	return max;
}


int main()
{
	lld s=0,i;
	for(i=3;i<=1000;i++)
		s+=remainder(i);
	cout<<s<<endl;
	return 0;
}
