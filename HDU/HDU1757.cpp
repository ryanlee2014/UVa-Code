#include <iostream>
#include <cstdio>
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
	Matrix():row(10),col(10){
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
int main(void)
{
	while(~in(n)&&~in(mod))
	{
		Matrix a,b;
		rep(i,0,10)
			in(a.m[0][i]);
		rep(i,1,10)
			a.m[i][i-1]=1;
		b=a^(n-9);
		int sum=0;
		rep(i,0,10)
		{
			sum+=b.m[0][i]*(10-i-1);
			sum%=mod;
		}
		out(sum);
	}
	return 0;
}