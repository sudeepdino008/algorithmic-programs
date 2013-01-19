#include <iostream>
#define forall(i,start,end) for(i=start;i<end;i++)
using namespace std;

string rpn(string s)
{
	int len=s.length(), i, j, oindex, k;
	string str;
	forall(i,0,len)
	{
		if(s[i]=='(')
			oindex = i;
		if(s[i]==')')
		{
			forall(j,oindex+1,i)
			{
				if(s[j]=='+' || s[j]=='-'|| s[j]=='*' || s[j]=='^' || s[j]=='/')
				{

					if(s[j+1]!='(' && s[j+1]!=')' && s[j+1]!='+' && s[j+1] !='-' && s[j+1]!='*' && s[j+1]!='^' && s[j+1]!='/')
					{
						str="";
						forall(k,0,oindex)
							str+=s[k];
						forall(k,oindex+1,j)
							str+=s[k];
						forall(k,j+1,i)
							str+=s[k];
						str+=s[j];

						forall(k,i+1,len)
							str+=s[k];

						return rpn(str);
					}
				}
			}
		}
		
	}	
	return s;
}


int main()
{
	int t, i;
	string s;
	cin>>t;
	forall(i,0,t)
	{
		cin>>s;
		cout<<rpn(s)<<"\n";
	}
	return 0;
}


