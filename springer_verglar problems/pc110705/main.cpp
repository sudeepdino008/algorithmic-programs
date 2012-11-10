
//the stategy is to create a vector of primes upto 10^7 and 4 looped arrys to traverse thro'the vector
//note that input n<=10000000
#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cstring>
#include<cmath>
using namespace std;
vector<int> prime;
vector<int> p;
void generate_prime();
void find_and_print_primes(int);
int main()
{
    string str;
    int n;
    generate_prime();
    cin>>str;
    while(str.length()){
        stringstream ss(str);

        ss>>n;

        find_and_print_primes(n);
        cin>>str;
    }

    return 0;
}
void generate_prime(){
    int i,j;
    p.push_back(0);
    p.push_back(0);
    for(i=2;i<=10000000;i++)p.push_back(i);
    for(i=2;i<=10000000;i++){
        if(p[i]){
        for(j=2*i;j<=10000000;j+=i){
            p[j]=0;
        }}
    }
    j=0;
    for(i=0;i<=p.size();i++){
        if(p[i])prime.push_back(p[i]);
    }
    p.clear();
}
void find_and_print_primes(int n){
    int i,j,k,p;
    for(i=0;i<=prime.size();i++){
        if(prime[i]>=n)return;
        for(j=0;j<=prime.size();j++){
            if(prime[i]+prime[j]>=n)break;
            for(k=0;k<=prime.size();k++){
                if(prime[i]+prime[j]+prime[k]>=n)break;
                for(p=0;p<prime.size();p++){
                    if(prime[i]+prime[j]+prime[k]+prime[p]==n){
                        cout<<prime[i]<<" "<<prime[j]<<" "<<prime[k]<<" "<<prime[p]<<endl;
                        return;
                    }
                    else if(prime[i]+prime[j]+prime[k]+prime[p]>n){
                        break;
                    }
                    //cout<<prime[i]<<" "<<prime[j]<<" "<<prime[k]<<" "<<prime[p]<<endl;
                }
            }
        }
    }
    cout<<"imposiible";


}
