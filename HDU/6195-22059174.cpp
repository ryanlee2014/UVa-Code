#include<iostream>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;

LL n,m;

int main()
{
    while(~scanf("%lld%lld",&n,&m))
    {
        LL ans=(n-m+1LL)*m;
        printf("%lld\n",ans);
    }
}