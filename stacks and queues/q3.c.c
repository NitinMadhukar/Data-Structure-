#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *next;
};
typedef struct node node;
int push(int x,node *top)
{
    node *t=(node *)malloc(sizeof(node));
    t->data=x;
    t->next=top;
    top=t;
    return top;
}
int pop(node *top)
{
    node *t=(node *)malloc(sizeof(node));
    t=top;
    if(t==NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
    top=top->next;
    t->next=NULL;
    printf("%d\n",t->data);
    free(t);
    return top;
}}
 
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,i;
        scanf("%d",&n);
        node *top=NULL;
        for( i=0;i<n;i++)
        {
            char a[50];
            scanf("%s",a);
            if(!strcmp(a, "push"))
            {
                int x;
                scanf("%d",&x);
          	    int h = push(x,top);
                top=h;
            }
            else if(!strcmp(a, "pop"))
            {
                int j= pop(top);
                top=j;
            }
            else if(!strcmp(a, "top"))
            {
                if(top!=NULL)
               { 
                printf("%d\n",top->data);
                }
                else
                printf("stack underflow\n");
            }
        }
    }
    return 0;
}
