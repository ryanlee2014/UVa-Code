#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
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
const int maxn = 200;
const double eps=1e-8;
struct Point
{
	double x, y;
	Point() : x(0), y(0)
	{}
	Point(double x, double y) : x(x), y(y)
	{}
	Point operator-(const Point& v)const
	{
		return Point(x-v.x,y-v.y);
	}
	double operator^(const Point& v)const
	{
		return x*v.y-y*v.x;
	}
	double operator*(const Point& v)const
	{
		return x*v.x+y*v.y;
	}
};

struct Line
{
	Point s, e;
	Line()
	{}
	Line(Point s, Point e) : s(s), e(e)
	{}
	bool operator<(const Line &v) const
	{
		return s.x < v.s.x;
	}
	double dis()
	{
		return sqrt((e-s)*(e-s));
	}
};

Line line[maxn];

int sgn(double x)
{
	return fabs(x)<eps?0:x<0?-1:1;
}

double cross_mul(Point p0,Point p1,Point p2) //p0p1 X p0p2
{
	return (p1-p0)^(p2-p0);
}

bool seg_cross(Line l1,Line l2)
{
	return sgn(cross_mul(l2.s,l1.s,l1.e))*sgn(cross_mul(l2.e,l1.s,l1.e))<=0;
}

bool judge(Line l,int n)
{
	if(!sgn(l.dis()))return false;
	rep(i,0,n)
		if(!seg_cross(l,line[i]))return false;
	return true;
}

int main(void)
{
	int n;
	int T;
	in(T);
	while(T--)
	{
		in(n);
		rep(i,0,n)
		{
			inf(line[i].s.x),inf(line[i].s.y),inf(line[i].e.x),inf(line[i].e.y);
		}
		bool flag=false;
		rep(i,0,n)
		{
			rep(j,0,n)
			{
				if(judge(Line(line[i].s,line[j].s),n)||judge(Line(line[i].s,line[j].e),n)||judge(Line(line[i].e,line[j].s),n)||judge(Line(line[i].e,line[j].e),n))
				{
					flag=true;
					break;
				}
			}
		}
		puts(flag?"Yes!":"No!");
	}
	return 0;
}