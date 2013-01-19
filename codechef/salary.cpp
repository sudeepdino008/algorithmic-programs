#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <algorithm>
#include <climits>
#define loop(a,s,e) for(a=s;a<=e;a++)
using namespace std;
int arr[100];


inline int input( )
{
    //int n=0;
    int ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}



int calculate(int n)
{
	int min=INT_MAX,i,s=0;
	loop(i,0,n-1)
	{
		if(arr[i]<min)
			min=arr[i];
	}
	loop(i,0,n-1)
		s+=(arr[i]-min);
	
	return s;
}

int main()
{
    //ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	int t,n,i,j;
	t=input();
	loop(i,1,t)
	{
		n=input();
		loop(j,0,n-1)
			arr[j]=input();
		printf("%d\n",calculate(n));
	}
	return 0;

}
