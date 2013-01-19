//142857

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

bool same(lld n,lld m)
{
	vector<int> vi1,vi2;
	lld i,j,k,size,sizem;
	while(n!=0)
	{
		vi1.push_back(n%10);
		n/=10;
	}
	while(m!=0)
	{
		vi2.push_back(m%10);
		m/=10;
	}
	size=sizem=vi1.size();
	
	i=0;
	while(i<size)
	{
		k=vi1[i];
		loop(j,0,sizem-1)
		{
			if(vi2[j]==k)
				break;
		}
		if(j==sizem)
			return false;
		vi2.erase(vi2.begin()+j);
		sizem--;
		i++;
	}
	return true;
	
	
}

lld done(lld n)
{

	lld m=n,k=0;
	if(n%10==7)
	{
		n=n/10;
		while(n>=10)
		{
			k++;
			if(n%10!=6)
				return m;
			n/=10;
		}
		return (lld)(pow(10,k+2));
	}
	else 
		return m;
	
}

int main()
{
	bool f=same(125874,251748);
	cout<<done(166)<<" "<<done(167)<<" "<<done(123)<<endl;
	if(f)
		cout<<"yes!";
	lld i;
	for(i=1;;i++)
	{
		if(same(i,2*i) && same(i,3*i) && same(i,4*i) && same(i,5*i) && same(i,6*i))
		{
			printf("%lld\n",i);
			break;
		}
		i=done(i);
	}
	return 0;
}
