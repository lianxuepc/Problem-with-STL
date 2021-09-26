#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int main(void)
{
	int n;
	cin>>n;
	cin.ignore();
	while(n--)
	{
		int idx=0;
		char str[1000];
		cin.getline(str,1000);
		cout<<"str len:"<<strlen(str)<<endl;
		while(idx<strlen(str))
		{

		}
		const char din[2]=" ";
		char *token=strtok(str,din);
		while(token)
		{
			
			token=strtok(NULL,din);
		}
		

	}

}