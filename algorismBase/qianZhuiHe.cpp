#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int num[100010]={0},res[100010]={0};

int main(void)
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num[i];
		res[i]=res[i-1]+num[i];
	}
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		cout<<res[r]-res[l-1]<<endl;
	}

}


