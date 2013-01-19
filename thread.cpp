#include <iostream>
#include <boost/thread/thread.hpp>
using namespace std;

void print1()
{
	cout<<"hello world!hey!!this is thread!\n";
}

void print2()
{
	cout<<"lol\n";
}

int main()
{
	boost::thread thrd1(&print1);
	boost::thread thrd2(&print2);
	cout<<"there!there\n";
	thrd1.join();
	thrd2.join();
	cout<<"there!there\n";
	return 0;
		
}
