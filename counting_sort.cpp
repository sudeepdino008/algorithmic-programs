
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

void counting_sort(int a[], int result[], int size);                //result stores the sorted array

int main()
{
	int i,n;
	cin>>n;
	int a[n],result[n];
	cout<<"Entries to be made from 0 to n-1 only!\n";
	for(i=0;i<n;i++)
		cin>>a[i];
	counting_sort(a,result,n);
	for(i=0;i<n;i++)
		cout<<result[i]<<" ";
	return 0;
}

//ascending order


void counting_sort(int a[], int result[], int size)
{
	int count[size],i;                                              //count is the frequency array
	memset(count,0,size*sizeof(int));
	
	for(i=0;i<size;i++)
		count[a[i]]++;
	for(i=1;i<size;i++)
		count[i]+= count[i-1];
	for(i=size-1;i>=0;i--)
		result[--count[a[i]]] = a[i];                           //[size-(count[a[i]]--)] to store in descending order           
 }
