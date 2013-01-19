#include <iostream>
#include <cstdio>
#include <cstdlib>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;

inline lld input()
{
	lld n=0;
	char ch=getchar_unlocked();
	while(ch>='0' && ch<='9')
		n=(n<<3)+(n<<1)+ch-'0', ch=getchar_unlocked();
	return n;
}

int main()
{
	int i;
	loop(i,1,45)
		cout<<i<<" ";
	cout<<endl;
	for(i=2;i<=45;i+=2)
		cout<<i<<" ";
	for(i=1;i<=45;i+=2)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}
