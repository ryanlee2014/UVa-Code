#include <iostream>
#include <algorithm>
const int maxn=0x3f3f3f3f;
struct Node{
int dis;
int cost;
Node():dis(0),cost(0){}
Node(int d,int c):dis(d),cost(c){}
bool operator < (const Node & v)
{
    return dis<v.dis;
}
};
Node map[1001][1001];
int distD[1001];
int distP[1001];
bool visited[1001];
int main()
{
    int point,r;
    int s,e,d,c;
    while(~scanf("%d%d",&point,&r)&&point!=0&&r!=0)
    {
        for (int i = 0; i <= point; ++i)
        {
            for (int j = 0; j <= point; ++j)
            {
                map[i][j].dis=maxn;
                map[i][j].cost=maxn;
            }
        }
        for (int i = 0; i < r; ++i)
        {
            scanf("%d%d%d%d",&s,&e,&d,&c);
            if(map[s][e].dis>d)
            {
                map[s][e].dis = d, map[s][e].cost = c;
                map[e][s].dis = d, map[e][s].cost = c;
            }
        }
        int x,y;
        scanf("%d%d",&x,&y);
        for (int i = 1; i <=point ; ++i)
        {
            visited[i]=false;
            distD[i]=map[x][i].dis;
            distP[i]=map[x][i].cost;
        }
        visited[x]=true;
        distD[x]=0;
        int min;
        int nextpoint=0;
        for (int i = 1; i <=point ; ++i)
        {
            min=maxn;
            for (int j = 1; j <=point ; ++j)
            {
                if(!visited[j]&&distD[j]<min)
                {
                    min=distD[j];
                    nextpoint=j;
                }
            }
            visited[nextpoint]=true;
            for (int j = 1; j <=point ; ++j)
            {
                if(!visited[j])
                {
                    if(distD[j]>distD[nextpoint]+map[nextpoint][j].dis)
                    {
                        distD[j]=distD[nextpoint]+map[nextpoint][j].dis;
                        distP[j]=distP[nextpoint]+map[nextpoint][j].cost;
                    }
                    else if(distD[j]==distD[nextpoint]+map[nextpoint][j].dis)
                    {
                        if(distP[j]>distP[nextpoint]+map[nextpoint][j].cost)
                            distP[j]=distP[nextpoint]+map[nextpoint][j].cost;
                    }
                }
            }
        }
        printf("%d %d\n",distD[y],distP[y]);
    }
    return 0;
}
