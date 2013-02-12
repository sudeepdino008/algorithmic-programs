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


inline int input( )
{
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}


int main()
{
	int t,ch,sum,i;
	int capital_count[26],small_count[26],len;
	string s;
	t=input();
	while(t--)
	{
		fill_n(capital_count,26,0);
		fill_n(small_count,26,0);
		sum=0;
		
		cin>>s;
		len=s.length();
		loop(i,0,len-1)
		{
			ch=s[i];
			if(ch>='A' && ch<='Z')
				capital_count[ch-'A']++;
			else
				small_count[ch-'a']++;
		}
		loop(i,0,25)
			sum+=ceil(small_count[i]/2.0)+ceil(capital_count[i]/2.0);
		printf("%d\n",sum);
	}
	return 0;
}
