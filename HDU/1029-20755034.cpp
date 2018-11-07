#include <cstdio>
using namespace std;
int main(void)
{
    int t;
    while(~scanf("%d",&t))
    {
        int cnt=0,num,cur;
        for (int i = 0; i < t; ++i)scanf("%d",&cur),cnt==0?(num=cur,++cnt):(cur==num?++cnt:--cnt);
        printf("%d\n",num);
    }
    return 0;
}