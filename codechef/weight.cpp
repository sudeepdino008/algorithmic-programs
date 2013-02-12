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
	lld n,t,w,i,j,k,max_e,p,sum;
	lld array[21][201][10];
	loop(i,0,20)
	{
		loop(j,0,200)
		{
			loop(k,0,9)
				array[i][j][k]=0;
		}
	}
	loop(i,0,20)
	{
		loop(j,1,9)
			array[i][0][j]=1;
	}
	loop(i,1,20)
	{
		loop(j,0,200)
		{
			loop(k,0,9)
			{
				max_e=max(k,9-k);
				loop(p,0,max_e)
					array[i][j][k]=(array[i][j][k]+((j-p)<0)?0:array[i-1][j-p][p])%mod;
			}
		}
	}
	t=input();
	while(t--)
	{
		n=input_gen();
		w=input_gen();
		sum=0;
		loop(i,0,9)
			sum=(sum+array[n][w][i])%mod;
		printf("%lld\n",sum);
	}
	return 0;
}
