#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
struct Matrix{
	int m[12][12];
	int row,col;
	Matrix():row(0),col(0){
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
				}
				res.m[i][j]%=9973;
			}
		}
		return res;
	}
	Matrix operator ^(int k)
	{
		Matrix res;
		res.row=row,res.col=col;
		rep(i,0,row)
			rep(j,0,col)
	            res.m[i][j]=(i==j);
		for (;k; k>>=1)
		{
			if(k&1)
				res=res*(*this);
			(*this)=(*this)*(*this);
		}
		return res;
	}
	int result()
	{
		int sum=0;
		int n=min(col,row);
		rep(i,0,n)
		{
			sum += m[i][i];
			sum%=9973;
		}
		return sum;
	}
};
int main(void)
{
	int T;
	in(T);
	while(T--)
	{
		int n,k;
		Matrix mat;
		in(n),in(k);
		mat.col=mat.row=n;
		rep(i,0,n)
			rep(j,0,n)
	            in(mat.m[i][j]);
		mat=mat^k;
		out(mat.result());
	}
	return 0;
}