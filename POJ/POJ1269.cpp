#include <iostream>
#include <cstdio>
#include <cmath>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
const double eps = 1e-8;
inline int sgn(double x)
{
	return fabs(x) < eps ? 0 : x < 0 ? -1 : 1;
}
struct Point
{
	double x, y;
	Point()
	{}
	Point(double x, double y) : x(x), y(y)
	{}
	Point operator-(const Point &v) const
	{
		return Point(x - v.x, y - v.y);
	}
	double operator^(const Point &v) const
	{
		return x * v.y - y * v.x;
	}
	double operator*(const Point &v) const
	{
		return x * v.x + y * v.y;
	}
};
struct Line
{
	Point s, e;
	Line()
	{}
	Line(Point s, Point e) : s(s), e(e)
	{}
	pair<Point, int> operator&(const Line &v) const
	{
		Point res = s;
		if (!sgn((s - e) ^ (v.s - v.e)))
		{
			return make_pair(res, !sgn((v.s - s) ^ (v.e - s)) ? 0 : 1);
		}
		double t = ((s - v.s) ^ (v.s - v.e)) / ((s - e) ^ (v.s - v.e));
		res.x += (e.x - s.x) * t;
		res.y += (e.y - s.y) * t;
		return make_pair(res, -1);
	}
};
int main(void)
{
	int T;
	in(T);
	double x1, y1, x2, y2, x3, y3, x4, y4;
	puts("INTERSECTING LINES OUTPUT");
	while (T--)
	{
		inf(x1), inf(y1), inf(x2), inf(y2), inf(x3), inf(y3), inf(x4), inf(y4);
		Line line1 = Line(Point(x1, y1), Point(x2, y2));
		Line line2 = Line(Point(x3, y3), Point(x4, y4));
		pair<Point, int> ans = line1 & line2;
		if (!~ans.second)printf("POINT %.2lf %.2lf\n", ans.first.x, ans.first.y);
		else puts(!ans.second ? "LINE" : "NONE");
	}
	puts("END OF OUTPUT");
	return 0;
}