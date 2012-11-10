#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ofstream fout("out.txt");
	ifstream fin("in.txt");
	int a,b;
	fin>>a>>b;
	cout<<a<<" "<<b<<endl;
	fin>>a>>b;
	cout<<a<<" "<<b<<endl;
	fout<<(a+b)<<endl;
	return 0;
}
