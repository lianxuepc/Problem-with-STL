#include <iostream>
#include <stack>
using namespace std;

int n[5];
char c[4],str[8];
stack<int> stn;
stack<char> stc;

/*
empty() 堆栈为空则返回真

pop() 移除栈顶元素

push() 在栈顶增加元素

size() 返回栈中元素数目

top() 返回栈顶元素
*/

void getNum()
{
    for(int i=1;i<=4;i++)
    {
        n[i]=str[i*2-1]-'0';
        stn.push(n[i]);

    }
}

void getChar()
{
    for(int i=1;i<=3;i++)
    {
        n[i]=str[2*i]-'0';
        stc.push(n[i]);
    }
}

int ans()
{
    int a1,a2,a3;
    if(c[1]=='/'||c[1]=='*')
    {
        a1=
    }
}

int main(void)
{
    int m;
    cin>>m;
    while(m--)
    {
        getNum();
        getChar();
        if(ans()==24)
            cout<<"Yes"<<endl
        else
            cout<<"No"<<endl;
    }
}