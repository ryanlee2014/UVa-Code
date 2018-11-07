#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
#define rep(i, a, b) for(int i=a;i<b;++i)
using namespace std;
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
        Matrix res,a;
        a=*this;
        res.row=row,res.col=col;
        rep(i,0,min(row,col)+1)
            res.m[i][i]=1;
        for (;k; k>>=1)
        {
            if(k&1)
                res=res*a;
            a=a*a;
        }
        return res;
    }
};
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
            out(n==0?0:a.m[4-n][0]%mod);
        }
        else
        {
            out(((b^n-4)*a).m[0][0]%mod);
        }
    }
    return 0;
}