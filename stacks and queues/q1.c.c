#include<stdio.h>
#include<string.h>
void push(int x,int c,int arr[],int top)
{
    if(top==c)
    {
        printf("stack overflow\n");
    }
    else
    {
        arr[++top]=x;
    }
}
void pop(int c,int arr[],int top)
{
    if(top<=0)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("%d\n", arr[top]);
        top--;
    }
}
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,c,i;
        scanf("%d %d",&n,&c);
        int arr[c],top=0;
        for(i=0;i<n;i++)
        {
            char a[50];
            scanf("%s",a);
            if(!strcmp(a, "push"))
            {
                int x;
                scanf("%d",&x);
                push(x,c,arr,top);
                if(top<c)
                top++;
            }
            else if(!strcmp(a, "pop"))
            {
                pop(c,arr,top);
                if(top>0)
                top--;
            }
            else if(!strcmp(a, "top"))
            {
                if(top==0)
                {
                    printf("stack underflow\n");
                }
                 else printf("%d\n", arr[top]);
            }
        }
    }
    return 0;
}
