#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

vector<pair<vector<string>, string>> oplist;

void hefa(char t[])
{
    for (int i = 0; i < strlen(t); i++)
    {
        char p = t[i];
        if (!(p >= 'a' && p <= 'z' || p >= 'A' && p <= 'Z' || p == '/' || p == '-' || p == '_' || p == '.' || p >= '0' && p <= '9'))
        {
            cout << "404 not hefa" << endl;
            return;
        }
    }
}

void splitop(char t[], vector<string> &tv)
{
    string ts;
    string tt=t;
    int flag=0;
    if(t[tt.find(' ')-1]=='/') flag=1;
    char *token = strtok(t, "/");
    while (token)
    {
        ts = token;
        tv.push_back(ts);
        token = strtok(NULL, "/");
    }
    ts = tv.back();
    string ts1(ts, 1, ts.length() - 1);
    tv.pop_back();
    if(flag)
        tv.push_back("/");
    oplist.push_back({tv, ts1});
}

void Pathsplitop(char t[], vector<string> &tv)
{
    string ts;
    char *token = strtok(t, "/");
    while (token)
    {
        ts = token;
        tv.push_back(ts);
        token = strtok(NULL, "/");
    }
    ts = tv.back();
    string ts1(ts, 0, 6), ts2(ts, 7, ts.length() - 6);
    tv.pop_back();
    tv.push_back(ts1);
    oplist.push_back({tv, ts2});
}

int isint(string s)
{
    for (auto i : s)
    {
        if (!(i >= '0' && i <= '9'))
            return 0;
    }
    return 1;
}

int isstr(string s)
{
    for (auto i : s)
    {
        if (i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z')
            return 1;
    }
    return 0;
}

void splitque(char t[], vector<string> &qv)
{
    string ts;
    int flag=0;
    if(t[strlen(t)-1]=='/') flag=1;
    char *token = strtok(t, "/");
    while (token)
    {
        ts = token;
        qv.push_back(ts);
        token = strtok(NULL, "/");
    }
    if(flag) qv.push_back("/");
}

int main()
{
    int n, m; //n规则，m URL地址
    cin >> n >> m;
    cin.ignore();
    while (n--)
    {
        vector<string> tv;
        string opstring;
        char op[110];
        cin.getline(op, 110);
        opstring = op;

        if (opstring.find("<path>") != string::npos)
        {
            Pathsplitop(op, tv);
        }
        else
        {
            splitop(op, tv);
        }
    }
//    for (auto i : oplist)
//    {
//        cout << i.second << ':';
//        for (auto j : i.first)
//        {
//            cout << j << ' ';
//        }
//        cout << endl;
//    }

    while (m--)
    {
        vector<string> qlist;
        string q;
        int flag;
        char que[110];
        cin.getline(que, 110);
        splitque(que, qlist);
        for (auto i : oplist)
        {
            int beg;
            flag=1;
            string str;
          	int pf=0;
        	for(auto j:i.first)
        	{
        		if(j=="<path>")
        		{
        			pf=1;
				}
			}
			if(i.first.size()==qlist.size()||pf)
			{
//				cout<<"yes"<<endl;
			}
			else
			{
//				cout<<"no"<<endl;
				continue;
			}
			
            for (int j = 0; j < i.first.size(); j++)
            {
            	
                if (i.first[j] == "<int>")
                {
                    if (!isint(qlist[j]))
                    {
                        // cout << "no int" << endl;
                        flag=0;
                        break;
                    }
                }
                else if (i.first[j] == "<str>")
                {
                    if (!isstr(qlist[j]))
                    {
                        // cout << "no str" << endl;
                        flag=0;
                        break;
                    }
                }
                else if (i.first[j] == "<path>")
                {
                    beg=j;
                    for(int k=j;k<qlist.size();k++)
                    {
                        str+=qlist[k];
                        str+='/';
                    }
                    flag=2;
                    str.pop_back();
                }
                else
                {
                    if (i.first[j] != qlist[j])
                    {
                        // cout << "no =" << endl;
                        flag=0;
                        break;
                    }
                }
            }
            if(flag==1)
            {
                cout<<i.second<<' ';
                for(int j=1;j<qlist.size();j++)
                {
                    cout<<qlist[j]<<' ';
                }
                cout<<endl;
                break;
            }
            else if(flag==2)
            {
                cout<<i.second<<' ';
                for(int j=1;j<beg;j++)
                {
                    cout<<qlist[j]<<' ';
                }
                cout<<str<<endl;
                break;
            }
        }
        if(!flag) cout<<404<<endl;
    }
    system("pause");
    return 0;
}