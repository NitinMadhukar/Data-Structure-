#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;
 
node *arrlinklist(int V,int E)
{
    int i;
     node *head[V],*temp=NULL;
            for(i=0;i<V;i++)
            {
                head[i]=NULL;
            }
            while(E--)
            {
                int u,v;
                scanf("%d %d",&u,&v);
                node *p=(node *)malloc(sizeof(node));
                p->data=v;
                p->next=NULL;
                if(!head[u])
                {
                    head[u]=p;
                }
                else
                {
                    temp=head[u];
                    while(temp->next)
                    temp=temp->next;
                    temp->next=p;
                }
           }
                path(head,V);

}
void print(int V,node *pth[])
{
    int i;
    for(i=0;i<V;i++)
    {
        if(pth[i]==NULL)
        {
            printf("NIL\n");
        }
        else
        {
            node* a=pth[i];
            while(a)
            {
                printf("%d ",a->data);
                a=a->next;
            }
            printf("\n");
        }
    }
}
void path(struct node *head[],int V)
{
    int f,r,col[V],dis[V],visited[V],parent[V];
    node *pth[V];
    int i,j;
    for(i=0;i<V;i++)
    {
        dis[i]=-1;
        col[i]=0;
        pth[i]=NULL;
    } 
    node *x=(node *)malloc(sizeof(node));
    x->data=0;
    x->next=NULL;
    pth[0]=x;
    r=0,dis[0]=0,col[0]=1,visited[0]=0,r++;
    for(i=0;i<r;i++)
    {
        node* t=head[visited[i]];
        col[visited[i]]=2;
        while(t)
        {
            if(col[t->data]==0)
            {
                 visited[r]=t->data;
                 r++;
                 parent[t->data]=visited[i];
                 col[t->data]=1;
                 node *temp=pth[parent[t->data]];
                 pth[t->data]=NULL;
                 while(temp)
                 {
                    node* q=(node *)malloc(sizeof(node));
                    q->data=temp->data;
                    q->next=NULL;
                    if(pth[t->data]==NULL)
                    {
                        pth[t->data]=q;
                    }
                    else
                    {
                        node *w=pth[t->data];
                        while(w->next)
                        {
                            w=w->next;
                        }
                    w->next=q;
                    }
                    temp=temp->next;
                 }
                 node *re=(node *)malloc(sizeof(node));
                 re->data=t->data;
                 re->next=NULL;
                 temp=pth[t->data];
                 while(temp->next)
                 {
                     temp=temp->next;
                 }  
                 temp->next=re;
            }
            t=t->next;
        }
          f++;
    }    
    print(V,pth);
}

int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int V,E,i;
        scanf("%d %d",&V,&E);
        arrlinklist(V,E);
    }
}

