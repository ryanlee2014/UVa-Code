#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define PI acos(-1)
#define fi first
#define se second
#define INF 0x3f3f3f3f
#define INF64 0x3f3f3f3f3f3f3f3f
#define random(a,b) ((a)+rand()%((b)-(a)+1))
#define ms(x,v) memset((x),(v),sizeof(x))
#define scint(x) scanf("%d",&x );
#define scf(x) scanf("%lf",&x );
#define eps 1e-10
#define dcmp(x) (fabs(x) < eps? 0:((x) <0?-1:1))
#define lc o<<1
#define rc o<<1|1
using namespace std;
typedef long long LL;
typedef long double DB;
typedef pair<int,int> Pair;
const int maxn = 1e5+10;
const int maxv = 1e6+10;

std::vector<int> ans;

set<int> x[maxn],st;
int p[maxn];
int FIND(int x){
    return p[x] == x? x :p[x] = FIND(p[x]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;cin>>n;
    for(int i=1 ; i<= maxn; ++i)p[i] = i;
    int last =0;
    for(int i=1 ; i<=n ; ++i){
        int a,b,c;cin>>a>>b>>c;
        int fa = FIND(a) , fb = FIND(b);
        st.insert(a);st.insert(b);
        if(c){
            if(x[fa].count(fb) || x[fb].count(fa)){
                ans.pb(i - last);
                last = i;
                for(auto e: st){
                    p[e] = e;
                    x[e].clear();
                }
                st.clear();
            }else if(fa != fb){
                //合并集合
                if(x[fa].size() > x[fb].size())swap(fa,fb);
                p[fa] = fb;
                for(auto e : x[fa]){
                    x[fb].insert(e);
                    x[e].erase(fa);
                    x[e].insert(fb);
                }
                x[fa].clear();
            }
        }else {
            x[a].insert(b);x[b].insert(a);
            if(fa  == fb){
                ans.pb(i - last);
                last = i;
                for(auto e : st){
                    p[e] = e;
                    x[e].clear();
                }
                st.clear();
            }
        }
    }
    std::cout << ans.size() << '\n';
    for(auto e : ans)std::cout << e << '\n';
    return 0;
}