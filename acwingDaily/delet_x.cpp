#include <iostream>
using namespace std;

static int N=110;

int main(void)
{
    int n,ans=0;
    char str[N];
    cin>>n;
    cin>>str;
    // cout<<str[1];
    for(int i=1;i<n-1;i++)
    {
        int temp=0;
        if(str[i]=='x'&&str[i-1]=='x'&&str[i+1]=='x')
        {
            // cout<<"µÚÒ»´Î"<<i<<endl;
            for(int j=i-1;j<n;j++)
            {
                if(str[j]=='x')
                {
                    temp++;
                }
                else
                    break;
            }
        }
        // cout<<"temp:"<<temp<<endl;
        if(temp>0)
        {
            ans+=temp-2;
            i=i+temp-2;
            cout<<i<<endl;
        }
        
    }
    cout<<ans;
    system("pause");
}