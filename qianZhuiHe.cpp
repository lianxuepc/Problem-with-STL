#include <iostream>
using namespace std;


int main(void)
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        arr[i]=i;
    }

    int sum[10];
    sum[0]=arr[0];
    for(int i=1;i<10;i++)
    {
        sum[i]=sum[i-1]+arr[i];
    }

    int chafen[10];
    chafen[0]=arr[0];
    for(int i=1;i<10;i++)
    {
        chafen[i]=arr[i]-arr[i-1];
    }

    //��֣���L R�����е�������ͬʱ�Ӽ���ֻҪchafen[L]+v,chafen[R+1]-v
    
}