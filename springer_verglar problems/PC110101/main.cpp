#include <iostream>
#include<cstring>
#include<cstdlib>
#include<sstream>
#define MAX(x,y) ((x>y)?x:y)
using namespace std;
int find_max(int i,int j);
int calc(int k);
int coni(string s);
int main()
{
    string str,s1,s2;
    int i,j;
    getline(cin,str);

    while(str.length()){
        s1=str.substr(0,str.find(" "));
        s2=str.substr(str.find(" ")+1,str.length());
        i=coni(s1);
        j=coni(s2);
        cout<<find_max(i,j)<<endl;
        getline(cin,str);
        //cout<<find_max(i,j)<<endl;
    }
    //cout<<i<<" "<<j;
    return 0;
}
int find_max(int i,int j){
    int m=0,p;
    for(int k=i;k<=j;k++){
        p=calc(k);
        m=(m<p)?p:m;
    }
    return m;
}
int calc(int k){
    int c=1,k1=k;
    while(k!=1){
        if(k%2)k=3*k+1;
        else k/=2;
        c++;
    }
    //cout<<"k:"<<k1<<" c:"<<c<<endl;
    return c;
}
int coni(string s){
    stringstream ss(s);
    int i;
    ss>>i;
    return i;
}


