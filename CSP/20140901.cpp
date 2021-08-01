#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int num[1010];

int main(void)
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    sort(num+1,num+n+1);
    for(int i=1;i<n;i++)
    {
        if(abs(num[i]-num[i+1])==1)
            ans++;
    }
    cout<<ans<<endl;
    system("pause");
}