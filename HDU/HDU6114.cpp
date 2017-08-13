#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const long long M = 1000000007;
long long ff[1300+5];  //打表，记录n!，避免重复计算

//求最大公因数
long long gcd(long long a,long long b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

//解线性同余方程，扩展欧几里德定理
long long x,y;
void Extended_gcd(long long a,long long b)
{
    if(b==0)
    {
        x=1;
        y=0;
    }
    else
    {
        Extended_gcd(b,a%b);
        long t=x;
        x=y;
        y=t-(a/b)*y;
    }
}

//计算不大的C(n,m)
long long C(long long a,long long b)
{
    if(b>a)
        return 0;
    b=(ff[a-b]*ff[b])%M;
    a=ff[a];
    long long c=gcd(a,b);
    a/=c;
    b/=c;
    Extended_gcd(b,M);
    x=(x+M)%M;
    x=(x*a)%M;
    return x;
}

//Lucas定理
long long Combination(long long n, long long m)
{
    long long ans=1;
    long long a,b;
    while(m||n)
    {
        a=n%M;
        b=m%M;
        n/=M;
        m/=M;
        ans=(ans*C(a,b))%M;
    }
    return ans;
}

int main(void)
{
    long long i,m,n;
    ff[0]=1;
    for(i=1;i<=1200;i++) 
        ff[i]=(ff[i-1]*i)%M;
    long long T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld", &n, &m);
        if(n<m)swap(n,m);
        printf("%lld\n", Combination(n, m));
    }
    return 0;
}