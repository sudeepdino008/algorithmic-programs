#include <iostream>
#include <algorithm>
#define cti(ch) (ch-48)   //converts character to int
#define itc(n) char(n+48)    //converts int to char
using namespace std;

string reverse(string s)
{
    reverse(s.begin(), s.end());
    return s;
}

string next_palin(string s)
{
    int len = s.length(), i;
    bool ifeven = (len%2)?(false):(true);
	/*checking whether the string consistes of all 9s*/
	for(i=0;i<len;i++)
	{
		if(s[i]!='9')
			break;
	}
	if(i==len)           //if string consists of all 9s, return palindrome of form 100000.....1
	{
		s="1";
		for(i=0;i<len-1;i++)
			s+="0";
		return s+"1";
	}

    for(i=0;i<len/2;i++)
    {
        if(cti(s[0])>cti(s[len-i-1]))
        {
            if(ifeven)
                return (s.substr(0,len/2)+reverse(s.substr(0,len/2)));
            else
                return (s.substr(0,len/2+1)+reverse(s.substr(0,len/2)));
        }
    }

    int mid = len/2;
	if(ifeven)
		mid-=1;
	for(i=mid;i>=0;i--)
	{
		if(s[i]=='9')
			s[i]='0';
		else  
			break;
	}
	s[i]=itc(cti(s[i])+1);
    if(ifeven)
		return (s.substr(0,len/2)+reverse(s.substr(0,len/2)));
	else
		return (s.substr(0,len/2+1)+reverse(s.substr(0,len/2)));
    
}


int main()
{
    int t, i;
    string s;       
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>s;
        cout<<next_palin(s)<<"\n";
    }
    return 0;
}
