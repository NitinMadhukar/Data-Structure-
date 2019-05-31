/*It is Kumbh and a number of devotees come to enter the entrance area.\
 Each devotee has a name (1 word only), gender (1 word only), residence city 
 (1 word only) and contact number (1 word only). The devotees are stacked in
  the order they arrive. When the event starts, the devotees are popped out 
  and are allowed to enter the river area. Print the order in which the devotees 
  enter the river area. Implement using stack with linked list.
 */
 
/*
Input Format

The first line is T, the number of test cases. Thereafter, each test case 
starts with n, the number of devotees. The next n lines print the details
of all devotees, name, gender, residence city and contact number.

Output Format

For every test case, n lines, the details of all devotees separated by a space.

 

Sample Input

1

5

DName1 Male DCity1 DPh1

DName2 Female DCity2 DPh2

DName3 Male DCity3 DPh3

DName4 Female DCity4 DPh4

DName5 Male DCity5 DPh5

 

Sample Output

DName5 Male DCity5 DPh5

DName4 Female DCity4 DPh4

DName3 Male DCity3 DPh3

DName2 Female DCity2 DPh2

DName1 Male DCity1 DPh1
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node 
{
    char name[100];
    char gender[100];
    char city[100];
    char phone[100];
    struct node *next;
};
typedef struct node node;
void push(node **top)
{
    node *t=(node *)malloc(sizeof(node));
    scanf("%s %s %s %s\n",t->name,t->gender,t->city,t->phone);
    t->next=NULL;
    if(*top==NULL){
        *top=t;
    }
    else{
        t->next=*top;
        *top=t;
    }
}
void pop(node **top)
{
    node *t=*top;
    printf("%s %s %s %s\n",t->name,t->gender,t->city,t->phone);
       t=t->next;
        *top=t;
}
int main()
{
    int tc;
    scanf("%d\n",&tc);
    while(tc--)
    {
        struct node *top=NULL;
        int n;
        scanf("%d\n",&n);
        while(n--)
        {
               push(&top);
        }
        while(top!=NULL){
            pop(&top);
        }
       
    }
    return 0;
}