#include <iostream>
#include <string>
#include <string.h>
using namespace std;


int main(void)
{
	string ts;
    char *token=strtok(t,"/");
    while(token)
    {
        ts=token;
        tv.push_back(ts);
        token=strtok(NULL,"/");
    }
    ts=*(tv.end());
    tv.pop_back();
    oplist.push_back({tv,ts});
    cout<<ts<<endl;

}