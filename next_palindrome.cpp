#include <iostream>
#include<cstring>
#include<sstream>
#include<algorithm>
#define char_to_int(c,n) n=c-'0'
using namespace std;

string itos(int);
string add(string);
string next_palindrome(string);
string reverse(string);

int main()
{
  int t,i;
  string s;
  cin>>t;
  for(i=1;i<=t;i++)
    {
      cin>>s;
      cout<<next_palindrome(s)<<endl;
      }
  //cout<<add("1999999","1000")<<endl;
  return 0;
}

string add(string s){
  int i,n1,n3,carry=1,ls=s.length();
  
  string s1;
  //if(ls<lw){return add(w,s);}
  s1="";
  for(i=ls-1;carry!=0;i--){
    if(i<0)break;
    char_to_int(s[i],n1);
    n3=(n1+carry)%10;
    carry=(n1+carry)/10;
    s1=itos(n3)+s1;
    
    }
  if(carry==1)
    s1="1"+s1;
    

  return (s.substr(0,i+1)+s1);
}
string itos(int n)
{
  ostringstream convert;
  convert<<n;
  return convert.str();
}
string next_palindrome(string s)
{
  string str;
  int len=s.length(),mid=len/2-1,i,rpos=0,nr,nl;
  
  for(i=mid;i>=0;i--)
    {
      rpos=2*mid-i+1;
      if(len%2)rpos++;
      char_to_int(s[i],nl);
      char_to_int(s[rpos],nr);
      if(nr<nl)
	{
	  if(len%2)
	    return (s.substr(0,mid+2)+reverse(s.substr(0,mid+1)));
	  else
	    return (s.substr(0,mid+1)+reverse(s.substr(0,mid+1)));
	}
      else if(nr>nl)
	{
	  
	  
	  //cout<<str<<" "<<s<<" ";
	  if(len%2)
	    str=add(s.substr(0,mid+2));
	  else
	    str=add(s.substr(0,mid+1));
	  //cout<<"sdj "<<str<<" "<<endl;
	  if(len%2)
	    return (str+reverse(str.substr(0,str.length()-1)));
	  else
	    return (str+reverse(str));
                             
	      }
    }
  //cout<<"hello"<<endl;
  if(s.compare("9")==0)return "11";
  if(len%2 && mid>=0)
    str=add(s.substr(0,mid+2));
  else if(mid>=0)
    str=add(s.substr(0,mid+1));
  //cout<<str<<endl;
  if(mid<0)
    return itos(int(s[0]-'0')+1);
  if(str.length()>len/2)
    str=str+reverse(str.substr(0,str.length()-1));
  else
    str=str+reverse(str);
  return str;
}
string reverse(string s)
{
  reverse(s.begin(),s.end());
  return s;
}
