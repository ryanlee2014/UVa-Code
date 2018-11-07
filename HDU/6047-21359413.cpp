#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

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
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int MOD=1e9+7;
struct Node
{
    int id;
    int val;
    Node(int id,int val):id(id),val(val){}
    Node(){}
    bool operator<(const Node& v)const
    {
        return val<v.val;
    }
};
priority_queue<Node>q;
int p[251000];
int main(void)
{
    int t;
    Node temp;
    while(~in(t))
    {
        cp(q);
        rep(i,1,t+1)
        {
            in(temp.val);
            temp.id=i;
            temp.val-=i;
            q.push(temp);
        }
        rep(i,1,t+1)
        {
            in(p[i]);
        }
        sort(p+1,p+t+1);
        int target=0;
        while(q.top().id<p[1])q.pop();
        target=q.top().val;
        int last_element=target-t-1;
        rep(i,2,t+1)
        {
            while(q.top().id<p[i])q.pop();
            target+=(max(last_element,q.top().val))%MOD;
            target%=MOD;
        }
        out(target);
    }
    return 0;
}