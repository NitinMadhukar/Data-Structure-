#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int data;
    int wgt;
    struct node *next;
};
 
typedef struct node node;


void print(int dis[],int V)
{
    int i;
    for(i=0;i<V;i++)
    {
        if(dis[i]==10000000)
        printf("-1\n");
        else
        printf("%d\n",dis[i]);
    }
}

void dijkstracost(node *head[],int V)
{
    int f,r,col[V],dis[V],visited[V],parent[V];
    int i;
    for(i=0;i<V;i++)
    {
        dis[i]=10000000;
        col[i]=0;
    }
    f=0,r=0,dis[0]=0,col[0]=1,visited[f]=0,r++;
    for(i=0;i<r;i++)
    {
        node* t=(node *)malloc(sizeof(node));
        t=head[visited[i]];
        col[visited[i]]=2;
        while(t!=NULL)
        {
            if(col[t->data]==0)
            {
                visited[r]=t->data;
                r++;
                col[t->data]=1;
                
            }
            parent[t->data]=visited[i];
            int sum=dis[parent[t->data]]+t->wgt;
            if(sum<=dis[t->data])
            {
                dis[t->data]=sum;
            }
            t=t->next;
        }
          f++;
          for(int j=f;j<r-1;j++)
          {
              for(int k=f;k<r;k++)
              {
                  if(dis[visited[j]]<dis[visited[k]])
                  {
                      int a=visited[j];
                      visited[j]=visited[k];
                      visited[k]=a;
                   }
              }
          }
         
    }     print(dis,V);
    
}
 
 
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
                int u,v,w;
                scanf("%d %d %d",&u,&v,&w);
                node *p=(node *)malloc(sizeof(node));
                p->data=v;
                p->wgt=w;
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
            dijkstracost(head,V);

}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int V,E;
        scanf("%d %d",&V,&E);
        arrlinklist(V,E);
    }
}
