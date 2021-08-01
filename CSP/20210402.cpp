#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int qianzhui[610][610],num[601][610];

int main(void)
{	
	int n,L,r,t,ans=0,x1,y1,x2,y2;
	float temp, hh;
	cin>>n>>L>>r>>t;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>num[i][j];
			qianzhui[i][j]=num[i][j]+qianzhui[i-1][j]+qianzhui[i][j-1]-qianzhui[i-1][j-1];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			x1=j-r-1;
			y1=i-r-1;
			x2=j+r;
			y2=i+r;
			if(x1<0)
				x1=0;
			if(y1<0)
				y1=0;
			if(x2>n)
				x2=n;
			if(y2>n)
				y2=n;
			hh=(x2-x1)*(y2-y1);
			temp=(qianzhui[x2][y2]+qianzhui[x1][y1]-qianzhui[x2][y1]-qianzhui[x1][y2])/hh;
//			printf("num:%d,i:%d,j:%d,h:%d,temp:%d\n",num[i][j],i,j,hh,temp);
			if(temp<=t)
				ans++;
			
		}
	}
//	for(int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=n;j++)
//		{
//			cout<<qianzhui[i][j]<<" "; 
//		}
//		cout<<endl;
//	}
	cout<<ans<<endl;

}


