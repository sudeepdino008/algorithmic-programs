
/*soltion of a'x+b'y=1 where gcd(a',b')=1 is x=x0-b'k and y=y0-a'k
where k is arbitrary number and x0,y0 are intial guess solutions*/


#include<iostream>
#include<cmath>
#include<sstream>
#define abs(x) (x<0)?(-x):x
using namespace std;
int convert_to_int(string s);
void print_solution(int a,int b);
int gcd(int a,int b);
static int p=0;       //indicates whether a and b are swapped or not
int main()
{
    int a,b,k;
    string str;
    getline(cin,str);
    while(str.length()){
        a=convert_to_int(str.substr(0,str.find(" ")));
        b=convert_to_int(str.substr(str.find(" ")+1,str.length()));
        if(b<a){swap(a,b);p=1;}
        //cout<<a<<" "<<b<<endl;
        k=gcd(a,b);
        a/=k;b/=k;              //looking for solutions of a'x+b'y=1 where gcd(a',b')=1
        print_solution(a,b);
        cout<<k<<endl;
        getline(cin,str);
    }
    return 0;
}
int convert_to_int(string s){
    stringstream ss(s);
    int i;
    ss>>i;
    return i;
}
int gcd(int a,int b){
    if(a)return gcd(b%a,a);
    else return b;
}
void print_solution(int a,int b){
    int x,y,xd,yd,k,sum;
    // finding intitial solution(guess solution)
    for(x=1;;x--){
        if((1-a*x)%b==0)
            break;
    }
    y=(1-a*x)/b;
    //cout<<"x:"<<x<<" y:"<<y<<endl;
    xd=x;yd=y;
    sum=abs(x)+abs(y);
    //looking for values of x and y for different values of k
    for(k=1;;k++){
        xd-=b*k;
        yd-=a*k;
        if(sum>(abs(xd)+abs(yd))){
            sum=abs(xd)+abs(yd);
            x=xd;y=yd;
        }
        else break;
    }

    for(k=-1;;k--){
        xd-=b*k;
        yd-=a*k;
        if(sum>(abs(xd)+abs(yd))){
            sum=abs(xd)+abs(yd);
            x=xd;y=yd;
        }
        else break;

    }
    if(!p)
        cout<<x<<" "<<y<<" ";
    else
        cout<<y<<" "<<x<<" ";
}







