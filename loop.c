#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
typedef struct node* NODEPTR;
NODEPTR getnode(int data)
{
    NODEPTR node=malloc(sizeof(NODEPTR));
    node->data=data;
    node->next=NULL;
    return node;
}
NODEPTR detectLoop(struct node* head)
{
    NODEPTR rabbit=head;
    NODEPTR turtle=head;
    int step_taken=0;
    int step_limit=2;
    while(1)
    {
        if(rabbit==NULL)
        {
            printf("%d\n", step_taken);
            return rabbit;
        }

        rabbit=rabbit->next;
        step_taken=step_taken+1;
        if(rabbit==turtle)
        {
            printf("%d\n", step_taken);
            return turtle->next;
        }
        if(step_taken==step_limit)
        {
            turtle=rabbit;
            step_limit*=2;
            step_taken=0;
        }
    }
}
int main()
{
    int arr[7]={1,2,3,4,5,6,7};
    int i=0;
    NODEPTR head=NULL;
    while(i<7)
    {
        NODEPTR node=getnode(arr[6-i]);
        node->next=head;
        head=node;
        i++;
    }
    //printf("%d\n", head->data);
    NODEPTR p=head;NODEPTR q=head;
    while(p->next!=NULL)
        p=p->next;
    while(q->data!=2)
        q=q->next;
    p->next=q;
    NODEPTR x=detectLoop(head);
    printf("%d\n", x->data);
    return 0;
}
