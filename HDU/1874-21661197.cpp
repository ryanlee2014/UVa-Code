#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
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
cst it INF = 0x3f3f3f3f;
/*
 * 输入挂
 * 场场AK buff
 */

class endln
{
};
cst it MAXBUF = 10000;
cst it MAXOUT = 10000;
class iofstream
{
    it idx;
    bl eof;
public:
    iofstream() : idx(-1),eof(true)
    {}
    cr buf[MAXBUF], *ps = buf, *pe = buf + 1;
    il vt rnext()
    {
        if (++ps == pe)
            pe = (ps = buf) + fread(buf, sf(cr), sf(buf) / sf(cr), stdin);
    }

    tpl<cl T>
    il bl fin(T &ans)
    {
#ifdef ONLINE_JUDGE
        ans = 0;
    T f = 1;
    if (ps == pe) rtn false;//EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } wl(!isdigit(*ps) && ps != pe);
    if (ps == pe) rtn false;//EOF
    do
    {
        ans = (ans << 1) + (ans << 3) + *ps - 48;
        rnext();
    } wl(isdigit(*ps) && ps != pe);
    ans *= f;
#else
        cin >> ans;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl fdb(T &ans)
    {
#ifdef ONLINE_JUDGE
        ans = 0;
    T f = 1;
    if (ps == pe) rtn false;//EOF
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } wl(!isdigit(*ps) && ps != pe);
    if (ps == pe) rtn false;//EOF
    do
    {
        ans = ans*10 + *ps - 48;
        rnext();
    } wl(isdigit(*ps) && ps != pe);
    ans *= f;
        if(*ps=='.')
        {
            rnext();
            T small=0;
            do
            {
                small=small*10+*ps-48;
                rnext();
            }wl(isdigit(*ps)&&ps!=pe);
            wl(small>=1)
            {
                small/=10;
            }
            ans+=small;
        }
#else
        cin >> ans;
#endif
        rtn true;
    }

/*
 * 输出挂
 * 超强 超快
 */
    cr bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
    il vt write()
    {
        fwrite(bufout, sf(cr), pout - bufout, stdout);
        pout = bufout;
    }
    il bl out_char(cst cr c)
    {
#ifdef ONLINE_JUDGE
        *(pout++) = c;
    if (pout == pend) write();
    write();
#else
        cout << c;
#endif
        rtn true;
    }
    il bl out_str(cst cr *s)
    {
#ifdef ONLINE_JUDGE
        wl(*s)
    {
        *(pout++) = *(s++);
        if (pout == pend) write();
    }
    write();
#else
        cout << s;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_double(T x, it idx)
    {
        char str[50];
        string format = "%";
        if(~idx)
        {
            format+='.';
            format += (char) (idx + '0');
        }
        format += "f";
        sprintf(str, format.c_str(), x);
        out_str(str);
    }

    tpl<cl T>
    il bl out_int(T x)
    {
#ifdef ONLINE_JUDGE
        if (!x)
        {
            out_char('0');
            rtn true;
        }
        if (x < 0) x = -x, out_char('-');
        it len = 0;
        wl(x)
        {
            outtmp[len++] = x % 10 + 48;
            x /= 10;
        }
        outtmp[len] = 0;
        for (it i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
        out_str(outtmp);
#else
        cout << x;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_intln(T x)
    {
#ifdef ONLINE_JUDGE
        out_int(x),out_char('\n');
        write();
#else
        cout << x << endl;
#endif
    }

    tpl<cl T>
    il bl out_doubleln(T x, it idx)
    {
        out_double(x, idx), out_char('\n');
    }
    il iofstream &ope<<(cst db &x)
    {
        out_double(x, idx);
        rtn *this;
    }

    il iofstream &ope<<(cst it &x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst ll &x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst endln &x)
    {
        out_char('\n');
        rtn *this;
    }

    il iofstream &ope<<(cst char *x)
    {
        out_str(x);
        rtn *this;
    }

    il iofstream &ope<<(cst char &x)
    {
        out_char(x);
        rtn *this;
    }

    il bl setw(it x)
    {
        if (x >= 0)
        {
            idx = x;
            rtn true;
        }
        rtn false;
    }

    il iofstream &ope>>(it &x)
    {
        if(!fin(x))eof=false;
        rtn *this;
    }

    il iofstream &ope>>(ll &x)
    {
        if(!fin(x))eof=false;
        rtn *this;
    }

    il iofstream& ope>>(db& x)
    {
        if(!fdb(x))eof=false;
        rtn *this;
    }

    il iofstream &ope>>(unsigned &x)
    {
        if(!fin(x))eof=false;
        rtn *this;
    }

    il iofstream &ope>>(unsigned long long &x)
    {
        if(!fin(x))eof=false;
        rtn *this;
    }
    ope bl()
    {
        rtn eof;
    }
};
iofstream fin;
endln ln;
using namespace std;
const int big=0x3f3f3f3f;
int map[1001][1001];
int main(void)
{
    int n,m;
    while(fin>>n>>m)
    {
        memset(map,big, sizeof(map));
        for (int i = 0; i < 1001; ++i)
        {
            map[i][i]=0;
        }
        for (int i = 0; i < m; i++)
        {
            int a,b,c;
            fin>>a>>b>>c;
            if(c<map[a][b])
            {
                map[a][b] = c;
                map[b][a] = c;
            }
        }
        for (int k = 0; k <n ; k++)
        {
            for (int i = 0; i <n ; i++)
            {
                for (int j = 0; j <n ; j++)
                {
                    map[i][j]=min(map[i][k]+map[k][j],map[i][j]);
                }
            }
        }
        int start,end;
        fin>>start>>end;
        if(map[start][end]!=big)fin<<map[start][end]<<ln;
        else fin<<-1<<ln;
    }
    return 0;
}