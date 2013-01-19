//not solved





#include <iostream>
#define MAX_INT 1000000000
using namespace std;

typedef struct matrix{
	int row;
	int column;
}mdimension;

/*void print_paren(int backtrace[][], int i, int j)
{
	if(i==j)
		cout<<"i";
	else
	{
		cout<<"(";
		print_paren(backtrace, i, backtrace[i][j]);
		print_paren(backtrace, backtrace[i][j]+1, j);
		cout<<")";
	}
	}*/


int main()
{
	int n, i, j, k, c, minimum;
	cout<<"number of matrix: ";
	cin>>n;
	mdimension A[n+1];
	cout<<"enter size and row:\n";
	
	for(i=1;i<=n;i++)
	{
		cout<<"array "<<i<<" : ";
		cin>>A[i].row;
		cin>>A[i].column;
	}
	int cost[n+1][n+1], backtrace[n+1][n+1];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cost[i][j] = backtrace[i][j] = 0;
	}
	for(i=n-1;i>=1;i--)
	{
		for(j=i+1;j<=n;j++)
		{
			minimum = MAX_INT;
			for(k=i+1;k<=j;k++)
			{
				if(k!=j)
					c = (A[i].row)*(A[k].column)*(A[j].column);
				else
					c = (A[i].row)*(A[k].row)*(A[j].column);
				c+= cost[i][k];
				if((k+1)<=j)
					c+=cost[k+1][j];
				
				if(minimum>c)
				{
					minimum = c;
					backtrace[i][j] = k;
				}
			}
			cost[i][j]=minimum;
		}
	}
	cout<<cost[1][n]<<endl;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<cost[i][j]<<" ";
		}
		cout<<endl;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
			cout<<i<<" "<<j<<" : "<<backtrace[i][j]<<endl;
		cout<<"\n";
	}
	//print_paren(backtrace, 1, n);
	return 0;
	
}
