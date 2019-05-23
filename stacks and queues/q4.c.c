#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node node;
void enqueue(node **r,node **f)
{
    int x;
    scanf("%d",&x);
    node *temp=(node *)malloc(sizeof(node));
    temp->data=x;
    temp->next=NULL;
    if(*f==NULL)
    {
        *r=temp;
        *f=temp;
    }
    else
    {
        *r=*f;
        while((*r)->next)
        *r=(*r)->next;
        (*r)->next=temp;
    }
}
void dequeue(node **r,node **f)
{
    if(*f==NULL)
    {
        printf("queue underflow\n");
    }
    else
    {
        node *temp=*f;
        *f=(*f)->next;
        printf("%d\n",temp->data);
        free(temp);
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,i; 
        scanf("%d",&n);
        node *r=NULL,*f=NULL;
        for(i=0;i<n;i++)
        {
            char a[50];
            scanf("%s",a);
            if(!strcmp(a, "enqueue"))
            {
                enqueue(&r,&f);
            }
            else if(!strcmp(a, "dequeue"))
            {
               dequeue(&r,&f);
            }
            else if(!strcmp(a, "front"))
            {
                if((f)==NULL)
                {
                    printf("queue underflow\n");
                }
               else
               {
                   node *temp=f;
                   printf("%d\n",temp->data);
               }
            }       
        
        }
    }
    return 0;
}
