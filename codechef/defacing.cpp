#include <iostream>
#include <cstdlib>
#include <cstdio>
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
	int t;
	string s,m;
	char ch;
	t=input();
	int arrmin[]={0,0,2,3,4,5,5,0,8,8};
	int arrmax[]={8,9,8,8,9,9,8,9,8,9};
	while(t--)
	{
		s=m=" ";
		ch=getchar_unlocked();
		while(ch!=' ')
			s+=ch, ch=getchar_unlocked();
		
		ch=getchar_unlocked();
		while(ch!='\n')
			m+=ch, ch=getchar_unlocked();
		
		result1=result2=m;
		ls=s.length();
		lm=m.length();
		ls--;
		lm--;
		flag=0;
		
		result1[1]=char(48+arrmin[result1[1]-48]);
		loop(i,2,lm)
			result1[i]=char(48+arrmax[result1[i]-48]);
		
		
		


		loop(i,2,ls)
		{
			if(s[i]=='0')
			{
				if(result1[i]=='0' || result1[i]=='8')
			
			}
			else if(s[i]=='1')
			{
			if(result1[i]=='0' || result1[i]=='1' || result1[i]=='3' || result1[i]=='4' || result1[i]=='7' || result1[i]=='8' || result1[i]=='9')
				
			}
			
			else if(s[i]=='2')
			{
				if(result1[i]=='2' || result1[i]=='8')
					
			}
			else if(s[i]=='3')
			{
				if(result1[i]=='3' || result1[i]=='8')
					}
			else if(s[i]=='4')
			{
				if(result1[i]=='4' || result1[i]=='8' || result1[i]=='9')
				
			}
			else if(s[i]=='5')
			{
				if(result1[i]=='5' || result1[i]=='6' || result1[i]=='8' || result1[i]=='9')
			 
			}
			else if(s[i]=='6')
			{
				if(result1[i]=='5' || result1[i]=='6' || result1[i]=='8')
				
			}
			else if(s[i]=='7')
			{
				if(result1[i]=='0' || result1[i]=='8' || result1[i]=='9' ||result1[i]=='7')
				
			}
			else if(s[i]=='8')
			{
				if(result1[i]=='8')
				
			}
			else if(s[i]=='9')
			{
				if(result1[i]=='8' || result1[i]=='9')
				
			}
			
			 
		}
		
	}
}
