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
        for (int i = 0; i < m; i++)
        {
            int a,b,c;
            scanf("%d%d",&a,&b);
            map[a][b] = 1;
            map[b][a] = 1;
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
        bool legal=true;
        for (int i = 0; i < n; ++i)
        {
            if(!legal)break;
            for (int j = 0; j < n; ++j)
            {
                if(i!=j)
                {
                    if(map[i][j]>7)
                    {
                        legal=false;
                        break;
                    }
                }
            }
        }
        puts(legal?"Yes":"No");
    }
    return 0;
}