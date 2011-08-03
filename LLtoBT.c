#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* next;
};
struct Binary
{
    int data;
    struct Binary* left;
    struct Binary* right;
};
typedef struct node* NODEPTR;
struct Binary* LLtoBT(struct node** nd, int start, int end)
{
    if(start>end)
        return NULL;
    int middle=(start+end)/2;
    struct Binary* leftChild=LLtoBT(nd, start, middle-1);
    struct Binary* parent=malloc(sizeof(struct Binary*));

    parent->data=(*nd)->data;
    parent->left=leftChild;
    (*nd)=(*nd)->next;
    parent->right=LLtoBT(nd, middle+1, end);
    return parent;
}
void intrav(struct Binary* root)
{
    if(root!=NULL)
    {
        intrav(root->left);
        printf("%d\t", root->data);
        intrav(root->right);
    }
}
int main()
{
    struct node* node1=malloc(sizeof(struct node*));
	struct node* node2=malloc(sizeof(struct node*));
	struct node* node3=malloc(sizeof(struct node*));
	struct node* node4=malloc(sizeof(struct node*));
	struct node* node5=malloc(sizeof(struct node*));
    node1->data=1;
	node2->data=2;
	node3->data=3;
	node4->data=4;
	node5->data=5;
	node1->next=node2;
	node2->next=node3;
	node3->next=node4;
	node4->next=node5;
	node5->next=NULL;
    struct Binary* root=LLtoBT(&node1, 0, 4);
    intrav(root);
    free(node1);free(node2);free(node3);free(node4);free(node5);
    free(root);
    return 0;
}
