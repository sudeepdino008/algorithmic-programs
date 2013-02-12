#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;

int main()
{
	int t,len,i,j,k,flag;
	string s;
	char ch;
	scanf("%d",&t);
	while(t--)
	{
		cin>>s;
		reverse(s.begin(),s.end());
				
		len=s.length();
		loop(i,0,len-4)
		{
			//cout<<"jeoo\n";
			flag=0;
			loop(j,i,i+3)
			{
				if(s[j]!='C' &&  s[j]!='H' && s[j]!='E' && s[j]!='F' && s[j]!='?')
				{
					
					flag=1;
					break;
				}
			}
			//cout<<flag<<endl;
			if(flag==1)
			{
				loop(k,i,j)
				{
					if(s[k]=='?')
						s[k]='A';
				}
			}
			else
			{
				if((s[i+3]=='C' || s[i+3]=='?') && (s[i+2]=='H' || s[i+2]=='?') && (s[i+1]=='E' || s[i+1]=='?') && (s[i]=='F' || s[i]=='?'))
				{
					s[i+3]='C';
					s[i+2]='H';
					s[i+1]='E';
					s[i]='F';
				}
			}
			//cout<<"hello\n";
			
		}
		loop(i,0,len-1)
		{
			if(s[i]=='?')
				s[i]='A';
		}
		reverse(s.begin(),s.end());
		cout<<s<<"\n";
	}
	return 0;
}
