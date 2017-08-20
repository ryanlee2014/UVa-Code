#include <cstdio>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define rep(i, a, b) for(int i=a;i<b;++i)
using namespace std;
const int maxn = 80010;
char a[maxn],b[maxn];
int main(void)
{
    int T,n,x,y,c,d;
    in(T);
    while (T--)
    {
        c=d=0;
        in(n),in(x),in(y),ins(a),ins(b);
        rep(i,0,n)a[i]==b[i]?++c:++d;
        puts((abs(x-y)<=d&&(x+y-2*c)<=d)?"Not lying":"Lying");
    }
    return 0;
}