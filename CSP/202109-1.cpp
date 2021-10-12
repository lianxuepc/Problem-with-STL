#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;

int a[N],b[N],summax,summin;

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        summax+=b[i];
    }
    summin=b[1];
    for(int i=2;i<=n;i++)
    {
        if(b[i]==b[i-1])
            summin+=0;
        else
            summin+=b[i];
    }
    cout<<summax<<endl;
    cout<<summin<<endl;

system("pause");
    return 0;
}