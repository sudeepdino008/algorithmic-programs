//14541

#include <iostream>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	int ones[]={0,3,3,5,4,4,3,5,5,4}, tens[]={0,3,6,6,5,5,5,7,6,6},s=11,i;
	loop(i,1,999)
	{
		if(i>=100)
		{
			s+=7;
			if(i%10!=0)
				s+=ones[i%10]+3;     //and
			if((i%100)/10!=0)
				s+=tens[(i%100)/10]+3;
			if((i/10)%10!=0 && i%10!=0)
				s-=3;
			s+=ones[i/100];
		}
		else if(i>=10)
		{
			s+=ones[i%10]+tens[i/10];
			
		}
		else
			s+=ones[i];
	}
	cout<<s<<endl;
	return 0;
}
