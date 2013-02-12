#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <climits>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#define round_int(n) floor(n+0.5)
#define round_up(n,s) round_int(n*pow(10,s))/pow(10,s) 
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define mod 1000000007
#define array_size(a) (1[&a]-a)
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;


inline lld input( )
{
    lld n=0;
    lld ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}

inline lld input_gen()
{
	lld t=0;
	char c;
	c=getchar_unlocked();
loop:
	while( (c<'0' || c>'9') && c != '-')
		c=getchar_unlocked();
	int n=0;
	if (c == '-' ) {
		c = getchar_unlocked();
		if (c >='0' && c <= '9')
			n=1;
		else {goto loop;}
	}
	while(c>='0' && c<='9')
	{
		t=(t << 3)+(t << 1)+c-'0';
		c=getchar_unlocked();
	}
	if (n==0)
		return(t);
	else {return (-t);}
}

int main()
{
	lld t,length[31],n,m,max_length,i;
	t=input();
	length[0]=0;
	length[1]=2;
	loop(i,2,30)
		length[i]=(i+1)+length[i/2]+length[i-i/2-1];

	while(t--)
	{
		n=input_gen();
		m=input_gen();
		max_length=(n*(n+3))/2;
		//cout<<length[n]<<endl;
		if(m>=length[n] && m<=max_length)
			printf("0\n");
		else if(m<length[n])
			printf("-1\n");
		else
			printf("%lld\n",(m-max_length));
	}
	return 0;
	
}
