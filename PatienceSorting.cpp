#include<iostream>
#include<conio.h>
using namespace std;
#define MAX 20
struct node
{
    int value;
    struct node* next;
    struct node* back;
};
typedef struct node* STRNODE;
class PatienceSorting
{
    public:
    STRNODE top;
    //STRNODE back;

    public:
    void stack() // constructure
    {
        top=NULL;
    }
    void push(int val); // to insert an element
    int pop();  // to delete an element
    //void show(); // to show the stack
};
void PatienceSorting :: push(int val)
{
    STRNODE obj = new struct node;
    obj->value = val;
    obj->next = NULL;
    if(top != NULL)
    {
        obj->next = top;
    }
    top = obj;
    obj->back=NULL;

}
int PatienceSorting :: pop()
{
    if(top != NULL)
    {
        STRNODE val = top;
        top = top->next;
        return val->value;
    }
    else
        return -1;
}
int main()
{
    int A[MAX],l=0;
    cout<<"Enter the length of the array\n";
    cin>>l;
    for(int i = 0; i<l; i++)
    {
        A[i]=-1;

    }
    cout<<"Enter the array\n";
    for(int i = 0; i<l; i++)
    {
        cin>>A[i];

    }

    PatienceSorting stacks[20];
    int count=0;
    bool flag;
    stacks[count].push(A[0]);
    for(int j=1; j<l; j++)
    {
        flag=true;

        for(int k=0; k<=count; k++)
        {
            if(A[j]<stacks[k].top->value)
            {
                stacks[k].push(A[j]);
                if(k!=0)
                {
                    stacks[k].top->back=stacks[k-1].top;
                }

                flag=false;
                break;
            }

        }
        if(flag)
        {
            stacks[++count].push(A[j]);
            stacks[count].top->back=stacks[count-1].top;
        }


    }
    count++;
    cout<<"Length "<<count<<"\n";
    count--;
    STRNODE p;
    cout<<stacks[count].top->value<<"\n";
    p = stacks[count].top;
    while(p != NULL)
    {
        cout<<p->value;
        p=p->back;

    }
    //cout<<p->value;
    getch();
    return 1;
}
