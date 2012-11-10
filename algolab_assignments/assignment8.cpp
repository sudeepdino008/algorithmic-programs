#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>                        //required for the constants INT_MAX and INT_MIN
#define MAX(x,y) ((x)>(y))?(x):(y)
#define MAX_m 10000
#define random (int(((double)rand()*100000 / (double)RAND_MAX)))/100000.0
using namespace std;

typedef struct points{				//stores the coordinates of a single point
  double x;
  double y;
}point;

typedef struct hash_table{                  //data structure for hash table
	double x,y;
	struct hash_table *next;
}hash_table;

hash_table* H[MAX_m][MAX_m];       //hash table of size MAX_m

void allocate(point* P,int n);             //fills P[] with random coordinates
void create_hash_table(int n, int m, point* P);          //creates and fills hash tables with values
void push_element(int xh, int yh, double x, double y);      //push element required for inserting elements in hash tables
void statistics(int n, int m);                             // for printing the different statistics i.e. frequecny
int distance(point* P, int x, int y, double xitem, double yitem, int n);    //finds and return index of the nearest point from(xitem,yitem) in the (x,y) cell
void search(point* P,int n, int m);   //responsible for initial and correct searching

int main()
{
  srand((unsigned int)time(NULL));
  int n,m;
  cout<<"n = ";
  cin>>n;
  m = ceil(sqrt(n));
  point P[n];
  allocate(P,n);                //allocating the points randomly in P array
  //print(P,n);

  create_hash_table(n,m,P);
  statistics(n, m);
  search(P, n, m);
  return 0;
}

void search(point* P,int n, int m)
{

	double xitem = random, yitem = random, min_dist_sq = INT_MAX, delta = 0.00001;
	int xi = floor(xitem*m), yi = floor(yitem*m), x, y;                  //finding the index of the search item in the hash table
	int r=1;                                             //r represents the maximum distance from a point(circle of radius r)
	int required_index = -1,index;
	bool flag = false;
	//cout<<xi<<" "<<yi<<endl;
	cout<<"+++ Searching for point closest to: ("<<xitem<<", "<<yitem<<")\n";
	index = distance(P, xi, yi, xitem, yitem, n);
	if(index!=-1)
		required_index = index;

	if(required_index!=-1)
	{
		cout<<"\t\tInitial Search Gives: ("<<P[required_index].x<<", "<<P[required_index].y<<")\n";
		flag = true;
		required_index = -1;
	}
	min_dist_sq = INT_MAX;
	
	while(required_index == -1)
	{
		
		//keeping x constant at xi+r while varying y from yi-r to yi+r
		x = xi+r;
		y = MAX(yi-r, 0);
		min_dist_sq = double(INT_MAX);
		while(x<m && y<=yi+r)
		{

			index = distance(P, x, y, xitem, yitem, n);
			if(index!=-1 && (min_dist_sq-(P[index].x-xitem)*(P[index].x-xitem)-(P[index].y-yitem)*(P[index].y-yitem))>delta)
			{
				min_dist_sq = ((P[index].x-xitem)*(P[index].x-xitem)+(P[index].y-yitem)*(P[index].y-yitem));
				required_index = index;
			}
			y++;
		}
	
		//keeping x constant at xi-r while varying y from yi-r to yi+r
		x = xi-r;
		y = MAX(yi-r, 0);
		while(y<=yi+r && x>=0)
		{
			index = distance(P, x, y, xitem, yitem, n);
			if(index!=-1 && (min_dist_sq-(P[index].x-xitem)*(P[index].x-xitem)-(P[index].y-yitem)*(P[index].y-yitem))>delta)
			{
				min_dist_sq = ((P[index].x-xitem)*(P[index].x-xitem)+(P[index].y-yitem)*(P[index].y-yitem));
				required_index = index;
			}
			y++;
		}
	
		//keeping y constant at yi+r while varying x from xi-r to xi+r
		y = yi+r;
		x = MAX(xi-r, 0);
		while(x<=xi+r && y<m)
		{
			index = distance(P, x, y, xitem, yitem, n);
			if(index!=-1 && (min_dist_sq-(P[index].x-xitem)*(P[index].x-xitem)-(P[index].y-yitem)*(P[index].y-yitem))>delta)
			{
				min_dist_sq = ((P[index].x-xitem)*(P[index].x-xitem)+(P[index].y-yitem)*(P[index].y-yitem));
				required_index = index;
			}
			x++;
		}
	
		//keeping y constant at yi-r while varying x from xi-r to xi+r
		y = yi-r;
		x = MAX(xi-r, 0);
		while(x<=xi+r && y>=0)
		{
			index = distance(P, x, y, xitem, yitem, n);
			if(index!=-1 && (min_dist_sq-(P[index].x-xitem)*(P[index].x-xitem)-(P[index].y-yitem)*(P[index].y-yitem))>delta)
			{
				min_dist_sq = ((P[index].x-xitem)*(P[index].x-xitem)+(P[index].y-yitem)*(P[index].y-yitem));
				required_index = index;
			}
			x++;
		}
		r++;
	}
	if(!flag)
		cout<<"\t\tInitial Search Gives : ("<<P[required_index].x<<","<<P[required_index].y<<")\n";	
	cout<<"\t\tThe correct result is: ("<<P[required_index].x<<" ,"<<P[required_index].y<<")\n";
		
   
}

