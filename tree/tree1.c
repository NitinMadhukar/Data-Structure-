#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* l;
	struct node* r;
};

typedef struct node node;

node *newnode(int data)
{
	node *temp=(node *)malloc(sizeof(node));
	temp->data=data;
	temp->l=NULL;
	temp->r=NULL;
	return(temp);
}

void postorder(node *temp)
{
	if(temp==NULL)
	return ;
	
	postorder(temp->l);
	postorder(temp->r);
	printf("%d ",temp->data);
}

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		inorder(root->r);
	}
}
node *insert(node* temp, int data) 
{ 
    if (temp == NULL) 
	return newnode(data); 
    
    if (data < temp->data) 
        temp->l  = insert(temp->l, data); 
    else if (data > temp->data) 
        temp->r = insert(temp->r, data);    
        return temp; 
 }
int main()
{ 
    node *root = NULL;
    int i;
	int arr[]={19,22,13,7,24,17,11,3,39,51};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<n;i++)
	{
    root = insert(root,arr[i]);
    inorder(root);  
    }
    postorder(root); 
    return 0;
}
