
// this program uses random pivots, which gives a high probabilty of (nlog n) time complexity

#include <iostream>
#include<cstdlib>
#include<ctime>
#define ARRAY_SIZE 50
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
using namespace std;



void quicksort(int*, int ,int,int);

int main()
{
    srand(time(0));
    int i,len;
    cout<<"enter size of array:\n";
    cin>>len;
    int s[len];
    cout<<"enter array elements:";
    for(i=0;i<len;i++)cin>>s[i];
    quicksort(s,0,len,rand()%len);
    cout<<"sorted:\n";
    for(i=0;i<len;i++)cout<<s[i]<<"\t";
    return 0;
}
void quicksort(int* s,int small,int large,int pivot){
    int p=0,i,k1=large;
    if(small<large){
        if(small!=pivot)
            SWAP(s[small],s[pivot]);
        for(i=small+1;i<large;i++){
            if(s[i]<s[small]){

                if(p==1){SWAP(s[k1],s[i]);k1++;}
            }
            else{
                    if(p==0)k1=i;
                    p=1;
            }
        }
        if(small!=(k1-1))     //condition introduced since SWAP function doesn't work for same memory locations
            SWAP(s[small],s[k1-1]);
        if(k1>=1 && (k1-1-small)>=1)
            quicksort(s,small,k1-1,small+rand()%(k1-1-small));
        if((large-k1)>=1)
            quicksort(s,k1,large,k1+rand()%(large-k1));

    }
}
