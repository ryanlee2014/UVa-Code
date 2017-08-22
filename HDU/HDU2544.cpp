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
    while(~scanf("%d%d",&n,&m),n&&m)
    {
        memset(map,big, sizeof(map));
        for (int i = 0; i < m; i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            map[a][b]=c;
            map[b][a]=c;
        }
        for (int k = 1; k <=n ; k++)
        {
            for (int i = 1; i <=n ; i++)
            {
                for (int j = 1; j <=n ; j++)
                {
                    map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
                }
            }
        }
        printf("%d\n",map[1][n]);
    }
    return 0;
}
