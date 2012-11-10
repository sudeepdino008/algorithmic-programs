#include <iostream>
#include<cstring>
#define MAX(x,y) (((x)>(y))?(x):(y))
using namespace std;
int longest_increasing_subsequence(string);
int main()
{
    string s1;
    cin>>s1;
    cout<<"longest increasing subsequence:\t"<<longest_increasing_subsequence(s1)<<endl;
    return 0;
}
int longest_increasing_subsequence(string s1){

    int value[s1.length()+1];
    int i,maximum,j,m=0;
    for(i=1;i<=s1.length();i++){
        maximum=0;

        for(j=1;j<i;j++)
            if((int(s1.at(j-1)))<(int(s1.at(i-1))))maximum=MAX(maximum,value[j]);

        value[i]=maximum+1;
        m=MAX(value[i],m);
    }
    return m;
}
