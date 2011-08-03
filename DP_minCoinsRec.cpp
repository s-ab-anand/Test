#include<iostream>
#include<conio.h>
using namespace std;
//void Min(int Sum[], int V, int curr);
/*int main()
{
    int V[10];
    int n, Sum[20];
    int S=0;
    cout<<"Enter the number of coins\n";
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"value of coin "<<i+1<<":";
        cin>>V[i];
        cout<<"\n";
    }
    cout<<"Enter the Sum\n";
    cin>>S;

    for(int k=0;k<20;k++)
    {
        Sum[k]=10000;
    }

    Sum[0]=0;
    for(int i = 0; i<n; i++)
    {
        Min(Sum, V[i], S);

    }
    cout<<"Answer is "<<Sum[S];
    getch();
    return 1;
}
void Min(int Sum[], int V, int curr)
{
    int min;
    if(curr>=0)
    {   if(curr==0)
        {
            Sum[curr]=0;
        }
        else
        {
            if((curr-V)>= 0)
            {
                Min(Sum, V, curr-V);
                min = Sum[curr-V]+1;
            }
            else
            {
                min = Sum[curr];
            }
            if(Sum[curr]>min)
            {
                Sum[curr]=min;
                cout<<"Value of Sum["<<curr<<"] is"<<min<<"\n";
            }
        }
    }
}
*/
