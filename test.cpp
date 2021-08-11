#include <iostream>
#include <math.h>
#include <cstring> 
#include <unordered_map>
#include <vector>
#define N 1100;
using namespace std;

int main(void)
{
	string temp("ls -a -l -a documents -b"),op("albwx");
	vector<string> opList;
	for(int i=0;i<temp.length();i++)
	{
		int j=temp.find_first_of(' ',i),k=temp.find_first_of(' ',j+1);
		cout<<j<<" "<<k<<endl;
		if(j!=string::npos)
			i=j;
		if(k!=string::npos)
		{
			
		}
		
		
	}
	system("pause");
}
