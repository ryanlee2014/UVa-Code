#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#define in(x) scanf("%d",&x)
#define ein(x) ~scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define sn scanf
#define bl bool
#define mp make_pair
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define cr char
#define ctn continue
#define stt struct
#define il inline
#define tpl template
#define cl class
#define db double
#define sf(x) sizeof(x)
#define vt void
#define pf printf
typedef long long ll;
using namespace std;
const int MAXN = 1e5 + 10;
int dict[MAXN];
int n;
set<string> s;

il vt kmpinit(char *x, int m, int *next)
{
    it i, j;
    j = next[0] = -1;
    i = 0;
    wl(i < m)
    {
        wl(~j && x[i] != x[j])j = next[j];
        next[++i] = ++j;
    }
}

il bl kmpcompare(char *x, int m, char *y, int n)
{
    int i, j;
    i = j = 0;
    wl(i < n)
    {
        wl(~j && y[i] != x[j])j = dict[j];
        ++i, ++j;
        if (j >= m)rtn true;
    }
    rtn false;
}

int main()
{
    it T;
    in(T);
    while (T--)
    {
        in(n);
        cr str[MAXN];
        it maxlen = 0;
        cr maxstr[MAXN];
        rep(i, 0, n)
        {
            ins(str);
            it len = strlen(str);
            if (len > maxlen)
            {
                maxlen = len;
                strcpy(maxstr, str);
            }
            string str1(str);
            s.insert(str1);
        }
        bl is = true;
        for (auto iter = s.begin(); iter != s.end(); iter++)
        {
            string tmp = *iter;
            char x[MAXN];
            strcpy(x, tmp.c_str());
            int len1 = strlen(x);
            kmpinit(x, len1, dict);
            if (!kmpcompare(x, len1, maxstr, maxlen))
            {
                puts("No");
                is = false;
                break;
            }
        }
        if (is)
            puts(maxstr);
        s.clear();
    }
    return 0;
}