#include <iostream>
#include <math.h>
using namespace std;

static int N=210;

int main(void)
{
    int t,num[N];
    while(t--)
    {
        int n,a=0,b=0,ans,take[N];
        cin>>n;
        char str[N];
        for(int i=1;i<=n;i++)
        {
            cin>>str[i];
            if(str[i]=='w')
                a++;
            else if(str[i]=='B')
                b++;
        }
        if(a%2 && b%2)
        {
            ans=-1;
            cout<<0<<endl;
        }
        else 
        {
            
        }
        
    }
}


