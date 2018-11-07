#include <bits/stdc++.h>
using namespace std;
int n;
int cnt=0;
int ans[100];
int vis[1010];
int kase=0;
bool isprime[1010];
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
void dfs(int step,int pos)
{
    ans[step]=pos;
    vis[pos]=1;
    if(step==n)
    {
        if(isprime[ans[n]+ans[1]])
        {
            if(cnt==0)
            {
                printf("Case %d:\n",++kase );
            }
            ++cnt;
            for(int i=1;i<=n;++i)
            {
                printf("%d%c",ans[i]," \n"[i==n]);
            }
        }
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(vis[i]||!isprime[i+ans[step]])continue;
        dfs(++step,i);
        --step;
        vis[i]=0;
    }
}

int main()
{
    for(int i=0;i<13;++i)
    {
        isprime[prime[i]]=true;
    }
    while(cin>>n)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;
        dfs(1,1);
        puts("");
    }
}