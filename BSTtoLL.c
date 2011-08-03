#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* left;
	struct node* right;
};
/*char* fgets(char* line, File* fp)
{
	register int c;
	register char* cs;
	cs=line;
	while((c=getc(fp))!= EOF)
	{
		if((*cs++ = c) == '\n')
			break;
	}
		*cs='\n';
		return (c==EOF && cs==s)?NULL:s;
}*/
typedef struct node* NODEPTR;
void intrav(struct node* root, struct node** prev, struct node** head)
{
	if(root!=NULL)
	{
		intrav(root->left, prev, head);
		root->left=(*prev);
		if((*prev))
			(*prev)->right=root;
		else
			*head=root;
		(*prev)=root;
		intrav(root->right, prev, head);
	}

}
void printit(struct node* head)
{
	while(head!=NULL)
	{
		printf("%d\t", head->data);
		head=head->right;
	}
	printf("\n");
}
int main()
{
	FILE *fp;
	fp=fopen("input.txt", "r");
	char line[100];
	int num[100]; int i=0;
	while(fgets(line, 100, fp)!= NULL)
	{
		num[i]=atoi(line);
		i=i+1;
	}
	//printf("%d", num[i-1]);
	fclose(fp);
	struct node* node1=malloc(sizeof(struct node*));
	/*struct node* node2=malloc(sizeof(struct node*));
	struct node* node3=malloc(sizeof(struct node*));
	struct node* node4=malloc(sizeof(struct node*));
	struct node* node5=malloc(sizeof(struct node*));*/
	node1->data=1;
	/*node2->data=2;
	node3->data=3;
	node4->data=4;
	node5->data=5;
	node4->left=node2;
	node4->right=node5;
	node5->left=NULL;
	node5->right=NULL;*/
	node1->left=NULL;
	node1->right=NULL;
	/*node3->left=NULL;
	node3->right=NULL;
	node2->left=node1;
	node2->right=node3;*/
	struct node* prev=NULL;
	struct node* head=NULL;
	intrav(node1, &prev, &head);
	printit(head);
	return 1;
}
