#include <iostream>
#include <cstring>
#include <math.h>
#include <set>
#include <utility>
using namespace std;

pair<int ,int > p1,t1,t2,t3,t4;
set<pair<int ,int >> s1;
set<pair<int ,int >>::iterator it;
int main(void)
{
    int n,res[5]={0};
    cin>>n;
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        p1=make_pair(x,y);
        s1.emplace(p1);
    }

    for(auto i=s1.begin();i!=s1.end();i++)
    {
        cout<<i->first<<i->second<<endl;
        int count=0,flag=0;
        t1=make_pair(i->first,(i->second)-1);

        if(s1.end()==s1.find(t1))
            continue;
        // cout<<"flag1"<<endl;
        t2=make_pair((i->first)-1,(i->second));
        if(s1.end()==s1.find(t2))
            continue;
        // cout<<"flag2"<<endl;

        t3=make_pair((i->first)+1,(i->second));
        if(s1.end()==s1.find(t3))
            continue;
        // cout<<"flag3"<<endl;

        t4=make_pair(i->first,(i->second)+1);
        if(s1.end()==s1.find(t4))
            continue;

        // cout<<"hava"<<endl;
        t1.first--;
        t2.second++;
        t3.second--;
        t4.first++;

        if(s1.end()!=s1.find(t1))
            count++;
        if(s1.end()!=s1.find(t2))
            count++;
        if(s1.end()!=s1.find(t3))
            count++;
        if(s1.end()!=s1.find(t4))
            count++;
        res[count]++;
    }
    for(int i=0;i<=4;i++)
    {
        cout<<res[i]<<endl;
    }
    system("pause");
}


