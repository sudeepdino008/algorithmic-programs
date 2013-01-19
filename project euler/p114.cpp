//16475640049

#include <iostream>
#define length 50
#define lld long long int
#define loop(a,s,e) for(a=s;a<=e;a++)
using namespace std;

lld array[length+1][1];                //[][0] for false, [][1] for true

lld count(lld n, int prev_black)
{
	if(n==0)
		return 1;
	if(array[n][prev_black]!=-1)
		return array[n][prev_black];
	
	lld sum=count(n-1,1);
	if(prev_black==1)
	{
		lld i;
		loop(i,3,n)
			sum+=count(n-i,0);
	}
	return array[n][prev_black]=sum;
	//return sum;
	
}

int main()
{
	int i;
	loop(i,1,length)
		array[i][0]=array[i][1]=-1;
	cout<<count(length,1)<<endl;
	return 0;
}
