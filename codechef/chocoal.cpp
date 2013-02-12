#include <iostream>
 <cstdio>
#include <algorithm>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
#define debug(format, ...) fprintf(stderr,format,## __VA_ARGS__)
using namespace std;


inline lld input( )
{
    lld n=0;
    lld ch=getchar_unlocked();
    while( ch >= '0' && ch <= '9' )
    n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
    return n;
}

int main()
{
	lld n,k, sum, i,j,max_freq, prev_freq;
	n=input();
	k=input();
	lld array[n+1];
	loop(i,1,n)
		array[i]=input();
	sum=0;
	sort(array+1, array+n+1);
	max_freq=prev_freq=n;
	loop(i,2,n)
	{
		sum+=array[i]-array[1];
		if(sum>k)
		{
			sum-=(array[i]-array[1]);
			max_freq =prev_freq= i-1;
			break;
		}
	}
	//cout<<"####"<<sum<<" "<<max_freq<<endl;
	loop(i,2,n)
	{
		prev_freq--;
		if(prev_freq<=1)
			prev_freq=0,sum=0;
		sum-=(prev_freq+1)*(array[i]-array[i-1]);
		loop(j,i+prev_freq,n)
		{
			sum+=(array[j]-array[i]);
			if(sum>k)
			{
				sum-=(array[j]-array[i]);
				if(sum<0)
					sum=0;
				prev_freq+=(j-(i+1));
				//cout<<"......."<<sum<<" "<<i<<" "<<prev_freq<<endl;
				if(prev_freq>max_freq)
					max_freq=prev_freq;
				break;
			}
		}
		if(j>=n+1)
		{
			prev_freq=n+1-i;
			if(prev_freq>max_freq)
				max_freq=prev_freq;
		}
	}
	printf("%lld\n",max_freq);
	return 0;
}
