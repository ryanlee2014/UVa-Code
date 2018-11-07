#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAXN 10
#define LL long long
#define MOD 998244353
#define INF 0x3f3f3f3f
using namespace std;


struct Matrix
{
    int n,m;
    LL a[MAXN][MAXN];
    Matrix(){}
    Matrix(int n,int m):n(n),m(m){memset(a,0,sizeof(a));};
    Matrix unit()
    {
        for(int i=0;i!=n;++i)
            for(int j=0;j!=n;++j)
                a[i][j]=(i==j);
    }
    Matrix operator * (Matrix &rhs)
    {
        Matrix res(n,rhs.m);
        for(int i=0;i!=n;++i)
            for(int j=0;j!=rhs.m;++j)
                for(int k=0;k!=m;++k)
                    res.a[i][j]=(res.a[i][j]+a[i][k]*rhs.a[k][j])%MOD;
        return res;
    }
};

Matrix pow(Matrix a,LL b)
{
    Matrix res(a.n,a.n);
    res.unit();
    while(b)
    {
        if(b&1) res=res*a;
        b>>=1;
        a=a*a;
    }
    return res;
}

LL k;

int main()
{
    while(~scanf("%lld",&k))
    {
        Matrix A(2,2),B(2,2);
        B.a[0][0]=B.a[1][0]=1;
        A.a[0][0]=A.a[0][1]=A.a[1][0]=1;
        A.a[1][1]=0;
        A=pow(A,2*k+1);
        A=A*B;
        printf("%lld\n",A.a[0][0]-1);
    }
}