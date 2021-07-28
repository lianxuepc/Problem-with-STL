#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;

int main(void)
{
    unordered_map<int,int> u1;
    for(int i=1;i<=100;i++)
    {
        u1.emplace(i,i);
    }
    // for(auto it=u1.begin();it!=u1.end();it++)
    // {
    //     cout<<it->first<<":"<<it->second<<endl;
    // }
    unordered_map<int,int>::iterator t1;
    t1=u1.find(99);
    cout<<t1->second<<endl;
    
    system("pause");
}