#include <cstdio>
const int maxn=200010;
using namespace std;
int fa[maxn],s[maxn];
int find(int x)
{
    if(x!=fa[x])
    {
        int temp=fa[x];
        fa[x]=find(temp);
        s[x]+=s[temp];
    }
    return fa[x];
}
int main(void)
{
    int n,m;
    while (~scanf("%d%d",&n,&m))
    {
        for (int i = 0; i <=n ; ++i)
        {
            fa[i]=i,s[i]=0;
        }
        int cnt=0;
        while(m--)
        {
            int x,y,d;
            scanf("%d%d%d",&x,&y,&d);
            int fx=find(--x),fy=find(y);
            (fx==fy&&(s[x]-s[y]!=d)&&++cnt)||(fa[fx]=fy,s[fx]=s[y]-s[x]+d);
        }
        printf("%d\n",cnt);
    }
    return 0;
}