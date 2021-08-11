#include <iostream>
#include <string>

using namespace std;

void make(string temp,string str,int flag)
{
    string tt=temp,ts=str;

    if(flag)//需要大小写
    {
        if(string::npos!=temp.find(str))
            cout<<temp<<endl;
    }
    else//不用大小写
    {
        //str小写
        for(auto i=ts.begin();i!=ts.end();i++)
        {
            if((*i)>='A'&&(*i)<='Z')
                (*i)+=32;
        }
        //temp小写
        for(auto i=tt.begin();i!=tt.end();i++)
        {
            if((*i)>='A'&&(*i)<='Z')
                (*i)+=32;
        }
        //寻找find函数
        if(string::npos!=tt.find(ts))
        {
            // cout<<tt.find(ts)<<endl;
            cout<<temp<<endl;
        }
            
    }
}

int main(void)
{
    string str,temp;
    int flag,n;
    cin>>str;
    cin>>flag>>n;

    while(n--)
    {
        cin>>temp;
            make(temp,str,flag);
    }   
    system("pause");

}