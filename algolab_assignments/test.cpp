#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>                        //required for the constants INT_MAX and INT_MIN
#include <cstring>
#define MAX(x,y) ((x)>(y))?(x):(y)
#define random (int(((float)rand()*100000 / (float)RAND_MAX)))/100000.0
#define c1 1.5
#define c2 1.1
#define delta 0.0001
#define distance_sq(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) 
#define SWAP(x1,x2) temp=x1;x1=x2;x2=temp;
using namespace std;


typedef struct _node{ 
	float x,y;
	struct _node *next;
}node;                                  //data structure for hash table
typedef node* node_pointer;
typedef node_pointer** hash;

typedef struct linked{
	float x;
	float y;
	struct linked* next;
}adjacency_list;                       //adjacency list for storing graph
typedef adjacency_list* ad_list;


typedef struct _edge{
	float cost;
	float x1,y1;
	float x2,y2;
	struct _edge *left;
	struct _edge *right;
}edge;

hash fillHashTable(int n);
void populateList(adjacency_list* list,node_pointer hash_table,hash H,int n);               //populates the adjacency list with its neighbours
adjacency_list* insert_to_list(adjacency_list* list, float x, float y);                     //returns whether element inserted
int find_index(float startx, float starty, ad_list * list, int n);          	//figure out the index of startx, starty in the adjacency_list

int main()
{
	srand((unsigned int)time(NULL));
	int n,i, m, j;
	cout<<"n = ";
	cin>>n;
	m = ceil(sqrt(n));
	hash hash_table = fillHashTable(n);
	adjacency_list* list[n];
	adjacency_list* temp1;
	int c=0, count=0, count1=0;
	node_pointer temp;

	//initialise adjacency list
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			
			temp = hash_table[i][j];
			while(temp!=NULL && temp->x!=-1)
			{
				list[c] = (adjacency_list *)malloc(sizeof(adjacency_list));
				list[c]->x = temp->x;
				list[c]->y = temp->y;
				list[c]->next = NULL;
				temp =temp->next;
				c++;
			}
			
		}
	}

	
	//filling the adjacency list with edges
	c=0;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			temp = hash_table[i][j];
			while(temp->x!=-1)
			{
				//cout<<"\t("<<temp->x<<" "<<temp->y<<")";
				count1++;
				populateList(list[c++], temp, hash_table,n);
				temp = temp->next;
			}
			//if(hash_table[i][j]!=temp)
			//	cout<<endl;
		}
	}
	
	/*calculating number of edges before 1st phase EMST*/
	c=0;
	for(i=0;i<n;i++)
	{
		temp1 = list[i];
		//cout<<"s:";
		while(temp1!=NULL)
		{
			//cout<<"   ("<<temp1->x<<" "<<temp1->y<<")";
			temp1 = temp1->next;
			c++;
		}
		//cout<<endl;
	}
	/************/
	cout<<"NUmber of edges:"<< c/2 <<endl;
	return 0;
} 


int find_index(float startx, float starty, ad_list * list, int n)          	//figure out the index of startx, starty in the adjacency_list
{
/*we need to find the index in the list[] of the 1st element in queue, for this, we can calculate the index of that element in hash_table and then look around the index (j*m+i) in the list (average constant time)*/
	int m = ceil(sqrt(n)), xh = floor(m*startx) ,yh = floor(m*starty), index = (yh*m+xh);
	int k;
	for(k=0;k<n;k++)
	{
		if(index-k>=0 && abs(list[index-k]->x-startx)<delta && abs(list[index-k]->y-starty)<delta)
		{
			index = index-k;
			break;
		}
		else if(index+k<n && abs(list[index+k]->x-startx)<delta && abs(list[index+k]->y-starty)<delta)
		{
			index = index+k;
			break;
		} 
	}
	return index;
}

hash fillHashTable(int n)
{
	int m = ceil(sqrt(n)), i, j, cx, cy;              //cx, cy contain coordinate of x,y in hash table
	float x,y;                                        //x,y store randomly generated points
	node_pointer temp;
	hash hash_table;
	/* Initialise the hash table   */
	hash_table = (node_pointer **)malloc(m*sizeof(node_pointer *));
	for(i=0;i<m;i++)
	{
		hash_table[i] = (node_pointer *)malloc(m*sizeof(node_pointer));
		for(j=0 ; j<m ;j++)
		{
			hash_table[i][j] = (node *)malloc(sizeof(node));
			hash_table[i][j]->x =  hash_table[i][j]->x = -1;
			hash_table[i][j]->next = NULL;
		}
	}

	/*fill hash table with n points*/

	for(i=0;i<n;i++)
	{
		x = random;
		y = random;
		cx = floor(x*m);
		cy = floor(y*m);
		temp = hash_table[cx][cy];
		while(temp->x!=-1)
			temp = temp->next;
		
		temp->x = x;
		temp->y = y;
		temp->next = (node *)malloc(sizeof(node));
		temp->next->x = temp->next->x = -1;
		temp->next->next = NULL;
		
	}
	return hash_table;

	
}

