#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int num[100010],cf[100010];

void outCf(int n)
{
	cout<<"cf: ";
	for(int i=1;i<=n;i++)
	{
		cout<<cf[i]<<" ";
	}
	cout<<endl;
}

void outNum(int n)
{
	cout<<"num: ";
	for(int i=1;i<=n;i++)
	{
		cout<<num[i]<<" ";
	}
	cout<<endl;
}

void outRes(int n)
{
	cout<<"res: ";
	for(int i=1;i<=n;i++)
	{
		num[i]=cf[i]+num[i-1];
		cout<<temp<<" ";
	}
	cout<<endl;
}

int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		cf[i]=num[i]-num[i-1];
	}
//	outCf(n);
////	outNum(n);
//	outRes(n);
	
	while(m--)
	{
		int l,r,c;
		cin>>l>>r>>c;
		cf[l]+=c;
		cf[r+1]-=c;
//		outCf(n);
//		outNum(n);
	
	}
		outRes(n);

}


