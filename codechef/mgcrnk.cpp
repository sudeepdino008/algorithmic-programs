#include <iostream>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <cstdio>
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define round(n) floor(n+0.5)
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;


inline int input()
{
	int t=0;
	char c;
	c=getchar_unlocked();
loop:
	while( (c<'0' || c>'9') && c != '-')
		c=getchar_unlocked();
	int n=0;
	if (c == '-' ) {
		c = getchar_unlocked();
		if (c >='0' && c <= '9')
			n=1;
		else {goto loop;}
	}
	while(c>='0' && c<='9')
	{
		t=(t << 3)+(t << 1)+c-'0';
		c=getchar_unlocked();
	}
	if (n==0)
		return(t);
	else {return (-t);}
}

int main()
{
	int t,n,i,j;
	int a[101][101];
	double s[101][101];
	s[1][1]=s[100][100]=0.0;
	loop(i,0,100)
		s[i][0]=s[0][i]=INT_MIN;
	t=input();
	while(t--)
	{
		//cout<<"sajsajash\n";
		n=input();
		loop(i,1,n)
		{
			loop(j,1,n)
			{			//scanf("%d",&a[i][j]);
				a[i][j]=input();}
		}
		
		
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i==1 && j==1)
					s[i][j]=a[i][j];
				else
					s[i][j]=max(s[i-1][j],s[i][j-1])+a[i][j];
				//cout<<i<<" "<<j<<" "<<s[i][j]<<endl;
			} 
		}

		if(s[n][n]<0)
			printf("Bad Judges\n");
		else
		{
			s[n][n]=round((s[n][n]/(2*n-3))*1000000)/1000000.0;
			printf("%f\n",s[n][n]);
		}
	 
	}
	return 0;
}
