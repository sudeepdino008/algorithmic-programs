#include <iostream>
#define ARRAY_SIZE 50
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b))) //Note that this SWAP function doesn't work for same memory locations.
using namespace std;
int s[ARRAY_SIZE];
int len;
void quicksort(int ,int);
void print();
int main()
{
    int i;
    cout<<"enter size of array:\n";
    cin>>len;
    cout<<"enter array elements:";
    for(i=0;i<len;i++)cin>>s[i];
    quicksort(0,len);
    cout<<"sorted:\n";
    for(i=0;i<len;i++)cout<<s[i]<<"\t";
    return 0;
}
void quicksort(int small,int large){

    int p=0,i,k1=large;

    if(small<large){
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

        if(k1>=1)
            quicksort(small,k1-2);
        quicksort(k1,large);

    }
}

