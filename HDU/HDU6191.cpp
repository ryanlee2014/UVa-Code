#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define met(a,b) memset(a,b,sizeof a)
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 2e5+5;;
const int M = 17;
const int mod = 1e9+7;
const int mo=123;
const double pi= acos(-1.0);
typedef pair<int,int>pii;

int bin[31];
int n,m,tot;
int a[N],root[N],id[N],st[N],ed[N];
vector<int>edg[N];
struct trie{
    int cnt;
    int ch[N*32][2],sum[N*32];
    void init(){
        met(ch,0);met(sum,0);
        cnt=0;
    }
    int insert(int x,int val){
        int tmp,y;tmp=y=++cnt;
        for(int i=30;i>=0;i--)
        {
            ch[y][0]=ch[x][0];ch[y][1]=ch[x][1];
            sum[y]=sum[x]+1;
            int t=val&bin[i];t>>=i;
            x=ch[x][t];
            ch[y][t]=++cnt;
            y=ch[y][t];
        }
        sum[y]=sum[x]+1;
        return tmp;
    }
    int query(int l,int r,int val){
        int tmp=0;
        for(int i=30;i>=0;i--)
        {
            int t=val&bin[i];t>>=i;
            if(sum[ch[r][t^1]]-sum[ch[l][t^1]])
                tmp+=bin[i],r=ch[r][t^1],l=ch[l][t^1];
            else r=ch[r][t],l=ch[l][t];
        }
        return tmp;
    }
}trie;
void dfs(int u,int fa){
    st[u]=++tot;
    id[tot]=u;
    for(int i=0;i<edg[u].size();i++){
        int v=edg[u][i];
        if(v==fa)continue;
        dfs(v,u);
    }
    ed[u]=tot;
}
int main(){
    bin[0]=1;for(int i=1;i<=30;i++)bin[i]=bin[i-1]<<1;
    while(~scanf("%d%d",&n,&m)){
        root[0]=0;tot=0;
        trie.init();
        for(int i=1;i<=n;i++)scanf("%d",&a[i]),edg[i].clear();
        for(int i=2;i<=n;i++){
            int v;
            scanf("%d",&v);
            edg[v].pb(i);
        }
        dfs(1,0);
        for(int i=1;i<=n;i++)root[i]=trie.insert(root[i-1],a[id[i]]);
        int l,r,x,u;
        while(m--){
            scanf("%d%d",&u,&x);
            l=st[u];r=ed[u];
            printf("%d\n",trie.query(root[l-1],root[r],x));
        }
    }
    return 0;
}

