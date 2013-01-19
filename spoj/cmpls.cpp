#include <iostream>
#include <vector>
using namespace std;

void cmpls(vector<int>& v, int s, int c)
{
	int i, j, sdiff;
	bool flag = true;
	for(i=0;i<s-1;i++)                //checking whether the 1st level have all same numbers
	{
		if(v[i]!=v[i+1])
		{
			flag = false;
			break;
		}
	}

	if(s==1 || flag)                  //if 1st level have all same numbers or s=1, then print v[o] c times
	{
		for(i=0;i<c;i++)
			cout<<v[0]<<" ";
		cout<<"\n";
		return;
	}

	vector< vector<int> > difference(s);
	difference[0] = v;
	for(i=1;i<s;i++)
	{
					
		for(j=0;j<s-i;j++)
			difference[i].push_back(difference[i-1][j+1]-difference[i-1][j]);
		sdiff = difference[i].size();
		for(j=0;j<sdiff-1;j++)
		{
			if(difference[i][j]!=difference[i][j+1])
				break;
		}

		if(j==sdiff-1)                //if the ith level has all equal value, then break.
			break;
		difference[i].resize(1);       //saving some space!!!
	}
	difference[0].resize(1);            //saving some more space!!!
	int level = i;
	double term, sum;                  //sum contains the kth term while term contains the mth part of kth term.
	
	for(i=s+1;i<=s+c;i++)
	{
		sum = 0;
		sum = difference[0][0];
		term = 1;
		for(j=1;j<=level;j++)
		{
			term = term*(i-j)/(j*1.0);
			sum+=term*difference[j][0];
		}
		cout<<int(sum)<<" ";
	}
	cout<<"\n";

}

int main()
{
	int i, t, s, c, j, a;
	vector<int> v;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>s>>c;
		for(j=0;j<s;j++)
		{
			cin>>a;
			v.push_back(a);
		}
		cmpls(v, s, c);
		v.resize(0);
	}
	
	return 0;
}
