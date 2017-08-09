#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
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
const int maxn=5010;
int n,m,total[maxn];

struct Point
{
	int x,y;
	Point():x(0),y(0){}
	Point(int x,int y):x(x),y(y){}
};

struct Line
{
	Point s,e;
	Line(){}
	Line(Point s,Point e):s(s),e(e){}
	int mul(Point a)
	{
		return (a.x-e.x)*(s.y-e.y)-(s.x-e.x)*(a.y-e.y);
	}
};

Line line[maxn];

void work(Point a)
{
	rep(i,0,n)
	{
		if(line[i].mul(a)>0)continue;
		else
		{
			++total[i];
			return;
		}
	}
	++total[n];
}

int main(void)
{
	Point a,b,tmp;
	while(~in(n)&&n)
	{
		in(m),in(a.x),in(a.y),in(b.x),in(b.y);
		ms(total);
		rep(i,0,n)
		{
			in(line[i].s.x),in(line[i].e.x);
			line[i].s.y=a.y;
			line[i].e.y=b.y;
		}
		rep(i,0,m)
		{
			in(tmp.x),in(tmp.y);
			work(tmp);
		}
		rep(i,0,n+1)
		{
			printf("%d: %d\n",i,total[i]);
		}
		puts("");
	}
	return 0;
}