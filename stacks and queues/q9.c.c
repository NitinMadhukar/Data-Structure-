#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node 
{
    char data[15];
    struct node *next;
};
typedef struct node node;
void push(char x[],node **top)
{
    node *t=(node *)malloc(sizeof(node));
    strcpy(t->data,x);
    if(*top!=NULL)
    {
        t->next=*top;
        *top=t;
    }
    else
    {
        t->next=NULL;
        *top=t;
    }
}
void pop(node **top)
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
void print(struct node * head)
{
    struct node* p=head->next;
    while(p!=NULL)
    {
        printf("%s\n",p->data);
        p=p->next;
    }
}
int room(node * top, int k)
{
    while(top!=NULL)
    {
        int i=0;
        node *temp=NULL;
        while(top!=NULL && i<k)
        {
           push(top->data,&temp);
           pop(&top);
           i++;
        }
        while(temp)
        {
            printf("%s\n",temp->data);
        }
        return temp;
        
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,c,i,j;
        scanf("%d %d",&n,&c);
        node *top=NULL,*temp=NULL;
        for(i=0;i<n;i++)
        {
           char x[12];
           scanf("%s",x);
           push(x,&top);
        }
        node *cr[c];
        for(i=0;i<c;i++)
        {
            cr[i]=(struct node*)malloc(sizeof(struct node));
            cr[i]->next=NULL;
        } 
        for(i=0;i<n;)
        {
            for(j=0;j<c;j++)
            {
                if(i==n)
                {
                    break;
                }
                room(temp,c);
                struct node *temp1=(struct node*)malloc(sizeof(struct node));
                strcpy(temp1->data,temp->data);
                push(cr[j],&top);
                top=pop(&top);
                i++;
            }    
              print(cr[i]);
        }
    }
    return 0;
}
