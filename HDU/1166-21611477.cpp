#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
const int N=50005;
int tr[4*N];

void build(int i,int l,int r)
{
    if(l==r)
    {
        scanf("%d",&tr[i]);
        return ;
    }
    int mid=(l+r)>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tr[i]=tr[2*i]+tr[2*i+1];
}

void update(int i,int l,int r,int x,int y)
{
    if(l==r)
    {
        tr[i]+=y;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid)update(i*2,l,mid,x,y);
    else update(i*2+1,mid+1,r,x,y);
    tr[i]=tr[2*i]+tr[2*i+1];
}

int query(int i,int l,int r,int x,int y)
{
    int sum=0;
    if(x<=l&&r<=y)
    {
        sum+=tr[i];
        return sum;
    }
    int mid=(l+r)>>1;
    if(x<=mid) sum+=query(2*i,l,mid,x,y);
    if(y>mid) sum+=query(2*i+1,mid+1,r,x,y);
    return sum;
}

int main(void)
{
    int T;
    int kase=0;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        printf("Case %d:\n",++kase);
        scanf("%d",&n);
        build(1,1,n);
        while(true)
        {
            char s[10];
            scanf("%s",s);
            if(s[0]=='E')break;
            int x,y;
            scanf("%d%d",&x,&y);
            if(s[0]=='A')update(1,1,n,x,y);
            else if(s[0]=='S')update(1,1,n,x,-y);
            else printf("%d\n",query(1,1,n,x,y));
        }
    }
    return 0;
}