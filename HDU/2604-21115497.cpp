#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
#define rep(i, a, b) for(int i=a;i<b;++i)
using namespace std;
const int maxn=4;
int n,mod;
struct Matrix{
    int m[12][12];
    int row,col;
    Matrix():row(4),col(4){
        ms(m);
    }
    Matrix operator*(const Matrix& v)
    {
        Matrix res;
        res.row=row;
        res.col=col;
        rep(i,0,row)
        {
            rep(j,0,v.col)
            {
                rep(k,0,col)
                {
                    res.m[i][j]+=m[i][k]*v.m[k][j];
                    res.m[i][j]%=mod;
                }
            }
        }
        return res;
    }
    Matrix operator ^(int k)
    {
        Matrix res;
        res.row=row,res.col=col;
        rep(i,0,min(row,col)+1)
            res.m[i][i]=1;
        for (;k; k>>=1)
        {
            if(k&1)
                res=res*(*this);
            (*this)=(*this)*(*this);
        }
        return res;
    }
};
Matrix Mul(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < maxn; k++)
                c.m[i][j] = (c.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
    return c;
}

Matrix powMul(Matrix a, int k) {
    Matrix tmp;
    for (int i = 0; i < maxn; i++)
        tmp.m[i][i] = 1;
    while (k) {
        if (k & 1)
            tmp = Mul(a, tmp);
        k >>= 1;
        a = Mul(a, a);
    }
    return tmp;
}
int main(void)
{
    Matrix a,b,c;
    a.m[0][0]=9;
    a.m[1][0]=6;
    a.m[2][0]=4;
    a.m[3][0]=2;
    b.m[0][0]=b.m[0][2]=b.m[0][3]=b.m[1][0]=b.m[2][1]=b.m[3][2]=1;
    while(~in(n)&&~in(mod))
    {
        if(n<=4)
        {
            if(n==0)
                out(0);
            else out(a.m[4-n][0]%mod);
        }
        else
        {
            c=powMul(b,n-4);
            c=c*a;
            out(c.m[0][0]%mod);
        }
    }
    return 0;
}