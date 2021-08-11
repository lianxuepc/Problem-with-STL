#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int fun(int x)
{
	if(x%7==0)
		return 1;
	while(x>0)
	{
		int temp=x%10;
		if(temp==7)
			return 1;
		x=x/10;
	}
	return 0;
		
}

int main(void)
{
	//n:需要多少个数（跳过的不算），i:当前是第几个数，num:现在是数字几 ，也即是现在是第几个人在玩 
	int n,peo[4]={0},i=1,num=1,index=0;
	cin>>n;
	while(i<=n)
	{
		index=index%4;
		if(fun(num)) //要跳过 ,peo++
		{
			peo[index]++;
//			printf("num:%d,%d号跳\n",num,index+1);
		}
		else
		{
			//不跳过，计数i++ 
			i++;
		}	
			
		index++;
		num++;	
			
	}
	
	for(int j=0;j<4;j++)
	{
		cout<<peo[j]<<endl;
		
	}

}


