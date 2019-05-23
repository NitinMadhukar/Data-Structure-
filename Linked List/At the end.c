#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void list(struct node **head, int x)
{
    node *p;
    p=(node *)malloc(sizeof(node));
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
node* display(node** head)
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
    return ;
}
int main()
{
    node *p,*head,*h2;
    int max;
    p=(node *)malloc(sizeof(node));
    int t,n,x;
    scanf("%d",&t);
    while(t--)
    {
        h2=NULL;
        head=NULL;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            list(&head,x);
        }
        for(int i=0;i<n;i++)
        {
        p=head; 
        max=p->data;
        while(p!=NULL)
        {
            if(max< p->data)
            max=p->data;
            p=p->next;
        }
        del(&head,max);
        list(&h2,max);
        }
        display(&h2);
        printf("\n");
    }
}
