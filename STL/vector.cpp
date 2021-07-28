#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main(void)
{
    vector<int> v0 {0,1,2,3};
    vector<int> v1(20,1);
    vector<int> v2;
    v1.reserve(20);//开辟新空间，会改变元素地址，之前的迭代器失效

    for(int i=1;i<=10;i++)
    {
        v2.push_back(i);
    }
    vector<int>::iterator t;
    t=v2.begin();
    cout<<*t<<endl;
    v2.insert(v2.end(),0);
    cout<<*t<<endl;
    cout<<v2.at(0)<<endl;
    
    // for(auto i=v2.begin();i<v2.end();i++)
    // {
    //     cout<<*i<<endl;
    // }

    // for(int i=0;i<=10;i++)
    // {
    //     cout<<v2[i]<<endl;
    // }

    // vector<int>:: iterator temp;
    // for(temp=v2.begin();temp<v2.end();temp++)
    // {
    //     cout<<*temp<<endl;
    // }
    
    //some operation
    // a.size() 
    // a.empty() 
    // a.clear() 
    // a.swap(b);
    // v2.pop_back();
    // v2.erase(v2.begin());
    // cout<<"容量"<<v2.size()<<endl;
    // printf("begin:%d,end:%d\n",*v2.begin(),*(v2.end()-1));
    system("pause");


}