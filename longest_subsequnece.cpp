#include <iostream>
#include<cstring>
using namespace std;
int longest_subsequence(string,string);
int MIN(int ,int,int);
int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    cout<<"longest subsequence:\t"<<longest_subsequence(s1,s2);
    return 0;
}
int longest_subsequence(string s1,string s2){
    int i,j,deletion_cost,len1,len2;
    s1=" "+s1;
    s2=" "+s2;
    len1=s1.length();
    len2=s2.length();
    int D[len1][len2];
    for(i=0;i<len1;i++)D[i][0]=i;
    for(i=0;i<len2;i++)D[0][i]=i;
    for(i=1;i<len1;i++){
        for(j=1;j<len2;j++){
            deletion_cost=0;
            if(s1.at(i)!=s2.at(j))deletetion_cost=2;
            D[i][j]=MIN(D[i-1][j-1]+c,D[i-1][j]+1,D[i][j-1]+1);
        }
    }
    return D[len1-1][len2-1];
}
int MIN(int x,int y,int z){
    if(x<y){
        if(x<z)return x;
        else return z;
    }
    else if(y<z)return y;
    else return z;
}








