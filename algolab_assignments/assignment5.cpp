#include<iostream>
#include<cstdlib>
#include<sstream>
/*macros for Swap and absolute value*/
#define SWAP(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))
#define abs(x) ((x)>0)?(x):(-1*(x))

using namespace std;

typedef struct h
{
	long long int a,b,s;
}h;

string str;                                                                     //string to store the ways of representation
int frequency(h *heap, int, int);                                            //finds frequeny using recursion
void heapify(h *heap,long long int B);                                          //heapifying the given min heap
//void print(h *heap,long long int B);
int delete_and_modify(h *heap, int i,long long int B, long long int delem);    //deletes and inserts elements simultaneously
string itos(int n);                                                                 //converts integer to string

int main()
{
	int i,count,present_heap_size,p,c,previous_count=0;
	long long int B;
	cout<<"Enter bound B:  ";
	cin>>B;
	h heap[B+1];
	for(i=1;i<=B;i++)
	{
		heap[i].a=i;
		heap[i].b=-1*(i-1);
		heap[i].s=3*i*i-3*i+1;
	}
	
	present_heap_size=B;
	c=1;
	while(present_heap_size>=1)
	{  
	    str="";
        count=frequency(heap,1,B);
        if(count>previous_count)		
        {
            previous_count=count;
            cout<<"CT("<<(c++)<<") :"<<heap[1].s<<endl;
            cout<<str<<endl;
        
        }
        p=delete_and_modify(heap,1,B,heap[1].s);
        
        present_heap_size-=p;                                    //reducing the number of heap elements by the number of elements deleted
        heapify(heap,B);
        
	}
	return 0;
}


void heapify(h *heap, long long int B)                      //heapify taking O(n) time.
{

	
    int j=1;
	while(j<=B)
	{
		if(2*j<=B && heap[j].s>heap[2*j].s)
		{
			
			SWAP(heap[j].s,heap[2*j].s);
			SWAP(heap[j].a,heap[2*j].a);
			SWAP(heap[j].b,heap[2*j].b);
		}
		if(2*j+1<=B && heap[j].s>heap[2*j+1].s)
		{
			//cout<<"\nhello2\n";
			SWAP(heap[j].s,heap[2*j+1].s);
			SWAP(heap[j].a,heap[2*j+1].a);
			SWAP(heap[j].b,heap[2*j+1].b);
		}
		j++;
	}
	//cout<<"reduce:"<<reduce<<endl;

}

int delete_and_modify(h *heap, int i,long long int B, long long int delem)            //return count, the number of elements deleted
{
    int count=0;
    if(heap[i].s>delem)                                              
        return 0;
    if(heap[i].s==delem)
    {
        (heap[i].b)++;
        if(heap[i].a<heap[i].b)
        {
            //deleting the element(the element will push towards the end of the heap after the heapify).
            heap[i].a=heap[i].b=-1;                                     
            heap[i].s=3*B*B*B;
            count++;
        }
        else
            heap[i].s=heap[i].a*heap[i].a*heap[i].a+heap[i].b*heap[i].b*heap[i].b;
        
    }
    if(2*i<B)
    {
    count+=delete_and_modify(heap,2*i,B,delem);
    count+=delete_and_modify(heap,2*i+1,B,delem);
    }
    else if(2*i==B)
        count+=delete_and_modify(heap,2*i,B,delem);
    else
        return 0;
    return count;
}
int frequency(h *heap, int i, int B)                                         //calculating frequency in approx. O(1) time.
{
    int count=0;
    if(i>B || heap[i].s!=heap[1].s)
        return 0;
    else
    {
        str+="\t:("+itos(heap[i].a)+")^3+("+itos(heap[i].b)+")^3\n";
        count++;
        count+=(frequency(heap,2*i,B)+frequency(heap,2*i+1,B));
        return count;
    }
    
}
string itos(int n)
{
    ostringstream convert;      
    convert<<n;
    return convert.str();
}










