#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#define MAXN 3000010
#define INF 0x3f3f3f3f
#define LL long long
using namespace std;

int n;
int a[MAXN],b[MAXN];

int main()
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;++i) scanf("%d",&a[i]),a[i+n]=a[i];
        for(int i=1;i<=n;++i) scanf("%d",&b[i]),b[i+n]=b[i];
        int sum=0,mx=-INF,ans=0;
        int cnt=0;
        for(int i=1;i<=2*n;++i)
        {
            sum+=a[i]-b[i];
            cnt+=a[i];
            if(sum<0)
            {
                if(cnt>mx) ans=i;
                sum=0;
                cnt=0;
            }
        }
        if(ans>n) ans-=n;
        printf("%d\n",ans);
    }
}
