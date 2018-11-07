#include <bits/stdc++.h>
using namespace std;
#define in(x) scanf("%d",&x)
#define rep(i,j,k) for(int i=j;i<k;++i)
#define out(x) printf("%d\n",x)
int a[1010],b[1010];
int main(int argc, char const *argv[])
{
    int T,n;
    in(T);
    while(T--) {
        in(n);
        rep(i,1,n+1)in(a[i]);
        int ans=0;
        rep(i,2,n+1)
        {
            b[i-1]=a[i]-a[i-1]-1;
            ans+=b[i-1];
        }
        int k=min(b[1],b[n-1]);
        out(ans-k);
    }
    return 0;
}
