#include <iostream>
#include <map>
#include <cstring>
#define loop(a,s,e) for(a=s;a<=e;a++)
#define lld long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,i;
	cin>>n>>m;
	string name[n],country[n];
	map<string, int> name_freq, country_freq;
	loop(i,0,n-1)
	{
		cin>>name[i]>>country[i];
		name_freq[name[i]]=country_freq[country[i]]=0;
	}

	string nam;
	loop(i,0,m-1)
	{
		cin>>nam;
		name_freq[nam]++;
	}
	loop(i,0,n-1)
	{
			country_freq[country[i]]+=name_freq[name[i]];
	}
	int nmax=-1,cmax=-1;
	string nm="",cm="";
	loop(i,0,n-1)
	{
		if(nmax<name_freq[name[i]])
		{
			nmax=name_freq[name[i]];
			nm=name[i];
		}
		else if(nmax==name_freq[name[i]] && (nm.compare(name[i])>0 || nm.compare("")==0))
		{
			nmax=name_freq[name[i]];
			nm=name[i];
		}

		if(cmax<country_freq[country[i]])
		{
			cmax=country_freq[country[i]];
			cm=country[i];
		}
		else if(cmax==country_freq[country[i]] && (cm.compare(country[i])>0 || cm.compare("")==0))
		{
			cmax=country_freq[country[i]];
			cm=country[i];
		}

		
	}
	/*puts(cm);
	puts("\n");
	puts(nm);
	puts("\n");*/
	cout<<cm<<"\n"<<nm<<"\n";
	return 0;

}
