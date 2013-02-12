#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <climits>
#define round_int(n) floor(n+0.5)
#define round_up(n,s) round_int(n*pow(10,s))/pow(10,s) 
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;




inline int input()
{
	int t=0;
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
	setvbuf (stdout, NULL, _IOFBF, 32768);
	int a,n,k,i,prev,exp;
	a=input();
	n=input();
	k=input();
	loop(i,0,k-1)
	{
		printf("%d ",a%(n+1));
		a/=(n+1);
	}
	return 0;
}
