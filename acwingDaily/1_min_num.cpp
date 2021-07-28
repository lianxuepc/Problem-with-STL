#include <iostream>
#include <algorithm>
#include<vector>
#include <cstring>
#include<unordered_map>//hash
using namespace std;

typedef unordered_map<int ,int> int_map;
const int N = 200010;

int n;
int w[N],cnt[N];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        memset(cnt,0,(n+1)*4);
        for(int i=0;i<n;i++)
        {
            cin>>w[i];
            cnt[w[i]]++;
        }
        int res=-1;
        for (int i=0;i<n;i++)
        {
            if(cnt[w[i]]==1)
            {
                if(res==-1||w[res]>w[i])
                    res=i;
            }
        }
        if (res!=-1) res++;
        printf("%d\n",res);
    }
return 0;
}