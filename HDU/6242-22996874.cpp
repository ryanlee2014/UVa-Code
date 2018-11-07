#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
#define mst(a, b) memset((a),(b),sizeof(a))

typedef long long ll;
const int maxn = 200005;
const ll mod = 10;
const int INF = 0x3f3f3f3f;
const double eps = 1e-3;

int n;
int num[maxn];

struct Point                         //点  
{
    double x, y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
} a[maxn];

typedef Point Vector;                 //向量  


struct Circle                        //圆  
{
    Point o;
    double r;

    Circle(Point o, double r) : o(o), r(r) {}
};

double getdis(Point a, Point b)       //两个点之间的距离  
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Circle get_outcircle(Point a, Point b, Point c)  //求三角形外接圆  
{
    double t1 = a.x * a.x + a.y * a.y;
    double t2 = b.x * b.x + b.y * b.y;
    double t3 = c.x * c.x + c.y * c.y;
    double temp = a.x * b.y + b.x * c.y + c.x * a.y - a.x * c.y - b.x * a.y - c.x * b.y;
    double x = (t2 * c.y + t1 * b.y + t3 * a.y - t2 * a.y - t3 * b.y - t1 * c.y) / temp / 2;
    double y = (t3 * b.x + t2 * a.x + t1 * c.x - t1 * b.x - t2 * c.x - t3 * a.x) / temp / 2;
    return Circle(Point(x, y), getdis(Point(x, y), a));
}

bool judge(Circle A, Point B) {
    if (fabs(sqrt((A.o.x - B.x) * (A.o.x - B.x) + (A.o.y - B.y) * (A.o.y - B.y)) - A.r) < eps)
        return 1;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            num[i] = i;
        }
        if (n == 1) {
            printf("%.6f %.6f 0\n", a[0].x, a[0].y);
            continue;
        }
        if (n <= 4) {
            double x = (a[0].x + a[1].x) / 2;
            double y = (a[0].y + a[1].y) / 2;
            double r = getdis(a[0], a[1]) / 2;
            printf("%.6f %.6f %.6f\n", x, y, r);
            continue;
        }
        while (1) {
            random_shuffle(num, num + n);
            Circle now = get_outcircle(a[num[0]], a[num[1]], a[num[2]]);
            int ans = 0;
            for (int i = 0; i < n; i++) {
                if (judge(now, a[i])) ans++;
            }
            if (ans >= (n + 1) / 2) {
                printf("%.6f %.6f %.6f\n", now.o.x, now.o.y, now.r);
                break;
            }
        }
    }
    return 0;
}  