#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void getnode(struct node** newNode, int data1)
{
    *newNode=malloc(sizeof(struct node*));
    (*newNode)->left=NULL;
    (*newNode)->right=NULL;
    (*newNode)->data=data1;
}
int main()
{
    struct node* node1;
    getnode(&node1, 1);
    printf("%d\n", node1->data);
    return 0;
}
