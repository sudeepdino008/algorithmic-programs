#include<iostream>
#include<cstdlib>
#define sp 12
#define SWAP(x,y) ((x^=y),(y^=x),(x^=y))
using namespace std;
int main(){
    int w[sp]={0,100,200,10,1,20,40,500,152,1,3,2},s[sp]={0,101,300,500,1000,30,40,901,199,2,40,1000},i,index[sp],j;
    for(i=1;i<=sp-1;i++){
        //cin>>s[i]>>w[i];
        index[i]=i;

    }
    cout<<"\nhola\n";
    for(i=1;i<=sp-1;i++){
        for(j=i+1;j<=sp-1;j++){
            if(w[i]<w[j]){
                SWAP(w[i],w[j]);
                SWAP(index[i],index[j]);
            }
        }

    }
    cout<<"weight indexes:\n";
    for(i=1;i<=sp-1;i++){cout<<index[i]<<",";index[i]=i;}
    cout<<"\n\n";
    for(i=1;i<=sp-1;i++){
        for(j=i+1;j<=sp-1;j++){
            if(s[i]<s[j]){
                SWAP(s[i],s[j]);
                SWAP(index[i],index[j]);
            }
        }

    }
    cout<<"strength indexes:\n";
    for(i=1;i<=sp-1;i++)cout<<index[i]<<",";
    return 0;
}




