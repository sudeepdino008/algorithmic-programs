#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdio>
#define loop(a,s,e) for(a=s;a<=e;a++)
using namespace std;

int main()
{
	int n,t,w;
	float h1,h2,p,s,y1,y2;
	scanf("%d",&t);
	loop(w,1,t)
	{
		scanf("%f %f",&p,&s);
		h1=(1.0*p+sqrt(p*p-24*s))/(12*1.0);
		h2=(1.0*p-sqrt(p*p-24*s))/(12*1.0);
		y2=(s*h2/2.0)+(h2*h2*h2*1.0)-(p*h2*h2/4.0);
		y1=(s*h1/2.0)+(h1*h1*h1*1.0)-(p*h1*h1/4.0);
		cout<<setprecision(2)<<fixed<<max(y1,y2)<<"\n";
	}
	return 0;
}
