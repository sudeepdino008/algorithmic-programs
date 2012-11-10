#include <iostream>
using namespace std;

void move_disk(int n,int from,int to);
int main()
{
    int n;
    cout<<"enter number of disks\n";
    cin>>n;
    move_disk(n,1,3);
    return 0;
}
void move_disk(int n,int from,int to){

    if(n==1)
        cout<<"move disk from "<<from<<" to "<<to<<endl;
    else{
        int pivot;
        if(from+to==3)pivot=3;
        else if(from+to==5)pivot=1;
        else pivot=2;
        move_disk(n-1,from,pivot);
        move_disk(1,from,to);
        move_disk(n-1,pivot,to);
    }

}
