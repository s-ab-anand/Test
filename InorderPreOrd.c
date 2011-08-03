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
int find(int prOrd[], int start, int end, int root)
{
    while(start<=end)
    {
        if(prOrd[start]==root)
            return start;
        start++;
    }
    return -1;
}
Binary* BinaryTree(int inOrd[], int prOrd[], int start, int end)
{
    Binary* root=malloc(sizeof(Binary*));
    root->data=prOrd[0];
    int i = find(prOrd, start, end, root->data);
    root->left=BinaryTree(inOrd, prOrd+1, start, i-1);
    root->right=BinaryTree(inOrd, prOrd+1+i, i+1, end)
}
int main()
{
    int inOrd[5]={1,2,3,4,5};
    int prOrd[5]={4,2,1,3,5};
    Binary* root=BinaryTree(inOrd, prOrd, 0, 4, 0);
    return 0;
}
