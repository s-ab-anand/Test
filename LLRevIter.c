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
void printList(NODEPTR head)
{
    while(head!=NULL)
    {
        printf("%d\t", head->data);
        head=head->next;
    }
    printf("\n");
}
void revListIter(struct node** head)
{
    if((*head)!=NULL)
    {
        if((*head)->next!=NULL)
        {
            NODEPTR p, q;
            p=(*head);
            q=p->next;
            p->next=NULL;
            //(*head)=p;
            p=q;
            q=q->next;
            while(p!=NULL)
            {
                p->next=(*head);
                (*head)=p;
                //printf("%d\n", (*head)->data);
                p=q;
                if(q!=NULL)
                    q=q->next;
            }
            //*head=p;
        }


    }
    //printList(*head);

}
NODEPTR newHead;

void revListRec(struct node** head, struct node** prev)
{
    if((*head)!=NULL)
    {
        revListRec(&(*head)->next, head);
        if((*head)->next==NULL)
            newHead=*head;
        if(prev!=NULL)
            (*head)->next=*prev;
        else
            (*head)->next=NULL;

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
    printList(head);
    //revListIter(&head);
    revListRec(&head, NULL);
    printList(newHead);
    //printf("%d\n", head->data);

    return 0;
}
