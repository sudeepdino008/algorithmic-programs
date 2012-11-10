#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t,n,i,flag1,k,j,temp,min,q1,q2,point;
	bool flag;
	vector<int> v(10000);
	cin>>t;
	for(k=0;k<t;k++)
	{
		cin>>n;
		for(j=0;j<n;j++)
			cin>>v[j];
		
		flag=true;
		while(flag)
		{
			point=1;
			flag1=0;
			for(i=0;i<n-1;i++)
			{
				
				if(v[i+1]<v[i])
				{
					q1=v[i];
					q2=v[i+1];
					point=0;
					flag=true;
					temp=v[i]+v[i+1];
					if(temp%2==0 )
						v[i]=v[i+1]=temp/2;
					else
					{
						v[i]=temp/2+1;
						v[i+1]=temp-v[i];
					} 
					
					if(q1==v[i] && q2==v[i+1] && flag1==0)
					{
						//point=1;
						flag=false;
					} 
					else 
						flag1=1;
					
				}
				else if(point==1)
					flag=false;
			}
			//cout<<endl;
			//for(i=0;i<n;i++)
			//	cout<<v[i]<<" ";
		}
		min=v[0];
		for(i=1;i<n;i++)
		{
			if(min>v[i])
				min=v[i];
		}
		
		cout<<min<<endl;

	}
	return 0;
}
