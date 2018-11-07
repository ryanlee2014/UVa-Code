#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int,int> pii;
const int inf = 0x3f3f3f3f;
const int N =2e5+10;
const int mod = 998244353;
const double eps = 1e-8;
void fre() {freopen("in.txt","r",stdin);}

ll b[10010],cnt,sum[10010];
int n,m,T,nxt,mi,a[10010],ans[10010];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<=m;i++) scanf("%lld",&b[i]),sum[i]=0;
        mi=0,cnt=1;
        while(cnt<b[0]){
            cnt*=2;
            mi++;
        }
        a[0]=mi;
        sum[0]=1<<mi;
        for(int i=1;i<=m;i++){
            a[i]=(b[i]-sum[i])/sum[0];
            for(int j=1;j<=a[i];j++){
                for(int k=m;k>=i;k--)
                    sum[k]+=sum[k-i];
            }
        }
        nxt=0;
        for(int i=0;i<=m;i++){
            for(int j=1;j<=a[i];j++){
                ans[++nxt]=i;
            }
        }
        for(int i=1;i<=nxt;i++) printf("%d%c",ans[i],i==nxt?'\n':' ');
    }
    return 0;
}