void populateList(adjacency_list* list,node_pointer hash_table,hash H,int n)               //populates the adjacency list with its neighbours
{
	//cout<<"\n\n\n";
	node_pointer cell;
	float xitem = hash_table->x, yitem = hash_table->y, neighbour_distance_sq = float(c1*c1)/n;
	int m = ceil(sqrt(n)), xi = floor(xitem*m), yi = floor(yitem*m), x, y;    //xi,yi the index of xitem,yitem in hash table
	int count = 0;

	//checking within the cell of xitem and yitem
	x = xi;
	y = yi;
	cell = H[x][y];
	while(cell->x!=-1)
	{
		if(distance_sq(cell->x, cell->y,xitem, yitem)<neighbour_distance_sq && abs(list->x-cell->x)>delta)
			list = insert_to_list(list,cell->x,cell->y);
	
		cell = cell->next;
	}
	//cout<<"original: "<<count<<endl;


	for(int r=1;r<=2;r++)
	{
		//keep x constant at xi+r while vary y from yi-r to yi+r
		x = xi+r;
		y = MAX(yi-r, 0);
		while(x<m && y<=yi+r && y<m)
		{

			cell = H[x][y];
			while( cell->x!=-1)
			{
				if(distance_sq(cell->x,cell->y,xitem,yitem)<neighbour_distance_sq && abs(list->x-cell->x)>delta)
					list = insert_to_list(list, cell->x, cell->y);
			
				cell = cell->next;
			}
			y++;
		}
        // cout<<count<<endl;
		//keep x constant at xi-r while vary y from yi-r to yi+r
		x = xi-r;
		y = MAX(yi-r, 0);
		while(x>=0 && y<=yi+r && y<m)
		{
			cell = H[x][y];
			while(cell->x!=-1)
			{
				if(distance_sq(cell->x, cell->y, xitem, yitem)<neighbour_distance_sq && abs(list->x-cell->x)>delta)
					list = insert_to_list(list, cell->x, cell->y);
				
				cell = cell->next;
			}
			y++;
		}
		//cout<<count<<endl;
  		//keep y constant at yi+r while vary x from xi-r+1 to xi+r-1
		y = yi+r;
		x = MAX(xi-r+1, 0);
		while(y<m && x<=xi+r-1 && x<m)
		{
			cell = H[x][y];
			while( cell->x!=-1)
			{
				if(distance_sq(cell->x, cell->y, xitem, yitem)<neighbour_distance_sq && abs(list->x-cell->x)<delta)
					list = insert_to_list(list, cell->x, cell->y);
			
				cell = cell->next;
			}
			x++;
		}
		//cout<<count<<endl;
		//keep y constant at yi-r while vary x from xi-r+1 to xi+r-1
		y = yi-r;
		x = MAX(xi-r+1, 0);
		while(y>=0 && x<=xi+r-1 && x<m)
		{
			cell = H[x][y];
			while( cell->x!=-1)
			{
				if(distance_sq(cell->x, cell->y, xitem, yitem)<neighbour_distance_sq && abs(list->x-cell->x)>delta)
					list = insert_to_list(list, cell->x, cell->y);
			
				cell = cell->next;
			}
			x++;
		}
		//cout<<count<<endl;
	}

	
	
	
}
   
adjacency_list * insert_to_list(adjacency_list* list, float x, float y)      //returns whether element inserted
{
	adjacency_list* copy = list;

	if(copy == NULL)
	{
		copy = (adjacency_list*)malloc(sizeof(adjacency_list));
		copy->next = NULL;
		copy->x = x;
		copy->y = y;
		return copy;
	}
	else if(copy->x  == -1)
	{
		copy->x = x;
		copy->y = y;
		copy->next = NULL;
		return copy;
	}
	while(copy->next!=NULL)
		copy = copy->next;

	
	copy->next = (adjacency_list*)malloc(sizeof(adjacency_list));
	copy->next->next = NULL;
	copy->next->x = x;
	copy->next->y = y;
	return list;
}


