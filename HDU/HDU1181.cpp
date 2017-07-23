#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
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
using namespace std;
struct Node
{
    char s,e;
};
int cnt=0;
Node node[1010];
bool visit[1010],flag;
void dfs(int s)
{
    if(flag)return ;
    if(node[s].e=='m')
    {
        flag=true;
        return ;
    }
    rep(i,0,cnt&&!flag)
        if(node[i].s==node[s].e&&!visit[i])
        {
            visit[i]=true;
            dfs(i);
        }
    }
}
int main(void)
{
    char str[500];
    while(~ins(str))
    {
        ms(node);
        ms(str);
        cnt=0;
        flag=false;
        if(str[0]!='0')
        {
            node[cnt].s=str[0];
            node[cnt++].e=str[strlen(str)-1];
            while(~ins(str)&&str[0]!='0')
            {
                node[cnt].s=str[0];
                node[cnt++].e=str[strlen(str)-1];
            }
        }
        else
            continue;
        rep(i,0,cnt)
        {
            if(node[i].s=='b') {
                ms(visit);
                visit[i] = true;
                dfs(i);
                if (flag) {
                    puts("Yes.");
                    break;
                }
            }
        }
        if(!flag)
        {
            puts("No.");
        }
    }
    return 0;
}