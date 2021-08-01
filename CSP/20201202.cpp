#include <iostream>
#include <cstring>
#include <math.h>
#include <map>
#include <utility>
using namespace std;

int main(void)
{
	pair<int,int> p1;
	pair<int,int> pit;
	map<pair<int,int>,int> u1;
	map<pair<int,int>,int>::iterator it;
	int m,a,b,ans=0,num=0;
	cin>>m;
	while(m--)
	{
		cin>>a>>b;
		p1=make_pair(a,b);
		it=u1.find(p1);
		if(it==u1.end())
			u1.emplace(p1,1);
		else
			u1[p1]++;
	}
	
	for(auto i=u1.begin();i!=u1.end();i++)
	{
//		printf("res:%d,flag:%d,num:%d\n",i->first.first,i->first.second,i->second);
	}
	
	for(auto i=u1.begin();i!=u1.end();i++)
	{
		int temp=0;
		for(auto j=u1.begin();j!=u1.end();j++)
		{
			if(j->first.first<i->first.first&&j->first.second==0)
				temp+=j->second;
			else if(j->first.first>=i->first.first&&j->first.second==1)
				temp+=j->second;
		}
		if(temp>num)
		{
			num=temp;
			ans=i->first.first;
		}
		if(temp==num&&ans<i->first.first)
			ans=i->first.first;
//		printf("res:%d,flag:%d,num:%d,ans:%d\n",i->first.first,i->first.second,i->second,ans);
	}
	cout<<ans<<endl;
}


