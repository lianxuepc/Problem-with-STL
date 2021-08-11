#include <iostream>
using namespace std;

int r,y,g,n;
long long ans=0;

int fun(int k)
{
    if(0<=k&&k<g)
        return 0;
    else if(g<=k&&k<g+y)
        return g+y+r-k;
    else
        return g+y+r-k;
}

int getTime(int k,int t)
{
    int time=r+y+g;
    if(k==1)//r
    {
        k=r-t+g+y;
        k=(k+ans)%time;
        return fun(k);
    }
    else if(k==2)//y
    {
        k=y-t+g;
        k=(k+ans)%time;
        return fun(k);

    }
    else if(k==3)
    {
        k=g-t;
        k=(k+ans)%time;
        return fun(k);

    }
    
}

int main(void)
{
    
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
                ans+=getTime(k,t);
                break;
            case 2:
                ans+=getTime(k,t);
                break;
            case 3:
                ans+=getTime(k,t);
                break;
        }
        // printf("the ans: %d\n",ans);
    }
    cout<<ans<<endl;
    // system("pause");

}