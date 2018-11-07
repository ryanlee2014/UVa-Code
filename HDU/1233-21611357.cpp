#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=6010;
int m,n;
struct Node{
    int start,end,weight;
    Node(){}
    Node(int s,int e,int w):start(s),end(e),weight(w){}
    bool operator<(const Node& v)const
    {
        return weight<v.weight;
    }
};
int list[maxn];
Node node[maxn];
inline int find(int x)
{
    return list[x]==x?x:find(list[x]);
}

int Kruskal()
{
    int ans=0;
    int x,y;
    for (int i = 1; i <= n; ++i)
    {
        list[i]=i;
    }
    sort(node+1,node+1+m);
    for (int i = 1; i <=m ; ++i)
    {
        x=find(node[i].start);
        y=find(node[i].end);
        if(x!=y)
        {
            ans+=node[i].weight;
            list[x]=y;
        }
    }
    return ans;
}

int main(void)
{
    while(~scanf("%d",&n)&&n)
    {
        m=n*(n-1)/2;
        for (int i = 1; i <= m; ++i)
        {
            scanf("%d%d%d",&node[i].start,&node[i].end,&node[i].weight);
        }
        printf("%d\n",Kruskal());
    }
    return 0;
}