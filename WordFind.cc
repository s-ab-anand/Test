#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
class WordFind
{
    public:
    WordFind(){};
    vector<string> findWords(vector<string> grid, vector<string> wordList);
};
vector<string> WordFind::findWords(vector<string> grid, vector<string> wordList)
{

}
int main()
{
    ifstream myfile("input.txt");
    string str;
    if(myfile.is_open())
    {
        while(myfile.good())
        {
            getline(myfile, str);
        }
        myfile.close();
    }
    return 0;
}
