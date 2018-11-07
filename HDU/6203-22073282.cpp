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
class iofstream
{
private:
    it idx;
    bl eof;
    cr buf[100000], *ps , *pe ;
    cr bufout[100000], outtmp[50], *pout, *pend ;
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
        ps = buf, pe = buf + 1;
        pout = bufout, pend = bufout + 100000;
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
#define MAXN 100100
#define MAXM 200100
#define MAXNODE 100100
#define INF 0x3f3f3f3f
using namespace std;

struct Edge
{
    int from,to,next;
    Edge(){}
    Edge(int u,int v,int n):from(u),to(v),next(n){}
};

int n,m;
Edge edges[MAXM];
int head[MAXN],tot,idc;
int num[MAXN],size[MAXN],dep[MAXN],son[MAXN],fa[MAXN];
int top[MAXN],id[MAXN];

struct Node
{
    int from,to,lca;
    Node(){}
    Node(int u,int v,int lca):from(u),to(v),lca(lca){}
    bool operator < (const Node &rhs) const
    {
        return dep[lca]>dep[rhs.lca];
    }
};

Node a[MAXNODE];

void AddEdge(int u,int v)
{
    edges[tot]=Edge(u,v,head[u]);
    head[u]=tot++;
    edges[tot]=Edge(v,u,head[v]);
    head[v]=tot++;
}

void init()
{
    tot=idc=0;
    memset(head,-1,sizeof(head));
    memset(son,-1,sizeof(son));
}

void dfs1(int u,int p,int d)
{
    dep[u]=d;
    fa[u]=p;
    size[u]=1;
    for(int i=head[u];~i;i=edges[i].next)
    {
        Edge &e=edges[i];
        if(e.to==p) continue;
        dfs1(e.to,u,d+1);
        size[u]+=size[e.to];
        if(!~son[u] || size[e.to]>size[son[u]]) son[u]=e.to;
    }
}

void dfs2(int u,int fa,int tp)
{
    top[u]=tp;
    id[u]=++idc;
    if(!~son[u]) return;
    dfs2(son[u],u,tp);
    for(int i=head[u];~i;i=edges[i].next)
    {
        Edge &e=edges[i];
        if(e.to==son[u] || e.to==fa) continue;
        dfs2(e.to,u,e.to);
    }
}

int tree[MAXN*4];

void maintain(int u)
{
    tree[u]=max(tree[u<<1],tree[u<<1|1]);
}

void build()
{
    memset(tree,0,sizeof(tree));
}

void update(int u,int L,int R,int p,int v)
{
    if(L==R)
    {
        tree[u]=v;
        return;
    }
    int mid=L+(R-L)/2;
    int lc=u<<1,rc=u<<1|1;
    if(p<=mid) update(lc,L,mid,p,v);
    else update(rc,mid+1,R,p,v);
    maintain(u);
}

int query(int u,int L,int R,int ql,int qr)
{
    if(ql<=L && R<=qr) return tree[u];
    int mid=L+(R-L)/2;
    int lc=u<<1,rc=u<<1|1;
    int res=-INF;
    if(ql<=mid) res=max(res,query(lc,L,mid,ql,qr));
    if(qr>mid) res=max(res,query(rc,mid+1,R,ql,qr));
    return res;
}

void change(int x,int v)
{
    update(1,1,idc,id[x],v);
}

int find(int u,int v)
{
    int res=-INF;
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        res=max(res,query(1,1,idc,id[top[u]],id[u]));
        u=fa[top[u]];
    }
    if(dep[u]>dep[v]) swap(u,v);
    res=max(res,query(1,1,idc,id[u],id[v]));
    return res;
}

int lca(int u,int v)
{
    while(top[u]!=top[v])
    {
        if(dep[top[u]]<dep[top[v]]) swap(u,v);
        u=fa[top[u]];
    }
    return dep[u]<dep[v]?u:v;
}

int main()
{
    while(fin>>n)
    {
        init();
        for(int i=0;i!=n;++i)
        {
            int u,v;
            fin>>u>>v;
            AddEdge(u,v);
        }
        dfs1(0,-1,1);
        dfs2(0,-1,0);
        build();
        fin>>m;
        for(int i=0;i!=m;++i)
        {
            int u,v;
            fin>>u>>v;
            a[i]=Node(u,v,lca(u,v));
        }
        sort(a,a+m);
        int ans=0;
        for(int i=0;i!=m;++i)
        {
            Node &e=a[i];
            if(find(e.from,e.to)) continue;
            else change(e.lca,1),++ans;
        }
        fin<<ans<<ln;
    }
}