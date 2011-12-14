#include<iostream>
#include<fstream>
#include<sstream>
#include<conio.h>
#include<vector>

#define MAX 40
using namespace std;
vector<int> recur(vector <int> height, vector <int> bloom, vector <int> wilt, int n, vector<int> stack);

class FlowerGarden
{
        int l;
        public:
        FlowerGarden(){};
        FlowerGarden(int len)
        {
            l=len;
        }
        vector <int> getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt);
};

vector <int> FlowerGarden::getOrdering(vector <int> height, vector <int> bloom, vector <int> wilt)
{
    vector<int> arrange (height.size());
    vector<int> arrange1(height.size());
    int size=height.size();

    arrange1=recur(height, bloom, wilt, 1, arrange);
    for(int i =0; i<size; i++)
    {
        cout<<arrange.at(i)<<"\n";
    }
    return arrange;
}
vector<int> recur(vector <int> height, vector <int> bloom, vector <int> wilt, int n, vector<int> stack)
{
        if(n==0)
        {
            stack.push_back(height.at(n));

            return recur(height, bloom, wilt, n+1, stack );
        }
                    if(n==(height.size()+1))
                    {
                        return stack;
                    }
                    else
                    {
                        int k=0;
                        bool done=false;
                        while(k<n)
                        {
                            if(!(bloom[k]>wilt[n]||wilt[k]<bloom[n]))
                            {
                                if(height[n]>height[k])
                                {
                                    stack.insert(stack.begin()+k+2, height[n]);
                                    k=k+2;
                                    done=true;
                                }
                            }

                        }
                        if(!done)
                        {
                            int h=0;
                            while(height[h]>height[n])
                             {

                                 h++;
                             }
                             stack.insert( stack.begin()+h+1, height[n]);
                        }
                        return recur(height, bloom, wilt, n+1, stack );
                    }

}
int main()
{
    
    int height1[]={5,4,3,2,1};
    int bloom1[]={1,1,1,1,1};
    int wilt1[]={365,365,365,365,365};
     vector<int> height;
    vector<int> bloom;
    vector<int> wilt;
    for(int i =0; i<5; i++)
    {
        height.push_back(height1[i]);
        bloom.push_back(bloom1[i]);
        wilt.push_back(wilt1[i]);
    }

    FlowerGarden xxx;
    vector<int> max = xxx.getOrdering(height, bloom, wilt);

    getch();
    return 1;
}

