#include <bits/stdc++.h>
using namespace std;

const int N=1e6;
int a[N];

int fun(int num[],int n)
{
    int ans=0;
    for(int i=1;i<n;i++)
    {
        if(!num[i]&&num[i+1])
            ans++;
    }

}


int main(void)
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<fun(a,n)<<endl;;

    system("pause");
    return 0;
}