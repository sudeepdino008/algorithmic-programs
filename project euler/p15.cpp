//137846528820


//basically calculate 40C20

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
	cout<<combine(4,3)<<endl;
	return 0;
}
