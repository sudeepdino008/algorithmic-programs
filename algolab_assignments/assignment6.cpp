#include <iostream>
#include <cstdlib>
#include <ctime>
#define random int((double)rand()*100 / (double)RAND_MAX)
using namespace std;

typedef struct node
{
	int data;
	int state;                                                          //state = 1 if value has been printed ; 0 if value has not been printed
	char child;                                                         //child = 'l' if left child ; 'r' if right child
	struct node *left, *right;
}node;

void iterative_traverse(node *root);
void clean(node * root);
int free_tree(node * root , int val);
int insert(node * root);

int main()
{
	srand((unsigned int)time(NULL));
	
	node *root;
	cout<<"Initializing the tree\n \tT = ()\n";
	root = (node*)malloc(sizeof(node));
	root->left = NULL;
	root->right = NULL;
	root->state = 0;
	root->data = random;
	
	cout<<root->data<<" inserted\n";
	cout<<"\tT = ( "<<root->data<<"  )";
	cout<<endl;
	
	int i ;
	for(i=0;i<20;i++)
	{	
		if(insert(root) == 1)
		{
			cout<<"\tT = (";
		
			iterative_traverse(root);
			cout<<")\n";
			
			clean(root);
			
			//cout<<"\n\n";
		}
	}
	cout<<"freeing Tree\n";
	free_tree(root , root->data);
	cout<<"\t T = ()\n";
	return 0;
}



void iterative_traverse(node *root)
{
	node *temp, *p = root, *q = NULL , *max = root;
	
	while(max->right != NULL)                                   
		max = max->right;
		
	while(max->state == 0 || q!=NULL || p != root)  //loop till  maximum value  has been printed and p and q have reached the original state
	{
		if(p->left != NULL && p->left->state == 0)  //move left down if possible
		{
			temp = p->left;
			p->left = q;
			q = p;
			p = temp;
		}
		else    //if it is not possible to go further down
		{
			if(p->state == 0)               //if p has not yet been printed print it
			{
				cout<<" "<<p->data;
				p->state = 1;
			}
			else if(p->right != NULL && p->right->state == 0)   // if it is possible to go down right , move down right
			{
				temp = p->right;
				p->right = q;
				q = p;
				p = temp;
			}
			else
			{
				if(p->child == 'l') //if p is left child , move up left
				{
					temp = q->left;
					q->left= p;
				}
				else                //if p if right child move up right
				{
					temp = q->right;
					q->right = p;
				}
				p = q;
				q = temp;
				
			}
		}
	}
}




void clean(node *root)
{
	if(root== NULL)
		return ;
	
	if(root->state == 1)
		root->state = 0;
	clean(root->left);
	clean(root->right);
}

/*
 * function to free the tree
 */
int free_tree(node * root , int val)
{
	if(root == NULL)
		return 0;
		
	free_tree(root->left , val);
	free_tree(root->right , val);
	
	if(root->data!=val)
	{
		free(root);
	}
	return 1;
}


int insert(node *root)                                                     //random values inserted in this function
{
	node *temp , *parent;
	int state , val;
	
	val = random;
	temp = root;
	while(temp != NULL)                             //looping to find whether val will be a left or right child or not be inserted
	{
		parent = temp;
		if(temp->data > val)
		{
			temp = temp->left;
			state = -1;
		}
		else if(temp->data < val)
		{
			temp = temp->right;
			state = 1;
		}
		else if(temp->data == val)
		{
			state =0;
			break;
		}
	}
		
	if(state!= 0)
	{
		temp = (node*)malloc(sizeof(node));
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		temp->state = 0;
	
		if(state == -1)
		{
			temp->child = 'l';//mark 'l' if left child
			parent->left = temp;
		}
		else if(state == 1)
		{
			temp->child = 'r';//mark 'r' if right child
			parent->right = temp;
		}
	
		cout<<temp->data<<" inserted\n";
		return 1;//return 1 if insertion is possible
	}
	else
		return 0;// return 0 if value already exists in the tree
}

