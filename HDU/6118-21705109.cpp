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
cst it INF = 0x3f3f3f3f;
/*
 * 输入挂
 * 场场AK buff
 */

class endln
{
};
cst it MAXBUF = 100000;
cst it MAXOUT = 100000;
class iofstream
{
private:
    it idx;
    bl eof;
    cr buf[MAXBUF], *ps = buf, *pe = buf + 1;
    cr bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
    il vt rnext()
    {
        if (++ps == pe)
            pe = (ps = buf) + fread(buf, sf(cr), sf(buf) / sf(cr), stdin),eof=true;
        if(ps==pe)
            eof=false;
    }
    il vt write()
    {
        fwrite(bufout, sf(cr), pout - bufout, stdout);
        pout = bufout;
    }
public:
    iofstream(char* in=NULL,char* out=NULL) : idx(-1),eof(true)
    {
        if(in)
            freopen(in,"r",stdin);
        if(out)
            freopen(out,"w",stdout);
    }
    tpl<cl T>
    il bl fin(T &ans)
    {
#ifdef ONLINE_JUDGE
        ans = 0;
    T f = 1;
    if (ps == pe)
    {
        eof=false;
        rtn false;//EOF
    }
    do
    {
        rnext();
        if ('-' == *ps) f = -1;
    } wl(!isdigit(*ps) && ps != pe);
    if (ps == pe)
     {
        eof=false;
         rtn false;//EOF
    }
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
        rtn true;
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

    il iofstream& ope<<(cst unsigned long long& x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream& ope<<(cst unsigned& x)
    {
        out_int(x);
        rtn *this;
    }

    il iofstream& ope<<(cst long& x)
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


    il iofstream &ope<<(cst cr *x)
    {
        out_str(x);
        rtn *this;
    }

    il iofstream& ope<<(cst string& x)
    {
        out_str(x.c_str());
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

    il iofstream& ope>>(float& x)
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
    il ope bl()
    {
        rtn eof;
    }

    il cr getchar()
    {
#ifdef ONLINE_JUDGE
        if (ps == pe){
            eof=false;//EOF
            rtn 0;
        }
        rnext();
        if(ps+1==pe)
            eof=false;
        rtn *ps;
#else
        rtn std::getchar();
#endif
    }

    il iofstream& ope>>(char* str)
    {
#ifdef ONLINE_JUDGE
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            rnext();
        } wl(isspace(*ps)&&iscntrl(*ps) && ps != pe);
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            *str=*ps;
            ++str;
            rnext();
        } wl(!(isspace(*ps)||iscntrl(*ps)) && ps != pe);
        *str='\0';
        rtn *this;
#else
        cin>>str;
        rtn *this;
#endif
    }

    il iofstream& ope>>(string& str)
    {
#ifdef ONLINE_JUDGE
        str.clear();
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            rnext();
        } wl(isspace(*ps)&&iscntrl(*ps) && ps != pe);
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            str+=*ps;
            rnext();
        } wl(!(isspace(*ps)||iscntrl(*ps)) && ps != pe);
        rtn *this;
#else
        cin>>str;
        rtn *this;
#endif
    }

    il iofstream& getline(char* str)
    {
#ifdef ONLINE_JUDGE
        if (ps == pe){
            eof=false;//EOF
            rtn *this;
        }
        do
        {
            rnext();
            *str=*ps;
        }while(*ps!='\n'&&ps!=pe&&str++);
        *str='\0';
        rtn *this;
#else
        gets(str);
        rtn *this;
#endif
    }
    il bl endfile()
    {
        rtn eof;
    }
};
static iofstream fin;
static endln ln;



template<typename flow_t, typename cost_t>
struct MCMF {
    static cst it N = 2000, M = 10000;
    cst flow_t inf = 1e9;
    stt node {
        it from, to, nxt;
        flow_t cap, flow;
        cost_t cost;
        node() {}
        node(int from, int to, int nxt, flow_t cap, cost_t cost):
                from(from), to(to), nxt(nxt), cap(cap), flow(0), cost(cost) {}
    } E[M];
    cost_t dis[N];
    int G[N], pre[N], vis[N], n, m;
    void init(int n) {
        this->n = n;
        this->m = 0;
        std::fill(G, G + n, -1);
    }
    il vt connect(int u, int v, flow_t f, cost_t c) {
        E[m] = node(u, v, G[u], f, +c); G[u] = m++;
        E[m] = node(v, u, G[v], 0, -c); G[v] = m++;
    }
    il bl extand(int S, int T) {
        std::fill(vis, vis + n, 0);
        std::fill(dis, dis + n, inf);
        std::queue<int> queue;
        dis[S] = 0;
        queue.push(S);
        for (; !queue.empty(); queue.pop()) {
            int u = queue.front();
            vis[u] = false;
            for (int st = G[u]; ~st; st = E[st].nxt) {
                int v = E[st].to;
                if (E[st].cap > E[st].flow && dis[v] > dis[u] + E[st].cost) {
                    dis[v] = dis[u] + E[st].cost;
                    pre[v] = st;
                    if (!vis[v]) queue.push(v);
                    vis[v] = true;
                }
            }
        }
        return dis[T] < 0; 
    }
    std::pair<flow_t, cost_t> run(int S, int T) {
        flow_t max_flow = 0;
        cost_t min_cost = 0;
        while (extand(S, T)) {
            flow_t delta = inf;
            for (int u = T; u != S; u = E[pre[u]].from) {
                delta = std::min(delta, E[pre[u]].cap - E[pre[u]].flow);
            }
            min_cost += delta * dis[T];
            max_flow += delta;
            for (int u = T; u != S; u = E[pre[u]].from) {
                E[pre[u]].flow += delta;
                E[pre[u] ^ 1].flow -= delta;
            }
        }
        rtn {max_flow, min_cost};
    }
};

MCMF<it, it> mcmf;
int main()
{
    it n, m;
    it a, b, c, d;
    wl(~in(n)&&~in(m) ) {
        mcmf.init(n + 2);
        it S = 0, T = n + 1;
        rep(i,1,n+1)
        {
            in(a),in(b),in(c),in(d);
            mcmf.connect(S, i, b, a);
            mcmf.connect(i, T, d, -c);
        }
        rep(i,1,m+1)
        {
            it u, v, w;
            in(u),in(v),in(w);
            mcmf.connect(u, v, mcmf.inf, w);
            mcmf.connect(v, u, mcmf.inf, w);
        }
        pii ans = mcmf.run(S, T);
        out(-ans.second);
    }
}