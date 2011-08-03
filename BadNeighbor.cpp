#include<iostream>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<vector>

//#include<BadNeighbor.h>
#define MAX 40
using namespace std;

class BadNeighbor{

    //vector<int> array;
    int length;
    public:
        BadNeighbor(){};
        BadNeighbor(int len){length = len;};
        int maxDonations(int donations[]);

};

int BadNeighbor::maxDonations(int donations[])
{
    int  max=0;
    int sum[MAX], don[MAX];
    //cout<<"length"<<length;
    for(int i = 0; i<length; i++)
    {
        sum[i]=donations[i];
        don[i]=1;
        //sum[i]=0;
    }
    for(int i = 0; i<length; i++)
    {

        //int prev = i;
        for(int j = i+1; j<length-1; j++)
        {
            if(j!=(i+1))
            {
            if(sum[j-1]<(sum[i]+donations[j]))
            {
                sum[j]=sum[i]+donations[j];

            }
            }
        }
    }

    for(int k=0; k<length; k++)
    {
        if(sum[k]>max)
            max=sum[k];
    }
    int max1=0;
    for(int i = 0; i<length; i++)
    {
        sum[i]=donations[i];
        don[i]=1;
        //sum[i]=0;
    }
    for(int i = 1; i<length; i++)
    {

        //int prev = i;
        for(int j = i+1; j<length; j++)
        {

            if(j!=(i+1))
            {

            if(sum[j]<(sum[i]+donations[j]))
            {
                sum[j]=sum[i]+donations[j];

            }
            }
        }
    }
    for(int k=0; k<length; k++)
    {
        if(sum[k]>max1)
            max1=sum[k];
    }
    return (max>max1?max:max1);
}


int main()
{
    string str;
    int n=0;
    //vector<int> dont;
    int length;
    int donations[MAX];
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
          //dont.push_back(il);
          donations[n++]=il;
          length=n;

        }
        myfile.close();
    }

    else cout << "Unable to open file";

    BadNeighbor xxx = BadNeighbor(length);
    int max = xxx.maxDonations(donations);
    cout<<"\nMaximum donations= "<<max<<"\n";
    getch();
    return 1;
}
