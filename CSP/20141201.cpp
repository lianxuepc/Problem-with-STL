#include <iostream>
#include <math.h>
#include <cstring> 
#include <unordered_map>
#define N 1100;
using namespace std;

int main(void)
{
	unordered_map<int,int> u1;
	unordered_map<int,int>::iterator it;
	int n,temp;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		it=u1.find(temp);
		if(it==u1.end())
		{
			u1.emplace(temp,1);
//			cout<<"hh"<<endl;
		}
		else
		{
			(it->second)++;
//			cout<<"wuwu"<<endl;
		}
		it=u1.find(temp);
		cout<<it->second<<" ";
		
		
	}
	
	
}

