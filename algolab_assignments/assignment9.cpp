
//Presenty the count is being counted multiple times.Correct that!

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>                        //required for the constants INT_MAX and INT_MIN
#define MAX(x,y) ((x)>(y))?(x):(y)
#define MAX_m 1200
#define random (int(((float)rand()*100000 / (float)RAND_MAX)))/100000.0
#define c1 1.5
#define c2 1.1
#define delta 0.0001
#define ifNeighbour (((cell->x-xitem)*(cell->x-xitem)+(cell->y-yitem)*(cell->y-yitem)-neighbour_distance_sq)<delta)
using namespace std;

typedef struct points{
	float x;
	float y;
}point;                                                      //stores the coordinates of a single point

typedef struct hash_table{ 
	float x,y;
	struct hash_table *next;
}hash_table;                                  //data structure for hash table

typedef struct linked{
	float x;
	float y;
	struct linked* next;
}adjacency_list;

typedef struct heap{
	float x1,y1;
	float x2,y2;
	float cost_sq;                   
	struct heap* child;
}min_heap;                                //contains edges connecting v1 and v2 and their cost.

hash_table* H[MAX_m][MAX_m];       //hash table of size MAX_m

void allocate(point* P,int n);             //fills P[] with random coordinates
void create_hash_table(int n, int m, point* P);          //creates and fills hash tables with values
void push_element_hash_table(int xh, int yh, float x, float y);      //push element required for inserting elements in hash tables
void search(point* P,int n, int m);   //responsible for initial and correct searching
void initialise_adjacency_list(adjacency_list**, point*, int);      //initialises adjacency list by pushing the 1st member in the list
void EMST(adjacency_list** list, point* P, int n);               //implements EMST
int populateList(adjacency_list* list,point P,int n);               //populates the adjacency list with its neighbours
bool insert_to_list(adjacency_list* list, float x, float y);      //returns number of element inserted

int main()
{
	srand((unsigned int)time(NULL));
	int n,m;
	cout<<"n = ";
	cin>>n;
	m = ceil(sqrt(n));
	adjacency_list* list[n]; 
	point P[n];
	allocate(P,n);                //allocating the points randomly in P array
	initialise_adjacency_list(list, P, n);
	//cout<<"\n";
	//for(int i=0;i<n;i++)
	//	cout<<"("<<P[i].x<<","<<P[i].y<<") ,";
	//cout<<"\n";
	create_hash_table(n,m,P);
	EMST(list, P, n); 
	return 0;
}


void kruskal_algorithm(adjacency_list** result,adjacency_list** list, point* P, int nvertice)
{
	min_heap* root = NULL;
	int i=0, root_node_x, root_node_y;
	adjacency_list* temp;
	//creation of min heap
	while(i<n)
	{
		temp = list[i];
		root_node_x = list[i]->x;
		root_node_y = list[i]->y;
		while(temp!=NULL)
		{
			cost_sq = (root_node_x-temp->x)*(root_node_x-temp->x)+(root_node_y-temp->y)*(root_node_y-temp->y);
			insert_heap(root, cost_sq, list[i]->x ,list[i]->y, temp->x, temp->y); 
			temp = temp->next;
		}
	}
	min_heap* temp_heap;
	vertice_count = nvertice;             //keeps the count of vertice in min heap.
	while(vertice_count!=0)
	{
		temp_heap = root;
		remove_from_heap(root);
		if(cycleNotPresent(temp_heap, result))
		{
			for(i=0;i<n;i++)
			{
				if(abs(P[i].x-root->
			}
		}
	}





}

void insert_heap(min_heap* heap, float cost_sq, float x1, float y1,float x2, float y2)
{
	
}

void EMST(adjacency_list** list, point* P, int n)               //implements EMST
{
	//adding the edges
	int i, count = 0;
	for(i=0;i<n;i++)
		count += populateList(list[i], P[i], n);       
	
	cout<<"1st phase of MST: " << count/2 << endl;                             //by 2 because each edge will be counted twice          

	kruskal_algorithm(list, P, n);	
	
}

int populateList(adjacency_list* list,point P,int n)               //populates the adjacency list with its neighbours
{
	//cout<<"\n\n\n";
	hash_table* cell;
	float xitem = P.x, yitem = P.y, neighbour_distance_sq = float(c1*c1)/n;
	int m = ceil(sqrt(n)), xi = floor(xitem*m), yi = floor(yitem*m), x, y;    //xi,yi the index of xitem,yitem in hash table
	int count = 0;

	//checking within the cell of xitem and yitem
	x = xi;
	y = yi;
	cell = H[x][y];
	while(cell->x!=-1)
	{
		if(ifNeighbour && insert_to_list(list, cell->x, cell->y))
		{
			count++;
			insert_to_list(list,cell->x, cell->y);
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
			while(cell->x!=-1)
			{
				if(ifNeighbour && insert_to_list(list, cell->x, cell->y))
					count++;
				
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
				if(ifNeighbour && insert_to_list(list, cell->x, cell->y))
					count++;				
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
			while(cell->x!=-1)
			{
				if(ifNeighbour && insert_to_list(list, cell->x, cell->y))
					count++;
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
			while(cell->x!=-1)
			{
				if(ifNeighbour && insert_to_list(list, cell->x, cell->y))
					count++;
				cell = cell->next;
			}
			x++;
		}
		//cout<<count<<endl;
	}
	
	return count;           
		
   
}

bool insert_to_list(adjacency_list* list, float x, float y)      //returns whether element inserted
{
	adjacency_list* copy = list;
	int count = 0;
	while(copy!=NULL)
	{
		if(abs(copy->x-x)<delta)
			return false;
		count++;
		copy = copy->next;
	}
	
	copy = (adjacency_list*)malloc(sizeof(adjacency_list));
	copy->next = NULL;
	copy->x = x;
	copy->y = y;
	return true;
}


void initialise_adjacency_list(adjacency_list** list ,point* P, int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		list[i] = (adjacency_list*)malloc(sizeof(adjacency_list));
		list[i]->x = P[i].x;
		list[i]->y = P[i].y;
		list[i]->next = NULL;
	}
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
		push_element_hash_table(xh, yh, P[i].x, P[i].y);
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

void push_element_hash_table(int xh, int yh, float x, float y)
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

