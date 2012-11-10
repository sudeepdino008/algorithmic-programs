#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct bin{
	int data;
    struct bin* parent;
    struct bin* right;
    struct bin* left;
}tree;
void create(tree* p,int n);
int max(tree* p);
bool search(tree* p,int n);

int main(){
    tree* t1;
    int n,m;
    t1=(tree*)malloc(sizeof(tree));
    t1->parent=NULL;
    t1->right=NULL;
    t1->left=NULL;
    cout<<"creating binary tree:"<<endl;
    cout<<"enter starter\n";

    cin>>n;
    t1->data=n;
    while(n!=-1){
        cin>>n;
        create(t1,n);
    }
    //cout<<"\n"<<t1->data<<" "<<t1->left->data<<" "<<t1->right->data<<endl;
    cout<<"maximum number:"<<max(t1)<<endl;
    cout<<"enter element to be seracehd\n";
    cin>>m;
    cout<<"\npath:\n";
    if(search(t1,m))
        cout<<"\nelement found\n";
    else
        cout<<"\nelement not found\n";
    return 0;

}
void create(tree* t1,int n){
    //t1->right=(tree*)malloc(sizeof(tree));
    //t1->right=(tree*)malloc(sizeof(tree));
    if(n==-1);
    else if((t1->data)<n){


            if(t1->right==NULL){
                t1->right=(tree*)malloc(sizeof(tree));
                t1->right->data=n;
                t1->right->parent=t1;
                t1->right->left=NULL;
                t1->right->right=NULL;
            }
            else create(t1->right,n);




    }
    else {
        if(t1->left==NULL){
                t1->left=(tree*)malloc(sizeof(tree));
                t1->left->data=n;
                t1->left->parent=t1;
                t1->left->left=NULL;
                t1->left->right=NULL;
            }
            else create(t1->left,n);
    }
}
int max(tree* t1){
    if(t1->right==NULL)
        return t1->data;
    else
        return max(t1->right);
}
bool search(tree* t1,int n){
    if(t1->data==n)
        return true;
    else if(t1->data<n){
        if(t1->right!=NULL){cout<<t1->right->data<<endl;
            return search(t1->right,n);}
            else return false;}
    else {
        if(t1->left!=NULL){cout<<t1->left->data<<endl;
            return search(t1->left,n);}
            else return false;}
    return false;
}
