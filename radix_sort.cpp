#include <iostream>
using namespace std;

void print(int *array, int n);
void radix_sort(int *array, int *copy_array, int n);

int main()
{
	int n,i;
	cout<<"Enter array size:\n";
	cin>>n;
	int array[n];
	cout<<"Enter "<<n<<" elements.\n";
	for(i=0;i<n;i++)
		cin>>array[i];
	int copy_array[n];
	radix_sort(array, copy_array, n);
	print(array,n);
	print(copy_array,n);
	return 0;
}

void radix_sort(int *array, int *copy_array, int n)
{
	int intermediate[n], i, frequency[10]={0}, exp=1, max;
	
	//Finding the maximum element and storing a copy of array
	max=array[0];
	for(i=0;i<n;i++)
		{
		copy_array[i]=array[i];
		if(array[i]>max)
			max=array[i];
		}
	
	while(max/exp > 0)
		{
			for(i=0;i<n;i++)
				frequency[copy_array[i]/exp %10]++;
			
			for(i=1;i<10;i++)
				frequency[i]+=frequency[i-1];
			
			for(i=n-1;i>=0;i--)
				intermediate[--frequency[copy_array[i]/exp %10]] = copy_array[i];
			
			for(i=0;i<n;i++)
				copy_array[i] = intermediate[i];
			
			for(i=0;i<10;i++)
				frequency[i] = 0;

			exp*=10;
		}
	
}


void print(int *array, int n)
{
	cout<<"Array is:\n";
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
	cout<<endl<<endl;
}
