#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

static int N=104;

int main(void)
{
    int n,a[N],b[N];

    int x=0,y=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }

    for(int i=1;i<=n;i++)
    {

        if(a[i]>b[i])
            x++;
        if(a[i]<b[i])
            y++;
        // printf("a:%d b:%d x:%d y:%d \n",a[i],b[i],x,y);
    }
    if (x==0)
        printf("%d",-1);

    else if (x>y) cout<<1;

    
    else if(x<=y) cout<<int(y/x)+1;
    system("pause");
}

