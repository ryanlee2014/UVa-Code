#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=305;
const int maxm=17;
ll c1[maxn],c2[maxn];
int n;
inline void init()
{
    c1[0]=1;
    for(int i=1;i<=maxm;++i)
    {
        for(int j=0;j<maxn;j+=i*i)
        {
            for(int k=0;j+k<maxn;++k)
            {
                c2[j+k]+=c1[k];
            }
        }
        for(int j=0;j<maxn;++j)
        {
            c1[j]=c2[j];
            c2[j]=0;
        }
    }
}

int main()
{
    init();
    while(~scanf("%d",&n)&&n)
    {
        printf("%lld\n",c1[n]);
    }
}