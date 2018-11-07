#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <cstdlib>
const int inf=0x3f3f3f3f;
struct Node
{
    int id,length;
    Node():id(0),length(inf){}
    Node(int i,int l):id(i),length(l){}
    bool operator<(const Node& v)const
    {
        return length>v.length;
    }
};
int dist[1010],graph[1010][1010];
bool visited[1010];
int station,way,home=-1,possible;

Node node[1010];
using namespace std;
priority_queue<Node>q;
inline void init()
{
    memset(dist,0x3f, sizeof(dist));
    memset(graph,0x3f, sizeof(graph));
}


void Dijkstra(int start)
{
    for (int i = 0; i <=station ; ++i)
    {
        node[i].id=i;
        node[i].length=inf;
    }
    memset(visited,0, sizeof(visited));
    node[start].length=0;
    q.push(node[start]);
    while(!q.empty())
    {
        Node cur=q.top();
        q.pop();
        int id=cur.id;
        if(visited[id])
            continue;
        visited[id]=true;
        for(int i=1;i<=station;++i)
        {
            if(!visited[i]&&node[i].length>node[id].length+graph[id][i])
            {
                node[i].length=node[id].length+graph[id][i];
                q.push(node[i]);
            }
        }
    }
}

int main(void)
{
    int x,y,w;
    while(~scanf("%d%d%d",&station,&way,&home))
    {
        init();
        for (int i = 0; i < way; ++i)
        {
            scanf("%d%d%d",&x,&y,&w);
            if(w<graph[y][x])
            {
                graph[y][x]=w;
            }
        }
        Dijkstra(home);
        scanf("%d",&possible);
        int target;
        int least=inf;
        while(possible--)
        {
            scanf("%d",&target);
            if(node[target].length<least)
            {
                least=node[target].length;
            }
        }
        if(least!=inf)
        {
            printf("%d\n",least);
        }
        else
            puts("-1");
    }
    return 0;
}