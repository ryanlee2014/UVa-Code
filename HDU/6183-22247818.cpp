#include <bits/stdc++.h>
using namespace std;
const int maxm = 3000010;
int tot, l[maxm], r[maxm], v[maxm], T[51];
void update(int &x,int L,int R,int pos,int val)
{
    if(!x)
    {
        x = ++tot;
        v[x] = val;
    }
    if(v[x]>val) v[x] = val;
    if(L==R)return;
    int mid=(L+R)>>1;
    if(pos<=mid) update(l[x],L,mid,pos,val);
    else update(r[x],mid+1,R,pos,val);
}
int flag;
int X;
int c, d;
 
void query(int x, int L, int R)
{
    if(flag||!x) return;
    if(c<=L && R<=d)
    {
        if(v[x]<=X)flag=1;
        return;
    }
    int mid=(L+R)>>1;
    if(c<=mid) query(l[x],L,mid);
    if(d>mid) query(r[x],mid+1,R);
}
int main()
{
    for(int i=0; i<=50; i++)
    {
        T[i]=0;
    }
    while(1)
    {
        int op;
        scanf("%d", &op);
        if(op==3)return 0;
        if(op==0)
        {
            for(int i=1; i<=tot; i++)l[i]=r[i]=0;
            for(int i=0; i<=50; i++)T[i]=0;
            tot=0;
        }
        if(op==1)
        {
            int x, y, c;
            scanf("%d %d %d", &x,&y,&c);
            update(T[c], 1, 1000000, y, x);
        }
        if(op==2)
        {
            scanf("%d %d %d", &X,&c,&d);
            int ans=0;
            for(int i=0; i<=50; i++)
            {
                flag=0;
                query(T[i], 1, 1000000);
                if(flag) ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}