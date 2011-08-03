#include<iostream>
#include<fstream>
#include<sstream>
#include<conio.h>
#define MAX 100
using namespace std;
int main()
{
    string str;
    int n=0;
    int A[MAX];
    int S[MAX], diff[MAX];

    ifstream myfile("input.txt");
    if(myfile.is_open())
    {
        while ( myfile.good() )
        {
          getline (myfile, str, ',');
          //n++;
          stringstream ss(str);
          int il;
          ss>>il;
          cout << il << endl;
          A[n++]=il;
        }
        myfile.close();
    }

    else cout << "Unable to open file";


    for(int i=0; i<n; i++)
    {
        S[i]=1;
        diff[i]=-1;
    }
    for(int a = 1; a<n; a++)
    {
        diff[a-1]=A[a]-A[0];
        S[a]=S[a]+1;
    }
    for(int j=0; j<n; j++)
    {
        for(int k = j+1; k<n; k++)
        {
            if((A[k]-A[j])*diff[j] < 0)
            {
                if(S[k]<S[j]+1)
                {
                    S[k]=S[j]+1;
                }
            }
            diff[k]=A[k]-A[j];
        }

    }
    int max = S[0];
    for(int l=1 ; l<n; l++)
    {
        if(S[l]>max)
        {
            max=S[l];
        }
    }
    cout<<"\nmax="<<max;
    return 1;
}

