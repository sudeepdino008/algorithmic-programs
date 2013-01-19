//840


#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	lld a,b,c,p,count,max=-1;
	loop(p,1,999)
	{
		count=0;
		loop(a,1,p)
		{
			loop(b,1,a-1)
			{
				c=p-a-b;
				if(c<=b && (a+b)>c && (a+c)>b && (b+c)>a && a*a==(b*b+c*c))
				{
					count++;
					if(p==120)
						cout<<".........."<<a<<" "<<b<<" "<<(p-a-b)<<endl;
				}
				
			}
		}
		if(p==120)
			cout<<"120..............."<<count<<endl;
		if(max<count)
		{
			max=count;
			cout<<p<<" "<<count<<endl;
		}
	}
	return 0;
}
