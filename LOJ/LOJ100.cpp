#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%lld",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%lld",x)
#define outln(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
const int MOD=1e9+7;
typedef long long ll;
struct Matrix{
	ll m[500][500];
	int row,col;
	Matrix():row(0),col(0){
		ms(m);
	}
	Matrix operator*(const Matrix& v)
	{
		Matrix res;
		res.row=row;
		res.col=v.col;
		rep(i,0,row)
		{
			rep(j,0,v.col)
			{
				rep(k,0,col)
				{
					res.m[i][j]=(res.m[i][j]+m[i][k]*v.m[k][j])%MOD;
				}
			}
		}
		return res;
	}
};
Matrix d,e;
int main(void)
{
	ll a,b,c;
	while(~in(a)&&~in(b)&&~in(c))
	{
		d.row=a;
		d.col=e.row=b;
		e.col=c;
		rep(i,0,a)
		{
			rep(j,0,b)in(d.m[i][j]);
		}
		rep(i,0,b)
		{
			rep(j,0,c)in(e.m[i][j]);
		}
		d=d*e;
		rep(i,0,d.row)
		{
			rep(j,0,d.col)
			{
				if(j)printf(" ");
				if(d.m[i][j]<0)d.m[i][j]+=MOD;
				out(d.m[i][j]);
			}
			puts("");
		}
	}
	return 0;
}