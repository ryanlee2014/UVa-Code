#include <stdio.h>
#include <string.h>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define ms(x) memset(x,0,sizeof(x))
#define rep(i, a, b) for(int i=a;i<b;++i)
char currency[31][50];
double map[31][31];
int n;
inline bool Floyd()
{
    rep(k,0,n)rep(i,0,n)rep(j,0,n)map[i][j]<map[i][k]*map[k][j]&&(map[i][j]=map[i][k]*map[k][j]);
    rep(i,0,n)if(map[i][i]>1.0)return true;
    return false;
}
int search(char *ch)
{
    rep(i,0,n)if(!strcmp(ch,currency[i])) return i;
    return NULL;
}
int main(void)
{
    int m,kase=0;
    char temp1[50],temp2[50];
    double rate;
    while(~in(n)&&n)
    {
        ms(map);
        rep(i,0,n)ins(currency[i]);
        in(m);
        rep(i,0,m)ins(temp1),inf(rate),ins(temp2),map[search(temp1)][search(temp2)]=rate;
        printf("Case %d: ",++kase);
        puts(Floyd()?"Yes":"No");
    }
    return 0;
}