#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
bool is_carmichael(int n);
bool is_prime(int);
int main()
{
    int n;
    cin>>n;
    while(n){
        if(is_carmichael(n))
            cout<<"is carmichael"<<endl;
        else
            cout<<"is not carmichael"<<endl;
        cin>>n;

    }
    return 0;
}
bool is_carmichael(int n){
    if(!(n%2))return false;
    int a,k,i,k1;
    for(a=2;a<=n-1;a++){
            k=a%n;
            k1=1;
            for(i=1;i<=n;i++){
                k1*=k;
                k1%=n;

            }
            //cout<<a<<" jhg:"<<k1<<endl;
            if(k1!=a)return false;
    }
    return !(is_prime(n));


}
bool is_prime(int n){
    if(n==2)return true;
    else if(n%2==0)return false;
    for(int i=2;i<=int(sqrt(n))+1;i++){
        if(n%i==0)return false;
    }
    return true;
}
