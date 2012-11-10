
// works for n<=1605 since the  numbers get way to large
// equivalent python program has been developed, which gives answers to all values mentioned in question(<=10000)

#include <iostream>
#include<cmath>

using namespace std;
long long int g[10000];
int main()
{
    long long int p,MIN;
    int n,i,k,value,value1;
    cin>>n;
    g[0]=0;
    value=0;

    for(i=1;i<=n;i++){
        MIN=(long long int)(2*(pow(2,62)-1)+1);
        for(k=i-1;k>=value;k--){

            if((i-k)<=64){
                p=2*g[k]+(long long int)(pow(2,i-k))-1;
            if(p<MIN){MIN=p;value1=k;}
        }}
        value=value1;
        g[i]=MIN;
    }
    cout<<g[n];
    return 0;
}
