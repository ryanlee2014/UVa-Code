#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
int n,broken,edge,car[1050],cnt;
const int inf=0x3f3f3f3f;
char name[120][100];
int mp[120][120];
int insert(char* n)
{
    rep(i,1,cnt)
    {
        if(!strcmp(name[i],n))
            return i;
    }
    strcpy(name[cnt],n);
    return cnt++;
}
char tmp[150],s[100],m[100],e[100];
int main(void)
{
    int kase=0;
    while(~in(n)&&~in(broken)&&~in(edge)&&n+broken+edge)
    {
        msc(mp,0x3f);
        int pos=0;
        ins(name[1]);
        cnt=2;
        rep(i,0,broken)
        {
            ins(tmp);
            car[pos++]=insert(tmp);
        }
        rep(i,0,edge)
        {
            int w;
            ins(s),ins(m),ins(e);
            int len=strlen(m);
            sscanf(m+2,"%d",&w);
            int u,v;
            u=insert(s),v=insert(e);
            if(m[0]=='<'&&m[len-1]=='>')
            {
                if(mp[u][v]>w)
                    mp[u][v]=w;
                if(mp[v][u]>w)
                    mp[v][u]=w;
            }
            else if(m[0]=='<')
            {
                if(mp[v][u]>w)mp[v][u]=w;
            }
            else if(m[len-1]=='>')
            {
                if (mp[u][v] > w)mp[u][v] = w;
            }
        }
        rep(k,1,n+1)
            rep(i,1,n+1)
                rep(j,1,n+1)
                {
                    if(mp[i][j]>mp[i][k]+mp[k][j])
                        mp[i][j]=mp[i][k]+mp[k][j];
                }
        int ans=0;
        rep(i,0,pos)
            ans+=mp[1][car[i]]+mp[car[i]][1];
        printf("%d. %d\n",++kase,ans);
    }
    return 0;
}