#include <iostream>
#include<cstring>
using namespace std;
void print_coordinate(string,string);
int main()
{
    int t,m,n,i,j;
    string s,str;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>m>>n;
        s="";
        for(j=0;j<n;j++)s+=" ";
        for(j=1;j<=m;j++){
            cin>>str;
            str.          //convert to lowr case
            s=s+" "+str;
        }
        cin>>k;
        for(j=1;j<=k;j++){
            cin>>str;
            print_coordinate(s,str);}
    }

    return 0;
}
void print_coordinate(string s,string str){
    int ls=s.length(),lstr=str.length();
    for()

}
