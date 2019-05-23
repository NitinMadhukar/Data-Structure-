#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
struct node
{
    char data[1000];
    struct node* next;
};
typedef struct node node;
void print(node* p,node *p1,int l)
{
    node* q;
    while(p1)
    {
        q=p;
       while(q)
       {
         if(!strncmp(p1->data,q->data,7))
         printf("%s ",p1->data);
         
         q=q->next;
        }
    
       p1=p1->next;
    }
       printf("\n");
}
node *createlist()
{
    int x,n,t,l;
    int i,j;
    scanf("%d %d",&n,&t);
    
    node *head[t],*p,*q,*head2=NULL,*temp;
   
    for(i=0;i<t;i++)
    {
        
        head[i]=NULL;
        scanf("%d",&l);
        for(j=0;j<l;j++)
        {
         temp=(node *)malloc(sizeof(node));
        char a[7];
        scanf("%s ",a);
        strcpy(temp->data,a);
        temp->next=NULL;
        if(!head[i])
        {
            head[i]=temp;
        }
        else
        {
            p=head[i];
            while(p->next)
            {
                p=p->next;
            }
            p->next=temp;
        }
        }
    }
    while(n--)
    {
        char z[11];
        scanf("%s ",z);
        node *temp1=(node *)malloc(sizeof(node));
        strcpy(temp1->data,z);
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
    for(i=0;i<t;i++)
    print(head[i],head2,l);
 
    
    return head2;
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
