

//Trade off:: Assumption that no collision occurs, i.e the hash function is very good


#include <iostream>
#include <sstream>
#define PRIME 104729              //large prinme number for hashing
#define B 10              //Base of the numeral system used
using namespace std;

string int_to_string(int n);
string robin_karp(string text, string pattern);
int hash_value(int a);
int exponential(int n);

int main()
{
	string text, pattern;
	cout<<"Enter text and pattern\n";
	getline(cin, text);
	getline(cin, pattern);
	cout << "string found at: "<< robin_karp(text, pattern) << endl;
	return 0;
} 

string robin_karp(string text, string pattern)
{
	int tlen = text.length(), plen = pattern.length(), i ,phash, thash, bm;
	string s = "";             //strores the various positions of pattern matching
	if(tlen<plen)
		return "-1";

	        //calculating hash value of pattern string

	phash = 0;
	for(i=0;i<plen;i++)                         
		phash = hash_value(phash*B + pattern[i]);
   
	//calculating hash value of 1st m characters of the text
	
	thash = 0;
	for(i=0;i<plen;i++)                         
		thash = hash_value(thash*B + text[i]);

	//caclulating B^(plen-1)% in log n  time
	bm = exponential(plen-1);
	 
	for(i=1 ;i<tlen && i+plen-1<tlen ;i++)
	{
	
		if(phash==thash)
			s+=" "+int_to_string(i-1);

		thash = hash_value(thash - text[i-1]*bm);       //calculating h(i) from h(i-1)
		thash = hash_value(thash*B);
		thash = hash_value(thash+text[i+plen-1]);

	}
	cout<<endl;
	if(s.empty())
		return "-1";
	return s;

}

int hash_value(int a)            //calculates a%PRIME even if a is -ve
{
	return (a%PRIME +PRIME)%PRIME;
}


int exponential(int n)
{
	int p;
	if(n==1)
		return B;
	if (n%2)
	{
		p = exponential((n-1)/2);
		return (B*p*p)%PRIME;
	}
	else
	{
		p = exponential(n/2);
		return (p*p)%PRIME;
	}
}

string int_to_string(int n)
{
	stringstream ss;
	ss << n;
	return ss.str();
}
