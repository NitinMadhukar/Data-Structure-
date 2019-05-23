#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
 
node *insert(struct node **head, int n)
{
    int x;
    node *p;
    p=(node *)malloc(sizeof(node));
    *head=NULL;
    while(n--)
    {
        scanf("%d",&x);
        node *temp=(node *)malloc(sizeof(node));
        temp->data=x;
        temp->next=NULL;
        if(!(*head))
        {
            *head=temp;
        }
        else
        {
            p=*head;
            while(p->next)
            {
                p=p->next;
            }
            p->next=temp;
        }
       
    }
     return *head;
    
}
 
void display(node** head)
{
    node *p;
    p=(node *)malloc(sizeof(node));
    p=*head;
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void del(struct node **head , int x)
{
    node *p,*t;
    p=(node *)malloc(sizeof(node));
     p=*head;
     if(p!=NULL&&p->data==x)
        {
         *head=p->next;
         free(p);
         return;
        }
   
    while(p!=NULL&&p->data!=x)
    {
        t=p;
        p=p->next;
    }
    
    t->next=p->next;
    
    free(p);
}
int main()
{
    node *p,*head;
    p=(node *)malloc(sizeof(node));
    head=(node *)malloc(sizeof(node));
    int t,x,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        
            p=insert(&head,n);
        
        int max=0,min;
        *p=*head;
        min=p->data;
 
        while(p)
        {
            if(min> p->data)
            min=p->data;
            if(max<p->data)
            max=p->data;
            p=p->next;
        }
        if(n==1)
        {
            del(&head,min);
        }
        else
        {
            del(&head,min);
            del(&head,max);
        }
        display(&head);
        printf("\n");
    }
}
