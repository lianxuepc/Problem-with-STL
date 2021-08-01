#include <iostream>
#include <math.h>
#include <cstring> 
using namespace std;


int flag[110][110];
int main(void)
{
	int n,x1,y1,x2,y2,ans=0;
	cin>>n;
	
	while(n--)
	{
		cin>>x1>>y1>>x2>>y2;
		for(int i=x1;i<x2;i++)
		{
			for(int j=y1;j<y2;j++)
			{
				flag[i][j]=1;
			}
		}
		
		
	}
	for(int i=0;i<110;i++)
		{
			for(int j=0;j<110;j++)
			{
				if(flag[i][j]==1)
					ans++; 
			}
		}
	cout<<ans<<endl;
	
	
	
	
	
}
