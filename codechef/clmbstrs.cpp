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
#define mod 1000000007
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;


inline int input( )
{
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}

inline int input_sep()
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

inline int count1(int v)
{
	v = v - ((v >> 1) & 0x55555555);                    // reuse input as temporary
	v = (v & 0x33333333) + ((v >> 2) & 0x33333333);     // temp
	return (((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24); // count

}


lld fibonacci(lld n)
{
    unsigned long long ans[2][2],fibonacci[2][2]={{1,1},{1,0}},result[2][2]={{1,0},{0,1}};
    while(n)
    {
        if(n%2==1)
        {
            memset(ans,0,sizeof(ans));
                for(int i=0;i<2;i++)
                    for(int j=0;j<2;j++)
                        for(int k=0;k<2;k++)
                            ans[i][j]=(ans[i][j]+result[i][k]*fibonacci[k][j])%mod;
                for(int i=0;i<2;i++)
                     for(int j=0;j<2;j++)
                        result[i][j]=ans[i][j]%mod;
        }
        memset(ans,0,sizeof(ans));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    ans[i][j]=(ans[i][j]+fibonacci[i][k]*fibonacci[k][j])%mod;
		for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                fibonacci[i][j]=ans[i][j];
		n/=2;
    }
    return result[0][1];
}

int main()
{
	lld t,n,g,sum,i;
	/*loop(i,1,10)
	  cout<<i<<" "<<fibonacci(i)<<endl;*/

	t=input();
	while(t--)
	{
		n=input_sep();
		g=input_sep();
		
				
		if(count1(fibonacci(n+1))==g)
			printf("CORRECT\n");
		else
			printf("INCORRECT\n");
	}

	return 0;
}
