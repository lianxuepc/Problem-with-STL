#include <iostream>
#include <unordered_set>
#include <cmath>
using namespace std;

const int N=1e5+100;
int num[N];

int main(void)
{
    int n,midi;
    float midf;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>num[i];
    }
    
    if(n%2)
    {
        midi=num[n/2+1];
        
        printf("%d %d %d\n",max(num[1],num[n]),midi,min(num[1],num[n]));
    }
    else
    {
        
        midf=(num[n/2]+num[n/2+1])/2.0;
        if(midf-(int)midf)
            printf("%d %.1f %d\n",max(num[1],num[n]),midf,min(num[1],num[n]));
        else
        {
            midi=(int)midf;
            printf("%d %d %d\n",max(num[1],num[n]),midf,min(num[1],num[n]));
        }
            
    }
   

   
    system("pause");
}