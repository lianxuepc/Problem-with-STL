#include <bits/stdc++.h>
using namespace std;

map<string, int> powermap;
map<string, map<string, int>> rolemap; //{str:<>}
map<string, vector<string>> usermap;
void split(char str[], const char din[])
{
    char *token = strtok(str, din);
    while (token)
    {
        ///
        token = strtok(NULL, din);
    }
}

void getop(string str, pair<string, int> &tp)
{
    string op;
    int idx = -1;
    for (auto it : str)
    {
        if (it >= 'a' && it <= 'z')
        {
            op += it;
        }
        else if (it >= '0' && it <= '9')
        {
            idx = it - '0';
        }
    }
    tp = {op, idx};
}

int main(void)
{
    int p, r;
    cin >> p; //p段
    while (p--)
    {
        string str, op;
        pair<string, int> temp;
        cin >> str;
        getop(str, temp);
        powermap.emplace(temp.first, temp.second);
    }

    //R段
    cin >> r;
    while (r--)
    {
        string role;
        map<string, int> m1;
        int count;
        cin >> role >> count;
        while (count--)
        {
            string str;
            pair<string, int> temp;
            cin >> str;
            getop(str, temp);
            m1.emplace(temp.first, temp.second);
        }
        rolemap.emplace(role, m1);
    }

    // for(auto it:rolemap)
    // {
    //     cout<<it.first<<" ";
    //     for(auto iter:it.second)
    //     {
    //         cout<<iter.first<<' '<<iter.second<<' ';
    //     }
    //     cout<<endl;
    // }

    //user
    int t;
    cin >> t;
    while (t--)
    {
        vector<string> v1;
        string name;
        int count;
        cin >> name >> count;
        while (count--)
        {
            string str;
            cin >> str;
            v1.push_back(str);
        }
        usermap.emplace(name, v1);
    }

    // for(auto it:usermap)
    // {
    //     cout<<it.first<<' ';
    //     for(auto iter:it.second)
    //     {
    //         cout<<iter<<' ';
    //     }
    //     cout<<endl;
    // }

    //que
    int q;
    cin >> q;
    while (q--)
    {
        string name, str;
        cin >> name >> str;
        pair<string, int> p1;
        getop(str, p1);
        //usermap<name:[role]}
        //如果用户不存在,权限不存在
        if (usermap.find(name) == usermap.end() || powermap.find(p1.first) == powermap.end())
        {
            cout << "no user/role false" << endl;
            continue;
        }

        string power = p1.first;
        int powerrand = powermap[p1.first];
        int querand = p1.second;
        //权限无等级
        if (powerrand == -1)
        {
            int flag=0;
            for (auto i : usermap[name]) //role
            {
                for (auto j : rolemap[i])
                {
                    if (j.first == power)
                    {
                        cout << "no rand true" << endl;
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag) cout << "no rank false" << endl;
            continue;
        }
        if(powerrand!=-1&&querand==-1)
        {
            int ans=0;
            for (auto i : usermap[name]) //role
            {
                for (auto j : rolemap[i])
                {
                    if (j.first == power && ans < j.second)
                    {
                        ans=j.second;
                        cout<<"!!!!!!!!!!!"<<endl;
                    }
                }
            }
            cout<<ans<<endl;
            continue;
        }
        else
        {
            
            int ans = -2,flag=0;
            if(querand==-1) flag=1;
            for (auto i : usermap[name]) //role
            {
                for (auto j : rolemap[i])
                {
                    if (j.first == power && querand <= powerrand)
                        if (querand > ans)
                        {
                            ans = querand;
                        }
                }
            }
            if(ans==-2)
            {
                cout<<"false"<<endl;
            }
            else
            {
                cout<<"true"<<endl;
            }
        }
    }

    system("pause");
    return 0;
}