#include <iostream>
#include <list>
using namespace std;

typedef struct summon
{
    int position;
    int heath;
    int attack;
}summon;

// void out(list<summon> &t)
// {
//     if(!t.empty())
//     {
//         for(auto it:t)
//         {
//             printf("(%d %d %d)",it.position,it.attack,it.heath);
//         }
//         cout<<endl;
//     }
// }

void ins(int idx,summon &x,list<summon> &lt)
{
    auto it=lt.begin();
    advance(it,idx-1);
    lt.insert(it,x);
    it=lt.begin();
    if(idx==7)  return;
    advance(it,idx);
    for(auto iter=it;iter!=lt.end();iter++)
    {
        (iter->position)++;
    }
}

int main(void)
{
    list<summon> per0,per1;
    int n,begin=30,end=30,x=0;
    cin>>n;
    while(n--)
    {
        string op;
        cin>>op;
        if(op=="summon")
        {
            summon t;
            cin>>t.position>>t.attack>>t.heath;
            if(!x)//先手
                ins(t.position,t,per0);
            else//后手
                ins(t.position,t,per1);
            
        }

        else if(op=="attack")
        {
            int acter,defer;
            cin>>acter>>defer;
            auto it0=per0.begin(),it1=per1.begin();
            //先手
            if(!x)
            {
                advance(it0,acter-1);
                if(defer==0)
                {
                    end-=it0->attack;
                    it0->heath=0;
                }
                else
                {
                    advance(it1,defer-1);
                    it1->heath-=it0->attack;
                    it0->heath-=it1->attack;
                    printf("per0 %d beat per1 %d\n",it0->position,it1->position);
                    
                }
                
            }
            else
            {
                advance(it1,acter-1);
                if(defer==0)
                {
                    begin-=it1->attack;
                    it1->heath=0;
                }
                else
                {
                    advance(it0,defer-1);
                    it0->heath-=it1->attack;
                    it1->heath-=it0->attack;
                    printf("per1 %d beat per0 %d\n",it1->position,it0->position);
                    
                        
                }
                if(it0->heath<=0)
                {
                    auto haha=per0.erase(it0);
                    while(haha!=per0.end())
                    {
                        haha->position-=1;
                        haha++;
                    }
                }    
                if(it1->heath<=0)
                {
                    auto haha=per1.erase(it1);
                    while(haha!=per1.end())
                    {
                        haha->position-=1;
                        haha++;
                    }
                }
            }
        }
        else
        {
            
            x=!x;
            continue;
        }
        // cout<<"per0: ";
        // out(per0);
        // cout<<"per1: ";
        // out(per1);
    }
    if(end<=0)
    {
        cout<<-1<<endl;
    }
    else if(begin<=0)
    {
        cout<<1<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    cout<<begin<<endl;
    cout<<per0.size()<<" ";
    for(auto it:per0)
    {
        cout<<it.heath<<" ";
    }
    cout<<endl;
    cout<<end<<endl;
    cout<<per1.size()<<" ";
    for(auto it:per1)
    {
        cout<<it.heath<<" ";
    }
    cout<<endl;

}