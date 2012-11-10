#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#define swap(x,y) x^=y;y^=x;x^=y
#define random (double)rand()/(double)RAND_MAX
#define gain(i) (house[i].neighbour_cross-house[i].neighbour_straight)     //gain on moving to i
using namespace std;

typedef struct house
{
    double x;
    double y;
    int neighbour_cross;
    int neighbour_straight;
    int group;                            //group=1 if in 1st group else group=2
}h;

double sq_distance(int,int,h*);

int main()
{
    srand((unsigned int)time(NULL));
    int n1,n2,i,j,ki,kj,sumc,max,maxx,maxy,p;
    double delta;
    cout<<"n1=";
    cin>>n1;
    cout<<"n2=";
    cin>>n2;
    cout<<"delta=";
    cin>>delta;
    h house[n1+n2+1];
    for(i=1;i<=n1+n2;i++)
    {
        house[i].x=int((random*10000))/10000.0;
        house[i].y=int((random*10000))/10000.0;
        house[i].neighbour_cross=house[i].neighbour_straight=0;
        if(i<=n1)                                        //assigning 1 to group1(till n1)                       
            house[i].group=1;
        else
            house[i].group=2;                            //assigning 2 to group2(from n1 to n2)
    }
    cout<<"Houses are located at:";
    for(i=1;i<=n1+n2;i++)
    {
        if(i%4==0)
            cout<<endl;
        cout<<"("<<house[i].x<<","<<house[i].y<<") ";   
    }
    cout<<endl;
    for(i=1;i<n1+n2;i++)
    {
        for(j=i+1;j<=n1+n2;j++)
        {
            if(sq_distance(i,j,house)<(delta*delta))
            {   
                if(house[i].group!=house[j].group)
                {
                    (house[i].neighbour_cross)++;
                    (house[j].neighbour_cross)++;
                   
                }
                else
                {
                    (house[i].neighbour_straight)++;
                    (house[j].neighbour_straight)++;
                }
            }
        }
    }
    sumc=0;
    for(i=1;i<=n1;i++)
        sumc+=house[i].neighbour_cross;
    maxx=maxy=1;
    p=0;
    while(maxx+maxy>0)
    {
        maxx=0;
        for(i=1;i<=n1;i++)
        {
            max=0;
            if(house[i].group==1)
            {
            for(j=n1+1;j<=n1+n2;j++)
            {
                if(sq_distance(i,j,house)>=(delta*delta) && house[j].group==2 && max<=gain(j))
                {
                    max=gain(j);
                    kj=j;
                }
            }
            if(max>=maxx)
            {   
                maxx=max;
                ki=i;
            }
        }}

        cout<<"Number of cross edges="<<sumc<<endl;
        if(p==1)
        {
            if(maxx==0 && maxy==0)
            {
                cout<<"\t+++ No further refinement possible"<<endl;
                break;
            }
        }
        if(maxx>=0)
        {
            cout<<"\t+++ Switching node "<<ki<<" to part 2: Gain= "<<maxx<<endl;
            swap(house[kj].neighbour_cross,house[kj].neighbour_straight);
            house[kj].group=1;
        }
        maxy=0;
        for(j=n1+1;j<=n1+n2;j++)
        {
            max=0;
            if(house[j].group==2)
            {
                for(i=1;i<=n1;i++)
                {
                    if(sq_distance(i,j,house)>=(delta*delta) && house[i].group==1 && max<=gain(i))
                    {
                        max=gain(i);
                        ki=i;
                    }
                }
                if(max>=maxy)
                {   
                    maxy=max;
                    kj=j;
                }
            }       
        }
        if(maxy>=0 && house[ki].group==1)
        {
            cout<<"\t+++ Switching node "<<kj<<" to part 2: Gain= "<<maxy<<endl;
            swap(house[ki].neighbour_cross,house[ki].neighbour_straight);
            house[ki].group=2;
        }
        sumc-=(maxx+maxy);
        p=1;
       
    }
    cout<<"Tribe 1 families gets the houses"<<endl;
    for(i=1;i<=n1+n2;i++)
    {
        if(house[i].group==1)
            cout<<i<<" ";
    }
    cout<<"\Total number of houses="<<n1;
    cout<<"\n\nTribe 2 families gets the houses"<<endl;
    for(i=1;i<=n1+n2;i++)
    {
        if(house[i].group==2)
            cout<<i<<" ";
    }
    cout<<"\Total number of houses="<<n2<<endl;
    return 0;
}


double sq_distance(int i,int j,h* house)
{
    return (((*(house+i)).x-(*(house+j)).x)*((*(house+i)).x-(*(house+j)).x)+((*(house+i)).y-(*(house+j)).y)*((*(house+i)).y-(*(house+j)).y));
}




