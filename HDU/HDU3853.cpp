#include <cstdio>
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
const int maxn=1020;
double mp[maxn][maxn][3];
double dp[maxn][maxn];
int main(void)
{
	int row,col;
	while(~in(row)&&~in(col))
	{
		rep(i,1,row+1)rep(j,1,col+1)rep(k,0,3)inf(mp[i][j][k]);
		dp[row][col]=0;
		rvep(i,row,1)
			rvep(j,col,1)
			{
				if(i==row&&j==col)continue;
				if(mp[i][j][0]==1)continue;
				dp[i][j]=(mp[i][j][1]*dp[i][j+1]+mp[i][j][2]*dp[i+1][j]+2)/(1.0-mp[i][j][0]);
			}
		printf("%.3f\n",dp[1][1]);
	}
	return 0;
}