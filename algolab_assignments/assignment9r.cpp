#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <climits>                        //required for the constants INT_MAX and INT_MIN
#define MAX(x,y) ((x)>(y))?(x):(y)
#define random (int(((float)rand()*100000 / (float)RAND_MAX)))/100000.0
#define c1 1.5
#define c2 1.1
#define delta 0.0001
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
}adjacency_list;


hash fillHashTable(int n);

int main()
{
	srand((unsigned int)time(NULL));
	int n,i;
	cout<<"n = ";
	cin>>n;

	hash hash_table = fillHashTable(n);
	node_pointer temp;
	
	return 0;
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
			hash_table[i][j] = NULL;
	}

	/*fill hash table with n points*/

	for(i=0;i<n;i++)
	{
		x = random;
		y = random;
		cx = floor(x*m);
		cy = floor(y*m);
		temp = hash_table[cx][cy];
		while(temp!=NULL && temp->next!=NULL)
			temp = temp->next;
		if(temp == NULL)
		{
			hash_table[cx][cy] = (node *)malloc(sizeof(node));
			hash_table[cx][cy]->x = x;
			hash_table[cx][cy]->y = y;
			hash_table[cx][cy]->next = NULL;
		}
		else
		{
			temp->next = NULL;
			temp->x = x;
			temp->y = y;
		}
	}
	return hash_table;

	
}
