#include <bits/stdc++.h>
using namespace std;

stack<char> stk;
stack<int> num;
string mid="a+b-a*((c+d)/e-f)+g";
string beh;
map<char,int> op;
string::iterator it=mid.begin(); 

/**
�� ֱ����ջ
�������
����Ƿ��ţ���<=���ȼ������
)���ֱ�� ( 
**/ 

int main(void)
{
	op['(']=0;
    op[')']=0;
    op['+']=1;
    op['-']=1;
    op['*']=2;
    op['/']=2;
    
	for(auto it=mid.begin();it!=mid.end();it++)
	{
		char t=(*it);
		//��op 
		cout<<t<<" ";
		if(op.count(t))
		{
			
			//)
			if(t==')')
			{
				while(stk.top()!='(')
				{
					
					beh+=stk.top();
					stk.pop();
				}
				stk.pop();
			}
			//+-*/ ���ȼ���ֱ����ջ ,(ֱ����ջ 
			else if(stk.empty()||t=='('||op[t]>op[stk.top()])
			{
				stk.push(t);
			}
			
			else if(op[stk.top()]>=op[t])
			{
				while((!stk.empty())&&op[stk.top()]>=op[t])
				{
					beh+=stk.top();
					stk.pop();
				}
				stk.push(t);
			}
		}
		//���� 
		else
		{
			beh+=t;
		}
	}
	while(!stk.empty())
	{
//		cout<< 4<<endl;
		beh+=stk.top();
		stk.pop();
	}
	cout<<beh;
	return 0;
}


