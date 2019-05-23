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

void heapify(int arr[], int n, int i) 
{ 
	int largest = i;  
	int l = 2*i + 1; 
	int r = 2*i + 2;  
	if (l < n && arr[l] > arr[largest]) 
		largest = l;  
	if (r < n && arr[r] > arr[largest]) 
		largest = r; 

	if (largest != i) 
	{ 
		int t;
		t=arr[i];
		arr[i]=arr[largest];
		arr[largest]=t;
		heapify(arr, n, largest); 
	} 
} 

void heapSort(int arr[], int n,int i) 
{ 
	for ( i = n / 2 - 1; i >= 0; i--) 
		heapify(arr, n, i);  
	for ( i=n-1; i>=0; i--) 
	{ 
		int t;
		t=arr[0];
		arr[0]=arr[i];
		arr[i]=t;
		heapify(arr, i, 0); 	
	} 
} 

void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->l);
		inorder(root->r);
	}
}

void preorder(node *temp) 
{ 
    if (temp == NULL) 
        return; 
	printf("%d ",temp->data);  
    preorder(temp->l);  
    preorder(temp->r); 
}  

node *insert(node* temp, int data) 
{ 
    if (temp == NULL) return newnode(data); 
  
    if (data < temp->data) 
        temp->l  = insert(temp->l, data); 
    else if (data > temp->data) 
        temp->r = insert(temp->r, data);    
      return temp; 
}

int main() 
{
	struct node *root=NULL;
	int i;
	int arr[] = {40,60,10,20,50,30}; 
	int n = sizeof(arr)/sizeof(arr[0]);
	for(i=0;i<n;i++)
	{
    root = insert(root,arr[i]);
    inorder(root);  
    }
    preorder(root);  
	heapSort(arr, n,i); 
    return 0;
} 
