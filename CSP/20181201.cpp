#include <iostream>
using namespace std;

int main(void)
{
    int r,y,g,n,ans=0;
    cin>>r>>y>>g>>n;
    while(n--)
    {
        int k,t;
        cin>>k>>t;
        switch(k)
        {
            case 0:
                ans+=t;
                break;
            case 1:
                ans=ans+t;
                break;
            case 2:
                ans=ans+t+r;
                break;
            case 3:
                ans=ans;
        }
    }
    cout<<ans<<endl;
    // system("pause");

}