#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <cstring>
using namespace std;
struct Node
{
    int id,weight;
    Node(){}
    bool operator<(const Node& v)const
    {
        return weight>v.weight;
    }
};
const int inf=0x3f3f3f3f;
int road,from,target,city;
int graph[1050][1050];
int home[1050],to[1050];
bool visit[1050];
Node node[1050];
priority_queue<Node>q;
inline void init()
{
    memset(graph, inf, sizeof(graph));
    memset(home, 0, sizeof(home));
    memset(to, 0, sizeof(to));
    city = 0;
}
inline void init_dijk()
{
    memset(visit,0, sizeof(visit));
}

void dijkstra(int start)
{
    init_dijk();
    for(int i=0;i<1050;i++)
    {
        node[i].id=i;
        node[i].weight=inf;
    }
    node[start].weight=0;
    q.push(node[start]);
    while(!q.empty())
    {
        Node cur=q.top();
        q.pop();
        int id=cur.id;
        if(visit[id])continue;
        visit[id]=true;
        for(int i=1;i<=city;++i)
        {
            if(!visit[i]&&node[i].weight>node[id].weight+graph[id][i])
            {
                node[i].weight=node[id].weight+graph[id][i];
                q.push(node[i]);
            }
        }
    }
}

int main(void)
{
    int start,end,weight;
    while(~scanf("%d%d%d",&road,&from,&target))
    {
        init();
        for (int i = 0; i < road; ++i)
        {
            scanf("%d%d%d",&start,&end,&weight);
            if(city<start)city=start;
            if(city<end)city=end;
            if(graph[start][end]>weight)
                graph[start][end]=graph[end][start]=weight;
        }
        for (int i = 0; i < from; ++i)
        {
            scanf("%d",&home[i]);
        }
        for (int i = 0; i < target; ++i)
        {
            scanf("%d",&to[i]);
        }
        int max_time=inf;
        for(int i=0;i<from;++i)
        {
            dijkstra(home[i]);
            for(int j=0;j<target;++j)
            {
                if(node[to[j]].weight<max_time)max_time=node[to[j]].weight;
            }
        }
        printf("%d\n",max_time);
    }
    return 0;
}