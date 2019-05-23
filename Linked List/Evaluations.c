#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data[1000];
    char name[1000];
    int marks;
    struct node* next;
};
typedef struct node node;
void print(node* p,node *p1)
{
    node *q=p1;
    while(p)
    {
        int sum=0;
        printf("%s %s ",p->data,p->name);
        q=p1;
        while(q)
        {
            if(!strcmp(p->data, q->data))
            {
            printf("%d ",q->marks);
            sum+=q->marks;
            }
            q=q->next;
        }
        printf("%d\n",sum);
        p=p->next;
    }
}
node *createlist()
{
    int x,n,t;
    scanf("%d %d",&n,&t);
    node *head=NULL,*p,*q,*head2=NULL;
    while(n--)
    {
        char a[11],b[100];
        scanf("%s %s",a,b);
        node *temp=(node *)malloc(sizeof(node));
        strcpy(temp->data,a);
        strcpy(temp->name,b);
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
    }
    while(t--)
    {
        char z[11];
        int s;
        scanf("%s %d",z,&s);
        node *temp1=(node *)malloc(sizeof(node));
        strcpy(temp1->data,z);
        temp1->marks=s;
        temp1->next=NULL;
        if(!head2)
        {
            head2=temp1;
        }
        else
        {
            q=head2;
            while(q->next)
            {
                q=q->next;
            }
            q->next=temp1;
        }
    }   
    print(head,head2);
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
    node *p=createlist();
    }
}
