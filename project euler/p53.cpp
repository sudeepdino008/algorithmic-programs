//4075

#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;


lld combine(lld a, lld b)
{
	if(b<a-b)
		return combine(a,a-b);
	lld i,p=1,c=1;
	loop(i,b+1,a)
		p=(p*i)/(c++);
	return p;
	
}

int main()
{
	lld i,j,sum=0,c;
	loop(i,1,100)
	{
		loop(j,1,i/2)
		{
			c=combine(i,j);
			if(c>1000000)
				break;
				
		}
		if(j!=i/2+1)
			sum+=i-2*j+1;
	}
	cout<<"........."<<sum<<endl;
	return 0;
}
