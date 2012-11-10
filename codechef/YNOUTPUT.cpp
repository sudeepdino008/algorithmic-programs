#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;
bool stringcompare(string,string);
int main()
{
    int n,i,j;
    cin>>n;
    string s[n],str,yn,y="YES",no="NO";
    for(i=0;i<n;i++)
    {
        str="";
        for(j=0;j<n;j++)
            {
                cin>>yn;
                if(stringcompare(yn,y))
                    str+="1";
                else
                    str+="0";
            }
        //cout<<i<<" "<<str<<endl;
        s[i]=str;
    }

    for(i=0;i<n;i++)
    {
        str=s[i];
        for(j=0;j<n;j++)
        {
            if(!((stringcompare(str,s[j]) && str[j]=='1') || (!(stringcompare(str,s[j])) && str[j]=='0')))
                break;
        }
        if(j==n)
            break;

    }
    if(j==n){
    for(i=0;i<n;i++)
    {
        if(str[i]=='0')
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }}
	else{

	for(i=0;i<n;i++)cout<<"NO"<<endl;
}	

    return 0;
}
bool stringcompare(string s1,string s2)
{
    int i,len=s1.length();
    for(i=0;i<len;i++)
        if(s1[i]!=s2[i])return false;
    return true;
}




