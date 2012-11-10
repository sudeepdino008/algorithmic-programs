#include<iostream>
#include<ctime>
#include<cmath>
#include<cstdlib>
#define swap(x,y) x^=y;y^=x;x^=y                                                    //Swapping two integers x and y
#define random (double)rand()/(double)RAND_MAX                                      //generating random double between 0 and 1
#define gain(i) (house[i].neighbour_cross-house[i].neighbour_straight)             //gain on moving to i
using namespace std;

typedef struct house
{
    double x;
    double y;
    int neighbour_cross;
    int neighbour_straight;
    int group;                            //group=1 if in 1st group else group=2
}h;

double sq_distance(int,int,h*);           //Function to calculate square of distance between house number i and house number j

int main()
{
    srand((unsigned int)time(NULL));                      
    int n1,n2,i,j,sumc,max_gain1=0,max_gain2=0,min_gain1=0,min_gain2=0,ki,kj;
    double delta;
    
    //Inputs
    cout<<"n1=";
    cin>>n1;
    cout<<"n2=";
    cin>>n2;
    cout<<"delta=";
    cin>>delta;
    
    //Filling the coordinates
    h house[n1+n2+1];
    for(i=1;i<=n1+n2;i++)
    {
        
        house[i].x=(int(random*10000))/10000.0;
        house[i].y=(int(random*1000))/1000.0;
        house[i].neighbour_cross=house[i].neighbour_straight=0;
        if(i<=n1)                                        //assigning 1 to group1(till n1)                       
            house[i].group=1;
        else
            house[i].group=2;                            //assigning 2 to group2(from n1 to n2)
    }
    
    //Printing the coordinates
    for(i=1;i<=n1+n2;i++)
    {
        if(i%4==0)
            cout<<endl;
        cout<<"("<<house[i].x<<","<<house[i].y<<") ";   
    }
    cout<<endl;
    
    //Calculating the number of neighbours( Own group and opposition group members calculated separatedly)
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
    cout<<endl;
    
    //Calculating the minimum gain among all houses    
    for(i=1;i<=n1+n2;i++)
    {
       
        if(i<=n1)                                                           
            min_gain1=(min_gain1>gain(i))?gain(i):min_gain1;
        else
            min_gain2=(min_gain2>gain(i))?gain(i):min_gain2;
            
    }
    
    //Calculating the number of crosses
    sumc=0;
    for(i=1;i<=n1;i++)
        sumc+=house[i].neighbour_cross;
    
    //max_gain1 and max_gain2 arbitrarily initialised such that their sum is >0
    max_gain1=1;
    max_gain2=1;
    
    //The main part of program
    while(max_gain1+max_gain2>0)
    {
        //Calculating the houses to be moved or whose group has to be changed
        max_gain2=min_gain2;
        for(j=n1+1;j<=(n1+n2);j++)
        {
            if(house[j].group==2 && gain(j)>max_gain2)
                {max_gain2=gain(j);kj=j;}
        }
        max_gain1=min_gain1;
        for(i=1;i<=n1;i++)
        {
            if(house[i].group==1 && gain(i)>max_gain1 && )
            {
                max_gain1=gain(i);
                ki=i;
            }
        
        }
        
        cout<<"Number of cross edges = "<<sumc<<endl;
        sumc-=(max_gain1+max_gain2);
        
        if(sumc<0 || max_gain1+max_gain2<=0)
        {
            cout<<"No more further refinement possible\n";
            break;
        }
        
        if(max_gain1+max_gain2>0)
        {
            cout<<"\t+++ Switching node "<<ki<<" to Group 2: Gain="<<max_gain1<<endl;
            cout<<"\t+++ Switching node "<<kj<<" to Group 1: Gain="<<max_gain2<<endl;
            
            house[ki].group=2;
            house[kj].group=1;
            swap(house[ki].neighbour_cross,house[ki].neighbour_straight);
            swap(house[kj].neighbour_cross,house[kj].neighbour_straight);
        }
        
    }
    
    //Printing of the assigned houses
    cout<<"Tribe 1 families get the houses:\n";
    for(i=1;i<=n1+n2;i++)
    {
        if(house[i].group==1)
            cout<<i<<" ";
    
    }
    cout<<"\nTribe 2 families get the houses:\n";
    for(i=1;i<=n1+n2;i++)
    {
        if(house[i].group==2)
            cout<<i<<" ";
    
    }
    cout<<endl;
    return 0;
}


double sq_distance(int i,int j,h* house)
{
    return (((*(house+i)).x-(*(house+j)).x)*((*(house+i)).x-(*(house+j)).x)+((*(house+i)).y-(*(house+j)).y)*((*(house+i)).y-(*(house+j)).y));
}




