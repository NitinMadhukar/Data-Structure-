#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void enqueue(int c,int arr[],int front,int rear)
{
    int x;
    scanf("%d",&x);
    if(rear-front>=c)
    {
        printf("queue overflow\n");
    }
    else
    {
      arr[rear] = x;
      rear++;
    }
}
void dequeue(int c,int arr[],int front,int rear)
{
    if(rear-front==0)
    {
        printf("queue underflow\n");
        return ;
    }
    else
    {
        printf("%d\n",arr[front]);
        front++;
    }
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,c,i; 
        int front=1,rear=1;
        scanf("%d %d",&n,&c);
        int arr[1000];
        for(i=0;i<n;i++)
        {
            char a[50];
            scanf("%s",a);
            if(!strcmp(a, "enqueue"))
            {
                enqueue(c,arr,front,rear);
                if(rear-front<c)
                {rear++;}
            }
            else if(!strcmp(a, "dequeue"))
            {
               dequeue(c,arr,front,rear);
               if(rear-front!=0)
               front++;
            }
            else if(!strcmp(a, "front"))
            {
                if(rear-front==0)
                {
                    printf("queue underflow\n");
                }
                else
                printf("%d\n", arr[front]);
            }
        }
    }
    return 0;
}
