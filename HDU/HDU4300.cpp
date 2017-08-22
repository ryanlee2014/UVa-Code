#include <iostream>
#include <cstring>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
const int maxn = 220100;
const int lens = 40;
char pass[maxn], brr[maxn], change[lens], arr[lens];
int n, m, dict[maxn];

void get_next(char *s)
{
    int i;
    i = dict[0] = -1;
    int j = 0, m = strlen(s);
    while (j < m)
    {
        if (i < 0 || s[j] == s[i])
        {
            ++i, ++j;
            dict[j] = i;
        }
        else
            i = dict[i];
    }
}

void work(char *s)
{
    rep(i, 0, 26) change[arr[i] - 'a'] = 'a' + i;
    int n = strlen(s);
    rep(i, 0, n)
    {
        s[i] = change[s[i] - 'a'];
    }
    return;
}

int main(void)
{
    int T;
    while (~in(T))
    {
        while (T--)
        {
            ins(arr), ins(brr);
            ms(pass);
            strcpy(pass, brr);
            n = strlen(brr);
            m = n << 1;
            work(pass);
            strcat(pass, brr);
            get_next(pass);
            int j = m, mid = n >> 1;
            while (dict[j] > 0 && dict[j] > mid) j = dict[j];
            int len = n - dict[j];
            rep(i, 0, len)printf("%c", brr[i]);
            rep(i, len, len * 2) printf("%c", change[brr[i - len] - 'a']);
            puts("");
        }
    }
    return 0;
}
