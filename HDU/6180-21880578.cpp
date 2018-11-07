#include<stdio.h>
#include<algorithm>
using namespace std;
#define LL long long
typedef struct
{
    LL x;
    LL flag;
}Point;
Point s[200005];
LL L[100005], R[100005];
bool comp(Point a, Point b)
{
    if(a.x<b.x || a.x==b.x && a.flag<b.flag)
        return 1;
    return 0;
}
int main(void)
{
    LL T, n, i, a, b, sum, ans;
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld", &n);
        for(i=1;i<=n;i++)
        {
            scanf("%lld%lld", &a, &b);
            s[i*2-1].x = a, s[i*2-1].flag = 1;
            s[i*2].x = b, s[i*2].flag = -1;
        }
        n *= 2;
        sort(s+1, s+n+1, comp);
        sum = ans = 0;
        for(i=1;i<=n;i++)
        {
            sum += s[i].flag;
            if(sum>ans)
            {
                ans = sum;
                L[sum] = s[i].x;
            }
            ans = max(ans, sum);
        }
        sum = ans = 0;
        for(i=n;i>=1;i--)
        {
            sum -= s[i].flag;
            if(sum>ans)
            {
                ans = sum;
                R[sum] = s[i].x;
            }
            ans = max(ans, sum);
        }
        sum = 0;
        for(i=1;i<=ans;i++)
            sum += R[i]-L[i];
        printf("%lld %lld\n", ans, sum);
    }
    return 0;
}