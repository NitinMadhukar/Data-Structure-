#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node 
{
    char data[15];
    struct node *next;
};
typedef struct node node;
int push(char x[],node **top)
{
    node *t=(node *)malloc(sizeof(node));
    strcpy(t->data,x);
    if(*top!=NULL)
    {
        t->next=*top;
        *top=t;
    }
    else{
        t->next=NULL;
        *top=t;
    }
}
int pop(node **top)
{
    node *t=(node *)malloc(sizeof(node));
    t=*top;
    if(t==NULL)
    {
        printf("stack underflow\n");
    }
    else
    {
    *top=(*top)->next;
    t->next=NULL;
    free(t);
    }
}
void room(node * top, int k)
{
    while(top!=NULL)
    {
        int i=0;
        node * temp=NULL;
        while(top!=NULL&&i<k)
        {
           push(top->data,&temp);
           pop(&top);
           i++;
        }
        while(temp)
        {
            printf("%s\n",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,c,i;
        scanf("%d %d",&n,&c);
        node *top=NULL;
        for(i=0;i<n;i++)
        {
            
                char x[12];
                scanf("%s",x);
                push(x,&top);
        }
        room(top, c);
    }
    return 0;
}
