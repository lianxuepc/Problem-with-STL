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
	//n:��Ҫ���ٸ����������Ĳ��㣩��i:��ǰ�ǵڼ�������num:���������ּ� ��Ҳ���������ǵڼ��������� 
	int n,peo[4]={0},i=1,num=1,index=0;
	cin>>n;
	while(i<=n)
	{
		index=index%4;
		if(fun(num)) //Ҫ���� ,peo++
		{
			peo[index]++;
//			printf("num:%d,%d����\n",num,index+1);
		}
		else
		{
			//������������i++ 
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


