/*
ID: sudeepd3
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout("ride.out");
	ifstream fin("ride.in");
	string a,b;
	fin >> a >>b;
	int moda=1,modb=1,i;
	for(i=0;i<int(a.length());i++)
		moda = (moda*(a[i]-64))%47;
	for(i=0;i<int(b.length());i++)
		modb = (modb*(b[i]-64))%47;
	//cout<<moda<<" "<<modb<<endl;
	if(moda==modb)
		fout<<"GO"<<endl;
	else
		fout<<"STAY"<<endl;
	return 0;
}
