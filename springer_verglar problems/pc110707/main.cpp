
//input is n_marbles \n c1 n1 \n c2 n2    with each being less than 2000000000

#include <iostream>
void print_answer();
int gcd(int a,int b);
using namespace std;
int c1,c2,n1,n2,n;
int main()
{

    cin>>n;
    while(n){
        cin>>c1>>n1;
        cin>>c2>>n2;
        print_answer();
        cin>>n;
    }
    return 0;
}
int gcd(int a,int b){
    if(a>b)return gcd(b,a);
    else if(a)return gcd(b%a,a);
    else return b;
}
void print_answer(){
    int k,x,y,x1,y1,MIN,p=1;
    k=gcd(n1,n2);
    //cout<<"\nhello\n"<<k<<endl;
    if(n%k!=0){cout<<"failed"<<endl;return;}

        for(x=0;;x++){
            //cout<<x<<endl;
            if(n-x*n1<0)p=0;
            if((n-x*n1)%n2==0)break;
        }
        if(p){
        y=(n-x*n1)/n2;
        MIN=(c1*x+c2*y);
        }

        for(x1=0;;x1++){
            //cout<<x1<<endl;
            if((n-x1*n2)<0){
                if(p==0)cout<<"failed"<<endl;
                return;
            }
            if((n-x1*n2)%n1==0)break;
        }
        y1=(n-x1*n2)/n1;

        //Messed up a little here, anyways gives correct solutions

        if(p==1){
        if(MIN<(x1*c2+y1*c1))cout<<x<<" "<<y<<endl;
        else cout<<y1<<" "<<x1<<endl;}
        else cout<<y1<<" "<<x1<<endl;

}
