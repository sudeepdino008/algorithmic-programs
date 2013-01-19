//cutting rods of length n with each length from 1,2,3,....n having different prices such that the total cost is maxmised


#include <iostream>
using namespace std;

void rod_cutting( int n, int *cost, int *solution, int *rod_length)
{
	int max, i, j;
	solution[0] = 0;
	for(i=1;i<=n;i++)
	{
		max = -1;
		for(j=1;j<=i;j++)
		{
			if(max < cost[j]+solution[i-j])
			{
				max = cost[j]+solution[i-j];
				rod_length[i] = j;
			}
		}
		solution[i] = max;
	}
}

void print_rod_length(int n, int *rod_length)
{
	while(n>0)
	{
		cout<<rod_length[n]<<" ";
		n = n-rod_length[n];
	}
	cout<<"\n";
}

int main()
{
	int n, i;
	cout<<"length of rod :";
	cin>>n;
	int cost[n+1], solution[n+1], rod_length[n+1];
	cout<<"Enter cost:\n";
	cost[0] = 0;
	for(i=0;i<n;i++)
	{
		cout<<(i+1)<<": ";
		cin>>cost[i+1];
	}
	rod_cutting(n, cost, solution, rod_length);
	cout<<"max cost is : "<<solution[n]<<endl;
	print_rod_length(n, rod_length);
	return 0;
}
