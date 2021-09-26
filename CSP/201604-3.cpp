#include <iostream>
#include <deque>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

char hh[1100];
char op[1100];//处理的地址
vector<string> root;
vector<string> oplist;//分割后的地址
//..上一级，.本目录，//是/

//不包括. .. 的绝对路径，不包括多个/，去掉末尾的/(目录），根目录是/,空字符串为当前目录 
void splitroot(char rec[])
{
	const char din[2]="/";
	char *token=strtok(rec,din);
	// cout<<"root: ";
	while(token)
	{
		root.push_back(token);
		token=strtok(NULL,din);
	}
	
}
void splitop()
{
	const char din[2]="/";
	char *token=strtok(op,din);
	// cout<<"oplist:";
	while(token)
	{
		oplist.push_back(token);
		// cout<<oplist.back()<<" ";
		token=strtok(NULL,din);
	}
	// cout<<endl;
}

int main()
{
	int n,flag=0;
	cin>>n;
	char rec[1100];
	cin>>rec;
	
	splitroot(rec);
	cin.ignore();
	
	while(n--)
	{
		
		oplist.clear();
		vector<string> ans;
		cin.getline(op,1100);
		if(op[0]=='/') flag = 1;
		else if(op[0]=='.') flag = 2;
		splitop();

		//flag=1,从根目录开始
		if(flag==1)
			for(auto it:oplist)
			{
				if(it==".")
				{
					// cout<<". ";
					continue;
				}
					
				else if(it=="..")
				{
					// cout<<"..pop ";
					if(!ans.empty()) ans.pop_back();
				}
				else
				{
					// cout<<it<<"push ";
					ans.push_back(it);
				}
					
			}
		else if(flag==2)
		{
			// cout<<"..begin,ans is ";
			ans=root;
			for(auto it:ans)
			{
				// cout<<it<<" ";
			}
			// cout<<endl;
			for(auto it:oplist)
			{
				if(it==".")
					continue;
				else if(it=="..")
				{
					if(!ans.empty()) ans.pop_back();
				}
				else
					ans.push_back(it);
			}
		}
		else
		{
			
			for(auto it:root)
			{
				cout<<"/"<<it;
			}
			cout<<endl;
			continue;
		}

		if(ans.empty())
		{
			cout<<"/"<<endl;
			continue;
		}
		for(auto it:ans)
		{
			cout<<"/"<<it;
		}
		cout<<endl;
	}
	

	system("pause");
	return 0;
}