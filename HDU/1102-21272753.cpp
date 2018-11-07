#include <iostream>
#include <algorithm>
#include <cstring>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;

int cnt;
struct Node
{
    int start, end;
    int weight;
    Node() : start(0), end(0), weight(0)
    {}
    bool operator<(const Node &v) const
    {
        return weight < v.weight;
    }
};
int path[110][110];
int fa[110];
Node node[5500];
int find(int x)
{
    if (x != fa[x])fa[x] = find(fa[x]);
    return fa[x];
}

int main(void)
{
    int size, temp;
    while (~in(size))
    {
        msc(path, 0x3f);
        cnt = 0;
        rep(i, 0, size * size + 1)fa[i] = i;
        rep(i, 1, size + 1) rep(j, 1, size + 1)
            {
                in(temp);
                if(i<j)
                {
                    node[cnt].start = i;
                    node[cnt].end = j;
                    node[cnt++].weight = temp;
                }
            }
        int q;
        in(q);
        while (q--)
        {
            int a, b;
            in(a), in(b);
            fa[find(a)] = find(b);
        }
        int sum = 0;
        sort(node, node + cnt);
        int count = 0;
        rep(i, 0, cnt)
        {
            int x = find(node[i].start);
            int y = find(node[i].end);
            if (x != y)
            {
                sum += node[i].weight;
                fa[x] = y;
                ++count;
                if (count == size - 1)break;
            }
        }
        out(sum);
    }
    return 0;
}