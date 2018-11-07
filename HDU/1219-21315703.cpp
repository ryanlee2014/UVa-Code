#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
char str[100100];
int alpha[26];
int main(void)
{
    while(gets(str))
    {
        ms(alpha);
        int len=strlen(str);
        rep(i,0,len)
        {
            if(islower(str[i]))alpha[str[i]-'a']++;
        }
        rep(i,0,26)
        {
            printf("%c:%d\n",'a'+i,alpha[i]);
        }
        puts("");
    }
    return 0;
}