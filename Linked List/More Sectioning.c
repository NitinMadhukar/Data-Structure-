#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    int sec[1000];
    struct node* next;
};
typedef struct node node;
void print(node *, int );
node *createlist()
{
    int x,n,c;
    scanf("%d %d",&n, &c);
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
    int sum[c];
    while(q)
    {
	    for(j=0; j<c; j++)
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
		for(i=1; i<c; i++)
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
	print(head, c);
}
void print(node* p, int d)
{
	node *i;
	int k;
	for(k=0; k<d; k++)
	{
		i=p;
	    while(i)
	    {
	    	if(i->sec[k]!=-1)
	        printf("%d ",i->sec[k]);
	        i=i->next;
	    }
	    printf("\n");
	}
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
