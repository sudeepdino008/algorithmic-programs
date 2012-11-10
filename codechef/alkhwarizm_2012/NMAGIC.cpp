#include<iostream>
//#include<cstring>
using namespace std;

int main()
{
	int t,i,j,len;
	string s,k;
	cin>>t;
	for(i=0;i<t;i++)
	{
		k="";
		cin>>s;
		len=s.length();
		for(j=len-1;j>=0;j--)
		{
			if(s[j]=='4')
				break;
			k+="4";
		}
		if(j==-1)
			cout<<k+"4"<<endl;
		else
			cout<<(s.substr(0,j)+"7"+k)<<endl;
	}
	return 0;
}
