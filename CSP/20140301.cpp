#include <iostream>
#include <cstring>
#include <unordered_map>
#include <math.h>
using namespace std;

static int N=1010;

int main(void)
{
    
    int num[N], n,ans=0;
    memset(num,0,N*4);
    cin>>n;
    //做法1，hash，因为绝对值不超过1000，开一个1000的数组即可。
    // for(int i=1;i<=n;i++)
    // {
    //     int temp;
    //     cin>>temp;
    //     temp=abs(temp);
    //     if(num[temp])
    //     {
    //         ans++;
    //     }
    //     else
    //         num[temp]=temp;
    // }


    //做法2：如果数很大，开的空间会浪费很多，所以用unoeder_map(hash)
    unordered_map<int,int> mYmap;
    unordered_map<int,int>::iterator it=mYmap.end();
    
    for(int i=1;i<=n;i++)
    {
        int temp,t;
        cin>>temp;
        t=abs(temp);
        if(it==mYmap.find(t))
            mYmap.emplace(t,temp);
        else
            ans++;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
    
}