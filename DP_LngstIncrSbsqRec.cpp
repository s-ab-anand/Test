#include<iostream>
#include<conio.h>
using namespace std;
int longest1(int A[], int n, int N);
int main()
{
    int n;
    cout<<"Enter the length of number array";
    cin>>n;
    int A[10], S[10];
    int i;
    for(i=0; i<n; i++)
    {
        cout<<" Enter the number: ";
        cin>>A[i];
        cout<<"\n";
        S[i]=1;
    }

    max=longest1(A, 0, n);
    cout<<"\nmax="<<max;
    return 1;
}
int longest1(int A[], int n, int N)
{

    if(n==(N+1))
    {
        //int max=1;
        return max;
    }
    else if(n==0)
    {
        return 1;
    }
    else
    {
        int max=longest1(A, n-1, N);
        int L = 1+longest1(A, n-1, N);
        if(A[n]>A[n-1])
        {
            if(max<L)
            {
                max=L;
            }
        }
    }
    return max;
}