int distance(point* P, int x, int y, double xitem, double yitem, int n)
{
	if(H[x][y]==NULL)
		return -1;
	
	hash_table* pointer = H[x][y];
	//cout<<x<<" "<<y<<" "<<H[x][y]->x<<" "<<pointer->x<<endl;
	double min_dist = INT_MAX, distance_sq, minx = -2, miny = -2;
	while(pointer != NULL && pointer->x!=-1)
	{
		distance_sq = (xitem-pointer->x)*(xitem-pointer->x)+(yitem-pointer->y)*(yitem-pointer->y);
		if(min_dist-distance_sq>0.001)
		{
			min_dist = distance_sq;
			minx = pointer->x;
			miny = pointer->y;
		}
		pointer = pointer->next;
	}
	//cout<<minx<<" ksdfk "<<miny<<endl;
	int i;
	double delta = 0.00001;
	for(i=0;i<n;i++)
	{
		
		if(fabs(P[i].x-minx)<delta && fabs(P[i].y-miny)<delta)
			return i;
	}
	return -1;

}

void create_hash_table(int n, int m, point* P)
{
	/*Initialise hash_table with values (-1,-1) for (x,y) and NULL to the next pointer*/
	int i,j;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			H[i][j] = (hash_table*)malloc(sizeof(hash_table));
			H[i][j]->x = H[i][j]->y = -1;
			H[i][j]->next =NULL;
		}
	}

	/*Creating the hash table i.e. inserting all the values in it*/
	int xh, yh;
	for(i=0; i<n; i++)
	{
		xh = floor(m*P[i].x);                         //xh and yh contain the cell coordinates where elements have to be inserted
		yh = floor(m*P[i].y);
		push_element(xh, yh, P[i].x, P[i].y);
	}

}

void allocate(point* P,int n)
{
  int i;
  for(i=0;i<n;i++)
    {
      (P[i]).x = random;
      (P[i]).y = random;
    }
}

void push_element(int xh, int yh, double x, double y)
{
	hash_table* pointer = H[xh][yh];
	while(pointer->next != NULL)
		pointer = pointer->next;
	pointer->next = (hash_table*)malloc(sizeof(hash_table));
	pointer->next->next = NULL;
	pointer->next->x = pointer->next->y = -1;
	pointer->x = x;
	pointer->y = y;
	
}

void statistics( int n, int m)
{
	hash_table* pointer;
	int max = INT_MIN, min = INT_MAX;                      
	int frequency[n], c, i, j, max_point, min_point;
	for(i=0;i<n;i++)
		frequency[i] = 0;
	
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			c = 0;
			pointer = H[i][j];
			while(pointer->next !=NULL)
			{
				pointer = pointer->next;
				c++;
			}
			frequency[c]++;	
		}
	}
	min_point = -1;
	//calulation of maximum and number of points in a cell
	for(i=0;i<n;i++)
	{
		if(frequency[i]!=0 && min_point==-1)
			min_point = i;
		
		if(frequency[i]!=0)
			max_point = i;
		  
				
	}
	/*printing the frequency statistics*/
	cout<<"Minimum number of points in a cell = "<<min_point<<"\n";
	cout<<"Maximum number of points in a cell = "<<max_point<<"\n";
	for(i=0;i<n;i++)
	{
		if(frequency[i] != 0)
			cout<<"\t"<<frequency[i]<<" cells with "<<i<<" points\n";
	}
	cout<<"\n\n";
}
