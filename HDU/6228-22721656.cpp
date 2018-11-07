#include <bits/stdc++.h>
using namespace std;
#define in(x) scanf("%d",&x)
#define rep(i,j,k) for(int i=j;i<k;++i)
#define out(x) printf("%d\n",x)
const int maxn=2e5+6;
int n,k,ans;
int num[maxn];
vector<int> vec[maxn];

void dfs(int u,int root)
{
    num[u]=1;
    rep(i,0,vec[u].size())
    {
        int v=vec[u][i];
        if(v==root)continue;
        dfs(v,u);
        num[u]+=num[v];
        if(num[v]>=k&&n-num[v]>=k)++ans;
    }
}

int main(int argc, char const *argv[])
{
    int T;
    in(T);
    while(T--) {
        memset(num,0,sizeof(num));
        in(n),in(k);
        rep(i,1,n+1)vec[i].clear();
        rep(i,1,n)
        {
            int u,v;
            in(u),in(v);
            vec[u].push_back(v);
            vec[v].push_back(u);
        }
        ans=0;
        dfs(1,-1);
        out(ans);
    }
    return 0;
}
