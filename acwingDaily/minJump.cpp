#include <iostream>
#include <math.h>
using namespace std;

static int N=11000;

int main(void)
{
    int t,n,x,num[N];
    cin>>t;
    while(t--)
    {
        int flag=0;
        int max=0,ans;
        cin>>n>>x;
        for(int i=1;i<=n;i++)
        {
            cin>>num[i];
            if(max<num[i])
                max=num[i];
            if(num[i]==x)
            {
                flag=1;
                // ans=1;
            }
                
        }
        cout<<"max:"<<max<<"  x:"<<x<<endl;
        if(flag)
            ans=1;

        else if (max==x)
        {
            ans=1;
            cout<<"flag3"<<endl;
        }
            
        else if(max>x)
        {
            ans=2;
            cout<<"flag4"<<endl;
        }
            
        else 
        {
            if(x%max==0)
            {
                ans=x/max;
                cout<<"f1"<<endl;
            }
                
            else
            {
                ans=x/max+1;
                cout<<"f2"<<endl;
            }
                
        }
        cout<<ans<<endl;
    }
    system("pause");
}