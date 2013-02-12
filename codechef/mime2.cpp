#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <climits>
#include <map>
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
	int n,q,i,j,len;
	string a,b,s;
	map<string,string> m;
	n=input();
	q=input();
	loop(i,1,n)
	{
		cin>>a>>b;
		m[a]=b;
		
	}
	map<string,string>::iterator it;
	loop(i,1,q)
	{
		cin>>a;
		len=a.length();
		s="";
		for(j=len-1;j>=0 && a[j]!='.';j--)
			s=a[j]+s;
		it=m.find(s);
		if(j>=0 && it!=m.end())
			cout<<m[s]<<"\n";
		else
			printf("unknown\n");
	}
	return 0;
}
