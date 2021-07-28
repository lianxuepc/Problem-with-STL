#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int arr[20],index=0,ans=0;

int fun(string temp)
{
    int num=0;
    for(int i=0;i<temp.length();i++)
    {
        num=temp[i]-'0';
        arr[index]=num;
        index++;
    }
    return num;
}

int main()
{
    //思路：先将各个字符拿出来，进行运算检验是否正确；
    //0-234-6789a-c
    string str,language,add,num,flag,haha;
    cin>>str;
    //赋值的时候进行截取,从str的第n个往后m个assign(str,n,m);
    language.assign(str,0,1);
    add.assign(str,2,3);
    num.assign(str,6,5);
    flag.assign(str,12,1);

    //使用substr函数进行截取子串,str的从第n到第m个，substr(n,m);
    // language=str.substr(0,1);

    //转换成数字
    int a,b,c,d;
    a=fun(language);
    b=fun(add);
    c=fun(num);
    d=fun(flag);
    // cout<<a<<b<<c<<d<<endl;

    for(int i=0;i<9;i++)
    {
        ans+=arr[i]*(i+1);
        // cout<<arr[i]<<endl;
    }
    ans=ans%11;
    if(ans==10)
        haha="X";
    
    if(haha==flag||ans==arr[9])
    {
        cout<<"Right"<<endl;
    }
    else
    {
        if(ans==10)
            cout<<language<<"-"<<add<<"-"<<num<<"-"<<haha<<endl;
        else
            cout<<language<<"-"<<add<<"-"<<num<<"-"<<ans<<endl;
            
    }
    // cout<<ans%11<<endl;
    // system("pause");
}