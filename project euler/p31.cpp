//73682
// problem of making 200 from 200,100,50,20,10,5,2,1(dynamic)

#include <iostream>
#define lld long long int
using namespace std;

lld m[201][201];


lld count(int i,int j)
{
	if(m[i][j]!=-1)
		return m[i][j];
	if(i<j)
		return 0;
	if(j==1)
		m[i][j] = count(i,2)+count(i-j,j);
	else if(j==2)
		m[i][j] = count(i,5) + count(i-j,j);
	else if(j==5)
		m[i][j] = count(i,10) + count(i-j,j);
	else if(j==10)
		m[i][j] = count(i,20) + count(i-j,j);
	else if(j==20)
		m[i][j] = count(i,50) + count(i-j,j);
	else if(j==50)
		m[i][j] = count(i,100) + count(i-j,j);
	else if(j==100)
		m[i][j] = count(i,200) + count(i-j,j);
	else
		m[i][j] = count(i-j,j);
	return m[i][j];
	
}

int main()
{
	int i,j;
	for(i=0;i<201;i++)
	{
		for(j=0;j<201;j++)
			m[i][j] = -1;
		m[i][i] = 1;
	}
	cout<<"count is: "<<count(200,1)<<endl;
}
