#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main(void)
{
	int n,ans=0,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		ans+=a*b;
	}
	ans=ans>0?ans:0;
	cout<<ans;
	
}


