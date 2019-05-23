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

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		printf("%d ",root->data);
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

void search(node *root,int data)
{
	int d=0;
	node *t=newnode;
	t=root; 
	while(t!=NULL)
	{
		d++;
		if(t->data==data)
		{
			printf("%d\n",d);
			return ;
		}
		else if(t->data>data)
		t=t->l;
		else
		t=t->r;
	}
	printf("NOT FOUND\n");
	return;
}
int main()
{ 
 	node *root = NULL;
 	int arr[]={19,22,13,7,24,17,11,3,39,51};
 	int num = sizeof(arr)/sizeof(arr[0]);
 	int i,n=4;
 	for(i=0;i<num;i++)
	{ 
    root = insert(root,arr[i]);
    }
    inorder(root);  
    search(root,n);
    return 0;
}
