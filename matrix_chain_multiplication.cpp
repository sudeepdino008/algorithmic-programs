#include <iostream>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;

typedef struct m
{
	int x11,x12,x21,x22;
}mat;


inline int input( )
{
    int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}



mat multiply(int n)
{
	mat m;
	if(n==0)
	{
		m.x11=m.x12=m.x21=m.x22=1;
		return m;
	}
	if(n==1)
	{
		m.x11=m.x12=2;
		m.x21=1;m.x22=0;
		return m;
	}
	m=multiply(n/2);
	mat p;
	p.x11=m.x11*m.x11+m.x12*m.x21;
	p.x12=m.x11*m.x12+m.x12*m.x22;
	p.x21=m.x11*m.x21+m.x21*m.x22;
	p.x22=m.x12*m.x21+m.x22*m.x22;
	if(n%2==1)
	{
		int r1,r2,r3,r4;
		r1=2*p.x11+p.x12;
		r2=2*p.x11;
		r3=2*p.x21+p.x22;
		r4=2*p.x21;
		p.x11=r1;
		p.x12=r2;
		p.x21=r3;
		p.x22=r4;
	}
	return p;
	
	
}


int main()
{
	int n=input();
	mat matrix=multiply(n);
	cout<<matrix.x11<<" "<<matrix.x12<<" "<<matrix.x21<<" "<<matrix.x22<<endl<<endl;
	cout<<3*matrix.x21+matrix.x22<<endl;
}
