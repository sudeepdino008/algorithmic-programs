//number of 0 at the end of a!


#include <iostream>
using namespace std;

int main()
{
	int t, i, a, s;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a;
		s=0;
		while(a)
		{
			a/=5;
			s+=a;
		}
		cout<<s<<"\n";
	}
	return 0;
}
