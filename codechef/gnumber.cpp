#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
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


int main()
{
	int t, n, i, len;
	char ch;
	vector<int> v;
	t=input();
	while(t--)
	{
		
		ch=getchar_unlocked();
		while(ch>='0' && ch<='9')
			v.push_back(ch-'0'), ch=getchar_unlocked();
		
		
		
		len = v.size();
		loop(i, 1,len-1)
		{
			if(v[i]>v[i-1])
				break;
		}
		if(i==len)
		{
			printf("-1\n");
			v.clear();
			continue;
		}
		next_permutation(v.begin(), v.end());
		
		loop(i,0,len-1)
			printf("%d",v[i]);
		printf("\n");
		v.clear();
	}
	return 0;
}
