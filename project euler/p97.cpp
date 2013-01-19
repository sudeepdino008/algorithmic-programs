//6782811137

#include <iostream>
#define ten 10000000000
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

lld power(lld n)
{
	if(n==0)
		return 1;
	lld p=power(n/2);
	if(n%2==0)
		return (p*p)%ten;
	else
		return (((p*p)%ten)*2)%ten;

}

int main()
{
	cout<<(((28433*power(7830457))%ten+1)%ten)<<endl;
	return 0;
}
