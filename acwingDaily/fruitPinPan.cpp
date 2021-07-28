#include <iostream>
#include <math.h>
using namespace std;

static int N=100010;

int main(void)
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,c,d,e,f,ans=0;
        cin>>a>>b>>c>>d>>e>>f;
        int flag_e=min(a,d);
        int flag_f;
        //a d   //// bcd
        for(int i=0;i<=flag_e;i++)
        {
            int anse=i*e;
            
            flag_f=min(min(c,b),min(c,d-i));
            int ansf=flag_f*f;
            if (ans<anse+ansf)
                ans=anse+ansf;
            printf("e:%d f:%d ans:%d\n ",i,flag_f,ansf+anse);
        }
        cout<<ans<<endl;

    }
    system("pause");
}