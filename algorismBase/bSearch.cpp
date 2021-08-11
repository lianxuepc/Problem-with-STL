#include <iostream>
#include <cmath>
using namespace std;

// int num[100100]={0};
int num[]={1 ,2 ,2 ,3 ,3 ,4};
int fun(int x,int l,int r)//传入数字,返回下标
{
    // cout<<"调用"<<endl;
    int mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(x==num[mid])
        {
            // printf("flag:%d\n",x);
            return mid;
        }
        else if(num[mid]>x)
        {
            r=mid-1;
        }
        else
            l=mid+1;
    }
    // printf("flag:%d\n",x);
    return -1;
}

int main(void)
{
    cout<<fun(5,0,5);
    // int n,q;
    // cin>>n>>q;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>num[i];
    // }int temp;
    // while(scanf("%d",&temp))
    // {
        
    //     // cin>>temp;
    //     printf("0\n");
    //     printf("find:%d,index:%d\n",temp,fun(temp,0,n-1));
    // }
    // int n,q;
    // cin>>n>>q;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>num[i];
    // }
    // while(q--)
    // {
    //     cout<<"hhhhhhhh"<<endl;
    //     int l=0,r=n-1,x,index;
    //     cin>>x;
    //     index=fun(x,l,r);
    //     l=r=x;
    //     printf("x:%d,index:%d\n",x,index);
    //     if(index==-1)
    //     {
    //         l=-1;
    //         r=-1;
    //     }
    //     else
    //     {
    //         while(l>=0)
    //         {
    //             if(num[l-1]==x) l--;
    //             else break;
    //         }
    //         while(r<n)
    //         {
    //             if(num[r+1]==x) r++;
    //             else break;
    //         }
    //     }
    //     printf("%d %d\n",l,r);
    // }
    system("pause");
}