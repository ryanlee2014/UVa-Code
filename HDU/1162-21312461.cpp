#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
int fa[110];
int point;
struct Node
{
    double x,y;
    int id;
    Node(){}
    Node(double x,double y):x(x),y(y){}
};
Node node[110];
struct Edge
{
    Node u,v;
    double w;
    bool operator<(const Edge& v)const
    {
        return w<v.w;
    }
};
Edge edge[101*101];
int find(int x)
{
    if(x!=fa[x])return fa[x]=find(fa[x]);
    return x;
}
int cnt;

double dist(Node a,Node b)
{
    return sqrt(pow(abs(a.x-b.x),2)+pow(abs(a.y-b.y),2));
}

void connect()
{
    rep(i,0,point)
    {
        rep(j,i+1,point)
        {
            edge[cnt].u=node[i];
            edge[cnt].v=node[j];
            edge[cnt++].w=dist(node[i],node[j]);
        }
    }
}

double Kruskal()
{
    rep(i,0,point)fa[i]=i;
    double ans=0;
    rep(i,0,cnt)
    {
        int fx=find(edge[i].u.id);
        int fy=find(edge[i].v.id);
        if(fx!=fy)
        {
            fa[fx]=fy;
            ans+=edge[i].w;
        }
    }
    return ans;
}

int main(void)
{
    while(~in(point))
    {
        cnt=0;
        rep(i,0,point)
        {
            inf(node[i].x),inf(node[i].y);
            node[i].id=i;
        }
        connect();
        sort(edge,edge+cnt);
        printf("%.2f\n",Kruskal());
    }
    return 0;
}
