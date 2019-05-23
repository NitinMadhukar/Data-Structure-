#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
struct node
{
    int data;
    struct node *next;  
};
 
typedef struct node node;
node *createlist()
{
    int x,n;
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
    }return head;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        node*p[100];
        char str[100];
        int n, i, j, count=0;
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            scanf("%s ", str);
            if(!strcmp(str, "add"))
            {
                p[count]=createlist();
                count++;
            }
            else if(!strcmp(str, "delete"))
            {
                int num;
                scanf("%d", &num);
                for(j=0; j<count; j++)
                {
                    node*temp=p[j], *y=NULL;
                    while(temp)
                    {
                        if(p[j]->data==num)
                        p[j]=p[j]->next;
                        else if(temp->data==num)
                        {
                            y->next=temp->next;
                        }
                        y=y->next;
                    }
                }
            }
            else if(!strcmp(str, "print")){
                for(j=0; j<count; j++){
                    node *y=p[j];
                    while(y){
                        printf("%d ", y->data);
                        y=y->next;
                    }
                    if(y!=p[j])
                    printf("\n");                
                }
            }
        }
    
    }
}
