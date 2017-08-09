#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define in(x) scanf("%d",&x)
#define ms(x) memset(x,0,sizeof(x))
#define rep(i, a, b) for(int i=a;i<b;++i)
const int maxn = 5010;
int n, m, total[maxn];
int num[maxn];
struct Point
{
	int x, y;
	Point() : x(0), y(0)
	{}
	Point(int x, int y) : x(x), y(y)
	{}
};

struct Line
{
	Point s, e;
	Line()
	{}
	Line(Point s, Point e) : s(s), e(e)
	{}
	int mul(Point a)
	{
		return (a.x - e.x) * (s.y - e.y) - (s.x - e.x) * (a.y - e.y);
	}
	bool operator<(const Line &v) const
	{
		return s.x < v.s.x;
	}
};

Line line[maxn];

int main(void)
{
	Point a, b;
	while (~in(n) && n)
	{
		in(m), in(a.x), in(a.y), in(b.x), in(b.y);
		rep(i, 0, n)
		{
			in(line[i].s.x), in(line[i].e.x);
			line[i].s.y = a.y;
			line[i].e.y = b.y;
		}
		line[n].s.x = b.x;
		line[n].s.y = a.y;
		line[n].e.x = b.x;
		line[n].e.y = b.y;
		sort(line, line + n + 1);
		int x, y;
		Point p;
		ms(total);
		while (m--)
		{
			in(x), in(y);
			p = Point(x, y);
			int l = 0, r = n;
			int tmp;
			while (l <= r)
			{
				int mid = (l + r) >> 1;
				if (line[mid].mul(p) < 0)
				{
					tmp = mid;
					r = mid - 1;
				}
				else l = mid + 1;
			}
			total[tmp]++;
		}
		ms(num);
		rep(i, 0, n + 1) if (total[i] > 0)
				num[total[i]]++;
		puts("Box");
		rep(i, 1, n + 1) if (num[i] > 0)
				printf("%d: %d\n", i, num[i]);
	}
	return 0;
}