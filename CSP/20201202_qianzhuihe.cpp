#include <iostream>
#include <cstring>
#include <math.h>
#include <map>
#include <utility>
using namespace std;

const int N=1e5+100;
int before[N]={0};
int after[N]={0};

typedef struct stu
{
	int res;
	int flag;
	int count;
}stu;

stu s[N];

int main(void)
{
	int n,ans=0,num=0,hh=0;
	map<pair<int,int>,int> m1;
	map<pair<int,int>,int>::iterator it;
	pair<int,int> p1;
	cin>>n;
	while(n--)
	{
		int res,flag;
		cin>>res>>flag;
		p1=make_pair(res,flag);
		it=m1.find(p1);
		if(it==m1.end())
		{
			m1.emplace(p1,1);
		}
		else
		{
			m1[p1]++;
		}
	}
	
	int j=1;
	for(auto i=m1.begin();i!=m1.end();i++)
	{
//		printf("res:%d,flag:%d,count:%d\n",i->first.first,i->first.second,i->second);
		s[j].count=i->second;
		s[j].res=i->first.first;
		s[j].flag=i->first.second;
//		printf("res:%d,flag:%d,count:%d\n",s[j].res,s[j].flag,s[j].count);
		j++;
	}
	//前缀和 小于且为0的个数 
	j--;
	for(int i=1;i<=j;i++)
	{
		if(s[i-1].flag==0)
		{
			if(s[i-1].res==s[i].res)
			{
				hh=s[i].count;
				before[i]=before[i-1];
			}
			else
			{
				before[i]=before[i-1]+s[i-1].count;
			}
			
		}

		else if(hh)
		{
			before[i]=before[i-1]+hh;
			hh=0;
		}
		else
			before[i]=before[i-1];
//		printf("%d\n",before[i]);
	}
	
	//后缀和，大于等于且为1的个数 
	if(s[j].flag)
		after[j]=s[j].count;
	for(int i=j-1;i>=1;i--)
	{
		if(s[i].flag)
			after[i]=s[i].count+after[i+1];
		else 
			after[i]=after[i+1];
	}
	
	
	for(int i=1;i<=j;i++)
	{
		
		int temp=before[i]+after[i];
		if(temp>=num)
		{
			num=temp;
			ans=s[i].res;
		}
//		printf("before:%d,after:%d,num:%d\n",before[i],after[i],temp);	
		
	}
	cout<<ans<<endl;
	
}


