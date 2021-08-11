#include <iostream>
#include <cmath>
using namespace std;

int a[1100][1100];

int main(void)
{
    int n,ftree=0,all=0,num=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int m,delet=0,re=0;
        cin>>m>>re;
        all+=re;
        // printf("begin:%d\n",re);
        for(int j=1;j<m;j++)
        {
            cin>>a[i][j];
            if(a[i][j]<=0)
                delet+=a[i][j];

            else if(a[i][j]>0)
            {
                if(a[i][j]!=delet+re)
                {
                    // printf("a[i][j]:%d,delet:%d,compare:%d\n",a[i][j],delet,delet+re);
                    a[i][0]=1;
                    // ftree++;
                    delet=a[i][j]-re;
                    
                }
            }
            
        }
        all+=delet;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i+1][0])
            ftree++;
        if(a[i%n+1][0]&&a[(i+1)%n+1][0]&&a[(i+2)%n+1][0])
            num++;
    }
    printf("%d %d %d",all,ftree,num);
    // system("pause");
}