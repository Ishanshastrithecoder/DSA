#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
struct node{
int data;
    struct node *link;
};
struct node *head=NULL;

struct node* create(int data)
{
    struct node*new1;
    new1=(struct node *)malloc(sizeof(struct node*));
    new1->data=data;
    new1->link=NULL;
    return new1;
}

struct node * reverse()
{
    struct node *cur=head,*prev=NULL,*temp;
    while(cur)
    {
        
        temp=cur->link;
        cur->link=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}

void print(struct node *t)
{
    while(t!=NULL)
    {
        printf("%d ",t->data);
        t=t->link;
        
    }
    printf("\n");
}
int main() {
    int n,val;
    scanf("%d",&n);
    if(n<=0||n>30)return 0;
    
    struct node* temp=NULL;
    for(int i=0;i<n;i++)
    {
    scanf("%d",&val);
        struct  node *t=create(val);
        if(head==NULL)
        {
            head=t;
            temp=head;
        }
        else{
            temp->link=t;
            temp=temp->link;
        }
    }
    head=reverse();//returning the data from end;
    print(head);
    

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
