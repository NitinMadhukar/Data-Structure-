#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
typedef struct node node;
node *createlist()
{
    int x,n;
    scanf("%d",&n);
    node *head=NULL,*p;
    while(n--)
    {
        scanf("%d",&x);
        node *temp=(node *)malloc(sizeof(node));
        temp->data=x;
        temp->next=NULL;
        if(!head)
        {
            head=temp;
        }
        else
        {
            p=head;
            while(p->next)
            {
                p=p->next;
            }
            p->next=temp;
        }
    }return head;
}
void print(node* p)
{
    while(p)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
void sum(node* p)
{
    int sum=0;
    while(p)
    {
       sum=sum+p->data;
       p=p->next;
    }
    printf("%d\n",sum);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    node *p=createlist();
    print(p);
    sum(p);
}
}
