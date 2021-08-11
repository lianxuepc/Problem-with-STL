#include <iostream>
using namespace std;

const int N=100100;
int num[N],count[N];

int main()
{
    int n,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }

    for(int i=1,j=1;i<=n;i++)
    {
        count[num[i]]++;
        while(j<=i&&count[num[i]]>1)//当num[i]重复时
        {
            count[j]--;
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans<<endl;
}