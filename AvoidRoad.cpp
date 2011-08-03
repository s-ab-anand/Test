#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class AvoidRoads {
    int _width;
    int _height;
public:
    void AvoidRoad(int w, int h){
        _width=w;
        _height=h;
    }
	long long numWays(int, int, vector <string>);
};

long long AvoidRoads::numWays(int width, int height, vector <string> bad) {

    if(width==0 && height==0)
    {
        return 0;
    }
    std::string s1, s2, s3, s4, s5, s6;
    std::stringstream out1, out2, out3, out4, out5, out6;
    out1 << width-1;
    s1 = out1.str();
    out2 << height-1;
    s2 = out2.str();
    out3 << width;
    s3 = out3.str();
    out4 << height;
    s4 = out4.str();
    out5 << height+1;
    s5 = out5.str();
    out6 << width+1;
    s6 = out6.str();

    long long count1=0;
    long long count2=0;
    long long count3=0;
    long long count4=0;
    long long count5=0;
    if(width+1 <= _width )
    {
        std::string s, ss;
        bool flag=false;
        s = s6+" "+s4+" "+s3+" "+s4;
        ss = s3+" "+s4+s6+" "+s4;
        for(int i=0; i<bad.size(); i++)
        {
            if(s.compare(bad.at(i))==0 || ss.compare(bad.at(i))==0)
            {
                flag=true;
            }
        }
        if(!flag)
        {
            count1 = 1+numWays(width+1, height, bad);
        }
    }
    if(height+1 <= _height )
    {
        std::string s, ss;
        bool flag=false;
        s = s3+" "+s5+" "+s3+" "+s4;
        ss = s3+" "+s4+s3+" "+s5;
        for(int i=0; i<bad.size(); i++)
        {
            if(s.compare(bad.at(i))==0 || ss.compare(bad.at(i))==0)
            {
                flag=true;
            }
        }
        if(!flag)
        {
            count2 = 1+numWays(width, height+1, bad);
        }
    }
    if((width-1)<0)
    {
        std::string s, ss;
        bool flag=false;
        s = s3+" "+s4+" "+s1+" "+s4;
        ss = s1+" "+s4+" "+s3+" "+s2;
        for(int i=0; i<bad.size(); i++)
        {
            if(s.compare(bad.at(i))==0 || ss.compare(bad.at(i))==0)
            {
                flag=true;
            }
        }
        if(!flag)
        {
            count3 = 1+numWays(width-1, height, bad);
        }
    }
    if((height-1)<0)
    {
        std::string s, ss;
        bool flag=false;
        s = s3+" "+s2+" "+s3+" "+s4;
        ss = s3+" "+s4+" "+s3+" "+s2;
        for(int i=0; i<bad.size(); i++)
        {
            if(s.compare(bad.at(i))==0 || ss.compare(bad.at(i))==0)
            {
                flag=true;
            }
        }
        if(!flag)
        {
            count4 = 1+numWays(width, height-1, bad);
        }
    }

    return count1+count2+count3+count4;

}
int main()
{
    AvoidRoads a;
    int width = 6;
    int height = 6;
    a.AvoidRoad(6,6);
    vector<string> bad;
    bad.push_back("0 0 0 1");
    bad.push_back("6 6 5 6");
    int count=a.numWays(width, height, bad);
    cout<<"No. of ways= "<<count;
    return 1;

}


