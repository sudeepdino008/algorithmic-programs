#include <iostream>
#include <sstream>
using namespace std;

string int_to_string(int n);
string kmp(string text, string pattern);
void failure_array_computation(int failure[], string pattern);

int main()
{
	string text, pattern;
	getline(cin, text);
	getline(cin, pattern);
	cout<<"pattern found at: "<<kmp(text,pattern)<<endl;
	return 0;
}


string kmp(string text, string pattern)
{
	int tlen = text.length();
	int plen = pattern.length();
	int i=0,m=0;    //i relates to pattern and m+i relates to the text
	if(tlen<plen)
		return "-1";
	int failure[plen];
	failure_array_computation(failure, pattern);
	string s="";
	while (m+i<tlen)
	{
		if(text[m+i]==pattern[i])
		{
			if(i==plen-1)
				s+=" "+int_to_string(m);
			i++;
		}
		else
		{
			m=m+i-failure[i];
			if(failure[i]==-1)
				i = 0;
			else
				i = failure[i];
		}
	}
	
	if(s.empty())
		return "-1";
	return s;
}

void failure_array_computation(int failure[], string pattern)
{
	int plen = pattern.length();
	int i=2, j=0;                                      //i related to prefix and j related to suffix
	failure[0] = -1;
	failure[1] = 0;
	while(i<=plen)
	{
		if(pattern[i-1]==pattern[j])
		{
			failure[i] = failure[i-1] + 1;
			j++;
		}
		else
		{
			failure[i] = 0;
			j = 0;
		}
		i++;
	}
	for(i=0;i<plen;i++)
		cout<<failure[i]<<" ";


}


string int_to_string(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}
