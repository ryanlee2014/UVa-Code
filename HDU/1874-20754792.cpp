#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;
const int big=0x3f3f3f3f;
int map[1001][1001];
int main(void)
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        memset(map,big, sizeof(map));
        for (int i = 0; i < 1001; ++i)
        {
            map[i][i]=0;
        }
        for (int i = 0; i < m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(c<map[a][b])
            {
                map[a][b] = c;
                map[b][a] = c;
            }
        }
        for (int k = 0; k <n ; k++)
        {
            for (int i = 0; i <n ; i++)
            {
                for (int j = 0; j <n ; j++)
                {
                    map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
                }
            }
        }
        int start,end;
        scanf("%d%d",&start,&end);
        if(map[start][end]!=big)printf("%d\n",map[start][end]);
        else puts("-1");
    }
    return 0;
}