#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int num[1010][1010],qz[1010][1010];

int main(void)
{
	int m,n,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>num[i][j];
			qz[i][j]=num[i][j]+qz[i-1][j]+qz[i][j-1]-qz[i-1][j-1];
			
		}
	}
	while(q--)
	{
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<qz[x2][y2]-qz[x1-1][y2]-qz[x2][y1-1]+qz[x1-1][y1-1]<<endl;
	}
//	cout<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//		{
//			printf("%d ",qz[i][j]);
//			
//		}
//		cout<<endl;
//	}

}


