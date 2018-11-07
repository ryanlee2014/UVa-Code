#include<stdio.h>
#include<iostream>
#define N 100005
using namespace std;
int a[N],tree[N*4],mi[N*4],add[N*4];
char op[30];
void build(int L,int R,int root)
{
    mi[root]=N;
    tree[root]=add[root]=0;
    if(L==R)
    {
        mi[root]=a[L];
        return ;
    }
    int mid=L+R>>1;
    build(L,mid,root<<1);
    build(mid+1,R,root<<1|1);
    mi[root]=min(mi[root<<1],mi[root<<1|1]);
}
void pushdown(int root)
{
    mi[root<<1]-=add[root];
    mi[root<<1|1]-=add[root];
    add[root<<1]+=add[root];
    add[root<<1|1]+=add[root];
    add[root]=0;
}
void update(int l,int r,int L,int R,int root)
{
    if(l<=L&&R<=r)
    {
        add[root]++;
        mi[root]--;
        return ;
    }
    if(add[root])pushdown(root);
    int mid=L+R>>1;
    if(r<=mid)update(l,r,L,mid,root<<1);
    else if(l>mid)update(l,r,mid+1,R,root<<1|1);
    else
    {
        update(l,mid,L,mid,root<<1);
        update(mid+1,r,mid+1,R,root<<1|1);
    }
    tree[root]=tree[root<<1]+tree[root<<1|1];
    mi[root]=min(mi[root<<1],mi[root<<1|1]);
}
void update(int L,int R,int root)
{
    if(L==R)
    {
        int val=(-mi[root]/a[L])+1;
        tree[root]+=val;
        mi[root]+=val*a[L];
        return ;
    }
    if(add[root])pushdown(root);
    int mid=L+R>>1;
    if(mi[root<<1]<=0)update(L,mid,root<<1);
    if(mi[root<<1|1]<=0)update(mid+1,R,root<<1|1);
    tree[root]=tree[root<<1]+tree[root<<1|1];
    mi[root]=min(mi[root<<1],mi[root<<1|1]);
}
int query(int l,int r,int L,int R,int root)
{
    if(l<=L&&R<=r)
    {
        if(mi[root]<=0)update(L,R,root);
        return tree[root];
    }
    if(add[root])pushdown(root);
    int mid=(L+R)>>1;
    if(r<=mid)return query(l,r,L,mid,root<<1);
    else if(l>mid)return query(l,r,mid+1,R,root<<1|1);
    else return query(l,mid,L,mid,root<<1)+query(mid+1,r,mid+1,R,root<<1|1);
    tree[root]=tree[root<<1]+tree[root<<1|1];
    mi[root]=min(mi[root<<1],mi[root<<1|1]);
}
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        build(1,n,1);
        for(int i=0;i<m;i++)
        {
            int l,r;
            scanf("%s%d%d",op,&l,&r);
            if(op[0]=='a')update(l,r,1,n,1);
            else printf("%d\n",query(l,r,1,n,1));
        }
    }
}