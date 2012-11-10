//modulus of difference

#include<iostream>
#include<sstream>
#include<cstring>
#define char_to_int(c) ((c)-'0')
using namespace std;
string subtract(string,string);
string itos(int);
int main()
{
  string n1,n2;
  cin>>n1>>n2;
  cout<<subtract(n1,n2)<<endl;
  return 0;
}
string subtract(string s1,string s2)
{
  int len1=s1.length(),len2=s2.length(),i,j,n1,n2,d,k;
  string result="";
  if(len1<len2)
    return subtract(s2,s1);
  else if(len1==len2)
    {
      for(i=0;i<len1;i++)
	{
	  if(char_to_int(s1[i])<char_to_int(s2[i]))
	    return subtract(s2,s1);
	}

    }
  for(i=len1-1,j=len2-1;i>=0;i--,j--)
    {
      if(j<0)break;
      n1=char_to_int(s1[i]);
      n2=char_to_int(s2[j]);
      //cout<<n1<<" "<<n2<<endl;
      if(n1>=n2)d=n1-n2;
      else
	{//cout<<"hello"<<endl;
	  d=10+n1-n2;
	  for(k=i-1;k>=0;k--)
	    {
	      if(s1[k]!='0'){s1[k]=char_to_int(s1[k])-1+'0';break;}
	       else s1[k]='9';
	      //cout<<"skjdkj "<<s1[k]<<endl;
	     
	    }
	  if(s1[0]=='0')s1=s1.substr(1,len1);

	}
      result=itos(d)+result;
      
    }
  if(j<0 && i>=0)result=s1.substr(0,i+1)+result;
  return result;
}
string itos(int n)
{
  ostringstream convert;
  convert<<n;
  return convert.str();
}
