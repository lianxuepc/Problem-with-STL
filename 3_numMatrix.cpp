#include <iostream>
using namespace std;

int main() 
{
    //思路：每次翻转相邻两个正负，所以当负数为偶数时，全为正
            //负数为奇数时，全体中绝对值最小的为负，其他为正。

    int N,n,m;
    cin>>N;
    int w[11][11];
    while(N--)
    {
        cin>>n>>m;
        int count=0,sum=0,min=9999999,temp;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                cin>>temp;
                w[i][j]=temp;
                sum+=abs(temp);
                if(temp>=0)
                    count++;
                if(abs(temp)<min)
                    min=abs(temp);
            }
        }
        if(count%2==0)
            cout<<sum<<"\n";
        else
            cout<<sum-2*min<<"\n";
    }
    system("pause");
    return 0;
}