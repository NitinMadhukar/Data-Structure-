#include<stdio.h>
#include<stdlib.h>
int push(int arr[],int top,int x)
{
    arr[++top]=x;
    return top;
}
int push1(int arr1[],int top1, int x)
{
    arr1[++top1]=x;
    return top1;
}
int main()
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        int n,i,temp;
        scanf("%d\n",&n);
        int arr[10000],arr1[10000],top=-1,top1=-1;
        for(i=0;i<n;i++)
        {
            int x,j;
            scanf("%d\n",&x);
            top=push(arr,top,x);
        }
           while(top>-1)
           {
               temp=arr[top];
               top--;
            while(top1>-1  && arr1[top1]>temp)
             {
               int h=arr1[top1];
                top1--;
                top=push(arr,top,h);
              }
             if(top==-1 || arr1[top1]<=temp)
             top1=push1(arr1,top1,temp);
           }
         for(i=0;i<=top1;i++)
          {
              printf("%d ",arr1[i]);
          }
          printf("\n");
        }
    return 0;
}
