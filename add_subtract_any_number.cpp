#include <iostream>
#include <cstring>
#define itc(n) char(n+48)
#define cti(ch) (ch-48)
using namespace std;

string add(string s1, string s2)
{
	int len1=s1.length(), len2=s2.length();
	if(len1<len2)                                   //s1 should be of greater length than s2
		return add(s2, s1);
	string ans="";
	int carry=0, i, s;
	for(i=1;i<=len1;i++)
	{
		s = carry+cti(s1[len1-i]);

		if(i<=len2)
			s += cti(s2[len2-i]);
	   		   
		ans = itc(s%10)+ans;                        //finding the character to be added to the ans
		carry = s/10;                               //finding the carry
	}
	if(carry!=0)
		ans = itc(carry)+ans;

	return ans;
}

string subtract(string s1, string s2)
{
	int len1=s1.length(), len2=s2.length();
	int i, j, n1, n2;
	if(len1<len2)
		return "-"+subtract(s2, s1);
	else if(len1==len2)
	{
		for(i=0;i<len2;i++)
		{
			if(s1[i]<s2[i])
				return "-"+subtract(s2, s1);
			else break;
		}
	}
	string ans="";
	
	for(i=1;i<=len1;i++)
	{
		n1 = cti(s1[len1-i]);
		if(i>len2)
			break;
		n2 = cti(s2[len2-i]);
		if(n1<n2)
		{
			n1+=10;
			for(j=i+1;j<=len1;j++)
			{
				if(s1[len1-j]=='0')
					s1[len1-j]='9';
				else 
					break;
			}
			s1[len1-j] = itc(cti(s1[len1-j])-1);
		}
		ans = itc(n1-n2)+ans;
	}
	ans = s1.substr(0,len1-i+1)+ans;
	int lans = ans.length();
	for(i=0;i<lans;i++)
	{
		if(ans[i]!='0')
			break;
	}
	if(i==lans)
		return "0";
	return ans.substr(i);
}

int main()
{
	string s1,s2;    
	cin>>s1>>s2;
	cout<<"\nadded: "<<add(s1, s2)<<"\nsubtract: "<<subtract(s1, s2)<<"\n";
	return 0;
}
