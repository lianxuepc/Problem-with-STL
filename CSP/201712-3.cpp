#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

vector<vector<string>> op;
vector<int> be,en;



int cToi(string a)
{
	int t=0;
	for(auto i:a)
	{
		t*=10;
		t+=(i-'0');
	}
	return t;
}

void time(vector<int> &t,string str)
{
	string t1(str,0,4);
	t.push_back(cToi(t1));
	string t2(str,4,2);
	t.push_back(cToi(t2));
	string t3(str,6,2);
	t.push_back(cToi(t3));
	string t4(str,8,2);
	t.push_back(cToi(t4));
	string t5(str,10,2);
	t.push_back(cToi(t5));
}

void split(char str[])
{
	vector<string> v1;
	char *token=strtok(str," ");
	while(token)
	{
		string t=token;

		v1.push_back(t);
		cout<<v1.back()<<" ";
		token=strtok(NULL," ");
	} 
	op.push_back(v1);
	cout<<endl;
}

int fun(vector<string> v1)
{
	for(int i=0;i<v1.size()-1;i++)
	{
		
	}
}

int main(void)
{
	int n;
	string s,t;
	
	cin>>n>>s>>t;
	cin.ignore();
	for(int i=1;i<=n;i++)
	{
		char str[110];
		cin.getline(str,110);
		split(str);
	}
	
}


