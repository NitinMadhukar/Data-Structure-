#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void insertbegin(struct node **head,int z)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=z;
        temp->next=NULL;
        *head=temp;
}
void insertend(struct node **head,int x)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=x;
        temp->next=NULL;
        struct node *p;
        p=*head;
        while(p->next)
        {
            p=p->next;
        }
        p->next=temp;
}
int key(struct node *head,int n)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp=head;
    int i=0;
    while(i<n)
    {
        temp=temp->next;
        i++;
    }
    return temp->data;
}
void print(struct node* p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    int t,x,n,l;
    scanf("%d",&n);
    while(n--)
    {
    struct node *head, *h1;
    scanf("%d",&t);
    int i=0;
    for(i=0;i<t;i++)
    {
    int x;
    scanf("%d",&x);
    if(i==0)
    insertbegin(&head,x);
    else
    insertend(&head,x);
    }
    for(i=0;i<t;i++)
    {
    scanf("%d",&x);
    l=key(head,x);
    if(i==0)
    insertbegin(&h1,l);
    else
    insertend(&h1,l);
    }
    print(h1);
    printf("\n");
    }
}
