#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _heap{
	int cost;
}heap;

void heapify(heap *mheap, int n, int i); 

int main()
{
	int n, i, a;
	cin>>n;
	heap mheap[n+1];
	mheap[0].cost = -1;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		mheap[i].cost = a;
		heapify(mheap, i, i);
	}

	for(i=1;i<=n;i++)
		cout<<mheap[i].cost<<" ";
	return 0;
}
void heapify(heap *mheap, int n, int i)
{
	int left, right, largest, temp;
	left = 2*i; right = 2*i+1; largest = i;
	if(left<n && mheap[left].cost < mheap[largest].cost)
		largest = left;
	if(right<n && mheap[right].cost < mheap[largest].cost)
		largest = right;
	if(largest!=i)
	{
		temp = mheap[i].cost;
		mheap[i].cost = mheap[largest].cost;
		mheap[largest].cost = temp;
		heapify(mheap, n, largest);
	}
}


