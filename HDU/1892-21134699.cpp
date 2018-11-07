#include <iostream>
#include <cstring>
using namespace std;
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
const int N=1005;
int tr[1005][1005];

inline int lowbit(int k)
{
    return k & -k;
}

void add(int x,int y,int val){
    while(x < N){
        int tmp = y;
        while(tmp < N){
            tr[x][tmp] += val;
            tmp += lowbit(tmp);
        }
        x += lowbit(x);
    }
}

int sum(int x,int y){
    int ans = 0;
    while(x > 0){
        int tmp = y;
        while(tmp > 0){
            ans += tr[x][tmp];
            tmp -= lowbit(tmp);
        }
        x -= lowbit(x);
    }
    return ans;
}

inline int solve(int x,int y)
{
    return sum(x,y)-sum(x-1,y)-sum(x,y-1)+sum(x-1,y-1);
}

int main(void)
{
    int T,x1,x2,y1,y2,x,n,tmp;
    in(T);
    rep(kase,1,T+1)
    {
        printf("Case %d:\n",kase);
        int n;
        scanf("%d",&n);
        memset(tr,0,sizeof(tr));
        for(int i = 1; i < N; ++i)
            for(int j = 1; j < N; ++j)
                add(i,j,1);
        char op[5];
        int x1,y1,x2,y2,x;
        for(int i = 0; i < n; ++i){
            scanf("%s",op);
            if(op[0]=='A' || op[0]=='D'){
                scanf("%d%d%d",&x1,&y1,&x);
                if(op[0] == 'D')
                    x = -min(x,solve(x1+1,y1+1));
                add(x1+1,y1+1,x);
            }
            else if(op[0] == 'M'){
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&x);
                int  tmp = min(x,solve(x1+1,y1+1));
                add(x1+1,y1+1,-tmp);
                add(x2+1,y2+1,tmp);
            }
            else{
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                if(x1 > x2)
                    swap(x1,x2);
                if(y1 > y2)
                    swap(y1,y2);
                int tmp = sum(x2+1,y2+1)-sum(x1,y2+1)-sum(x2+1,y1)+sum(x1,y1);
                printf("%d\n",tmp);
            }
        }
    }
    return 0;
}