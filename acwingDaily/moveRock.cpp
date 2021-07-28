#include <iostream>
using namespace std;

static int N=110;

int main(void)
{
    int T,n,d,ans=0,num[N];
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cin>>n>>d;
        ans=0;
        for(int j=0;j<n;j++)
        {
            cin>>num[j];
        }
        //原本就有的石子
        ans+=num[0];
        // cout<<"原来有石子："<<ans<<endl;
        int use=0;
        for(int j=1;j<n;j++)
        {
            
            for(int k=1;k<=num[j];k++)
            {
                // printf("j:%d,d:%d\n",j,d);
                d=d-j;
                if(d>=0)
                    ans++;
                else
                    break;
            }


        }
        cout<<ans<<endl;
    }
}