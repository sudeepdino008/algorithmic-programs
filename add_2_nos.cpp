


#include <iostream>
#include <cstring>
#include <sstream>
#define char_to_int(c,n) n=c-'0'
using namespace std;
string add(string,string);
string itos(int);


int main()
{
    cout << add("1286","297318")<< endl;
    return 0;
}


string add(string s,string w){
     int i,n1,n2=0,n3,carry=0,j;
    string s1;
    if(s.length()<w.length()){return add(w,s);}
    s1="";
    for(i=s.length()-1,j=w.length()-1;i>=0;i--,j--){
        char_to_int(s[i],n1);
        n3=n1;
        if(j>=0){
            char_to_int(w[j],n2);
            n3=(n2+n1)%10;

        }
        if(j<0 && carry==0)
            break;
        //else if(carry==0)break;
        //ostringstream convert;
        //convert<<(n3+carry);
        s1=itos((n3+carry)%10)+s1;
        carry=(n2+n1+carry)/10;
        n2=0;
    }
    //cout<<i<<" "<<j<<endl;
    if(j<0 && i+1>0 && carry==0)s1=s.substr(0,i+1)+s1;
    if(carry==1)s1="1"+s1;

    return s1;
}
string itos(int n)
{
  ostringstream convert;
  convert<<n;
  return convert.str();
}

