 #include<stdio.h>
 #include<stdlib.h>
 struct node
 {
     int data;
     struct node *next;
 };
 typedef struct node node;
 node* createlist()
 {
     int n,x;
     scanf("%d",&n);
     struct node *head=NULL,*p;
     while(n--)
     {
         scanf("%d",&x);
         node* temp=(node *)malloc(sizeof(node));
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
 node* odd(node *p)
 {
    struct node *head=NULL,*pr=NULL;
    while(p)
    {
        if(p->data%2!=0)
        {
             node* temp=(node *)malloc(sizeof(node));
             temp->data=p->data;
             temp->next=NULL;
             if(!head)
             {
                 head=temp;
             }
             else
             {
             pr->next=temp;
             }
                 pr=temp;
            }p=p->next;
    }return head;
 }
 node* even(node* p)
 {
    struct node *head=NULL,*pr=NULL;
    while(p)
    {
        if(p->data%2==0)
        {
             node* temp=(node *)malloc(sizeof(node));
             temp->data=p->data;
             temp->next=NULL;
             if(!head)
             {
                 head=temp;
             }
             else
             {
             pr->next=temp;
             }
                 pr=temp;
            }p=p->next;
    }return head;
}
 node* append(node* p,node *q)
 {
     node *i;
     for(i=p;i->next!=NULL;i=i->next);
     i->next=q;
     return p;
 }
 void print(node *p)
 {
     while(p)
     {
         printf("%d ",p->data);
         p=p->next;
     }
 }
 int main()
 {
     int t;
     scanf("%d",&t);
     while(t--)
     {
        node* p=createlist();
        node* o=odd(p);
        node* e=even(p);
        //print(o);
        o=append(o,e);
        print(o);
        printf("\n");
     }
 }
