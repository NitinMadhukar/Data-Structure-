#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    int sec[3];
    struct node *next;
};
typedef struct node node;
void print(node *p)
{
    node *t;
    int k;
    for(k=0;k<3;k++)
    {
        t=p;
        while(t)
        {
            if(t->sec[k]!=-1)
            {
                printf("%d ",t->sec[k]);
            }
            t=t->next;
        }
        printf("\n");
    }
}
node *createlist()
{
    int n,x;
    scanf("%d",&n);
    node *head=NULL,*p=NULL;
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
    }
    node *q=head;
    int j;
    int sum[3];
    while(q)
    {
    for(j=0;j<3;j++)
    {
        q->sec[j]=-1;
        sum[j]=0;
    }
    q=q->next;
    }
    node *temp=head;
    while(temp)
    {
        int w=0, i, m=sum[0];
        for(i=1;i<3;i++)
        {
            if(m>sum[i])
            {
                m=sum[i];
                w=i;
            }
        }
        temp->sec[w]=temp->data;
        sum[w]+=temp->data;
        temp=temp->next;
    }
    print(head);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        node *p=createlist();
    }
}
