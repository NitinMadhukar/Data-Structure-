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
                  cost(head,V);

}
void print(int V,int dis[])
{
    int i;
    for(i=0;i<V;i++)
    printf("%d\n",dis[i]);
}
void cost(struct node *head[],int V)
{
    int f,r,col[V],dis[V],visited[V],parent[V];
    int i,j;
    for(i=0;i<V;i++)
    {
        dis[i]=-1;
        col[i]=0;
    }
    f=0,r=0,dis[0]=0,col[0]=1,visited[f]=0,r++;
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
                dis[t->data]=dis[parent[t->data]]+1;
            }
            t=t->next;
        }
          f++;
    }    
    print(V,dis);
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
