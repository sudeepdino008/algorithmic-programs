//4782

#include <iostream>
#define itc(n) char(n+48)
#define cti(ch) (ch-48)
#include <cstring>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
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


int main()
{
	lld i,y=1;
	string f0="1",f1="1",fn="";
	for(i=3;fn.length()<1000;i++)
	{
		fn=add(f0,f1);
		f0=f1;
		f1=fn;
		if(fn.length()>=y)
		{
			cout<<i<<" "<<fn<<" "<<y<<endl;
			y*=10;
		}
	}
	cout<<--i<<endl;
	return 0;
}
