#include <iostream>
#include <cstring>
#include <math.h>
#include <unordered_map>
using namespace std;

int h[300];

int main(void)
{
//	unordered_map<int,int> u1;
//	unordered_map<int,int>::iterator it;
	int n,m,L,temp;
	cin>>n>>m>>L;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>temp;
			h[temp]++;
		}
	}
	for(int i=0;i<L;i++)
	{
		cout<<h[i]<<" ";
	}

}


