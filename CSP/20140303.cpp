#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <utility>
using namespace std;


char top[100];
string no,yes;
vector<pair<string,string>> v1;
vector<string> list;
void getOp()// get op list
{
    for(int i=0;i<strlen(top);i++)
    {
        if(top[i+1]==':')
        {
            yes.append(1,top[i]);
            i+=1;
        }
        else
        {
            no.append(1,top[i]);
        }
    }
    // cout<<"no:"<<no<<", yes:"<<yes<<endl;
}

void getList(string temp)
{

}

void analy(string temp)
{
    for(auto i=temp.begin();i!=temp.end();i++)
    {
        if(*i=='-')
        {

        }
    }
}

int main(void)
{
    
    scanf("%s",top);
    int n;
    cin>>n;
    getOp();
    while(n--)
    {
        string temp;
        cin>>temp;
        getList(temp);
    }
    system("pause");

}