#include<iostream>
#include<cstdlib>
#include<ctime>
#include lv(i) list[i].value
#include li(i) list[i].index
#define SWAP(a, b) (((a) ^= (b)), ((b) ^= (a)), ((a) ^= (b)))
#define llib (long long int)
typedef struct{
    int value;
    int index;
}variable;
using namespace std;
void quicksort(variable*, int ,int,int);
int main()
{

    srand(time(0));
    int n,w,end,i,j,kmin,kmax,count=0,min,max;
    cin>>n>>w;
    int array[n+1];
    variable list[w];
    for(i=1;i<=n;i++)
        cin>>array[i];
    max=array[1];
    min=array[1];
    kmax=1;
    kmin=1;
    for(i=0;i<w;i++)
        lv(i)=array[i+1];
    quicksort(list,0,w,rand()%w);
    //cout<<endl;
    for(i=2;i<=w;i++)
    {
        if(max<array[i])
            {max=array[i];kmax=i;}
        else if(min>array[i])
            {min=array[i];kmin=i;}
    }
    for(i=2;i<=n-w+1;i++)
    {
        //cout<<max<<" "<<min<<endl;
        if((lv(w-1)-lv(0))==w-1)
            count++;
        end=i+w-1;
        if(i-1==kmin && ((array[end]<lv(w-1) && array[end]>lv(0)) || array[end]>lv(w-1)))
        {
            if(array[end]>lv(w-1))
                {lv(w-1)=array[end];kmax=end;}    
            min=array[i];
            kmin=i;
            for(j=i+1;j<=end;j++)
            {
                if(min>array[j])
                {min=array[j];kmin=j;}           
            }
        }
        else if(i-1==kmax && ((array[end]<max && array[end]>min)|| array[end]<min))
        {   
            if(array[end]<min)
            {min=array[end];kmin=end;}  
            max=array[i];
            kmax=i;
            for(j=i+1;j<=end;j++)
            {
                if(max<array[j])
                {max=array[j];kmax=j;}           
            }
        } 
        
        if(array[end]>max)
            {max=array[end];kmax=end;}  
        else if(array[end]<min)
            {min=array[end];kmin=end;}  
        
    }
    //cout<<max<<" "<<min<<endl;
    if((max-min)==w-1)
        count++;
    cout<<count<<endl;
    return 0;
}
void quicksort(variable* s,int small,int large,int pivot){
    int p=0,i,k1=large;
    if(small<large){
        if(small!=pivot)
            {SWAP(s[small].value,s[pivot].value);SWAP(s[small].index,s[pivot].index);}
        for(i=small+1;i<large;i++){
            if(s[i]<s[small]){

                if(p==1){SWAP(s[k1].value,s[i].value);k1++;SWAP(s[k1].index,s[i].index)}
            }
            else{
                    if(p==0)k1=i;
                    p=1;
            }
        }
        if(small!=(k1-1))     //condition introduced since SWAP function doesn't work for same memory locations
            {SWAP(s[small].value,s[k1-1].value);SWAP(s[small].index,s[k1-1].index);}
        if(k1>=1 && (k1-1-small)>=1)
            quicksort(s,small,k1-1,small+rand()%(k1-1-small));
        if((large-k1)>=1)
            quicksort(s,k1,large,k1+rand()%(large-k1));

    }
}
