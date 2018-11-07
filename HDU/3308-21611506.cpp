#include <cstdio>
#include <iostream>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
const int maxn=120100;
int num[maxn],marr[maxn<<2],larr[maxn<<2],rarr[maxn<<2];
inline void pupd(int pos, int m, int l1, int l2)
{
    marr[pos]=max(marr[pos<<1],marr[pos<<1|1]);
    larr[pos]=larr[pos<<1];
    rarr[pos]=rarr[pos<<1|1];
    if(num[m]<num[m+1])
    {
        marr[pos]=max(marr[pos],rarr[pos<<1]+larr[pos<<1|1]);
        if(larr[pos]>=l1)
            larr[pos]+=larr[pos<<1|1];
        if(rarr[pos]>=l2)
            rarr[pos]+=rarr[pos<<1];
    }
}
void build(int l,int r,int pos)
{
    if(l==r)
    {
        in(num[l]);
        marr[pos]=larr[pos]=rarr[pos]=1;
        return;
    }
    int mid=(l+r)>>1;
    build(l,mid,pos<<1);
    build(mid+1,r,pos<<1|1);
    pupd(pos, mid, mid - l + 1, r - mid);
}
void update(int p, int val, int l, int r, int pos)
{
    if(l==r)
    {
        num[l]=val;
        return;
    }
    int mid=(l+r)>>1;
    if(p<=mid)
        update(p, val, l,mid,pos<<1);
    else
        update(p, val, mid+1,r,pos<<1|1);
    pupd(pos, mid, mid - l + 1, r - mid);
}
int query(int L,int R,int l,int r,int pos)
{
    if(L<=l&&R>=r)
        return marr[pos];
    int mid=(l+r)>>1;
    if(R<=mid)
        return query(L,R,l,mid,pos<<1);
    if(L>mid)
        return query(L,R,mid+1,r,pos<<1|1);
    int ret=max(query(L,R,l,mid,pos<<1),query(L,R,mid+1,r,pos<<1|1));
    if(num[mid]<num[mid+1])
        ret=max(ret,min(R,mid+larr[pos<<1|1])-max(L,mid-rarr[pos<<1]+1)+1);
    return ret;
}
int main(void)
{
    int i,j,n,m,T;
    char que[60];
    in(T);
    while(T--)
    {
        in(n),in(m);
        build(0,n-1,1);
        while(m--)
        {
            ins(que),in(i),in(j);
            if(que[0]=='U')
                update(i, j, 0, n - 1, 1);
            else
                out(query(i,j,0,n-1,1));
        }
    }
    return 0;
}