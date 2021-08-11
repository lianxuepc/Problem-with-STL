#include <iostream>
using namespace std;

int num[2000][2000];

int main(void)
{
    //flag is the most delet apple tree,count is the delet num
    int n,m,flag=1,count=0,all=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>num[i][0];//the tree apple
        all+=num[i][0];//all apple
        int temp=0;
        for(int j=1;j<=m;j++)
        {
            cin>>num[i][j];
            temp+=num[i][j];
            all-=num[i][j];
        }
        if(temp<count)
        {
            count=temp;
            flag=i;
        }
    }
    printf("%d %d %d",all,flag,count);
    system("pause");
}