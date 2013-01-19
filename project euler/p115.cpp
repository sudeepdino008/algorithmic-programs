//168

#include <iostream>
#define red_length 50
#define max_array_length 1000
#define lld long long int
#define loop(a,s,e) for(a=s;a<=e;a++)
using namespace std;

lld array[max_array_length+1][1];                //[][0] for false, [][1] for true


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
		loop(i,red_length,n)
			sum+=count(n-i,0);
	}
	return array[n][prev_black]=sum;
	//return sum;
	
}

int main()
{
	
	lld i,j;
	lld c,max=-1;
	loop(i,red_length,max_array_length)
	{
		loop(j,0,max_array_length)
			array[j][0]=array[j][1]=-1;
		c = count(i,1);
		if(max<c)
		{
			max=c;
			cout<<i<<" "<<max<<endl;
			if(max>1000000)
				break;
		}
		}
	return 0;
}
