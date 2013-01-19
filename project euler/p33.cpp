//100 (19/95,49/98, 16/64, 26/65)

#include <iostream>
#define loop(a,start,end) for(a=start;a<=end;a++)
using namespace std;

int main()
{
	int a,b,d;
	loop(a,1,9)
	{
		loop(b,1,9)
		{
			loop(d,1,9)
			{
				if(10*a*b==d*(9*a+b))
					cout<<a<<b<<"/"<<b<<d<<endl;
			}
		}
	}
	return 0;
}
