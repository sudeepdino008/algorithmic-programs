#include<iostream>
#include<cstring>
//#define print_value(tf) (tf)?("YES":"NO")
using namespace std;
bool function(string);
int main()
{
    int n,i;
    string s;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s;
        if(function(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
bool function(string s)
{
    int len=s.length(),i,count;
    count=2;
    for(i=1;i<len;i++)
    {
        if(s[i-1]<=s[i])
            count+=s[i]-s[i-1]+1;
        else
            count+=26-s[i-1]+s[i]+1;
        if(count>(11*len))
            return false;

    }
    return true;
}
