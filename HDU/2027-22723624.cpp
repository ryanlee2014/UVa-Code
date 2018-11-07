#include <bits/stdc++.h>
#define it int
#define db double
#define in(x) scanf("%d",&x)
#define out(x) printf("%d",x)
#define rep(i,j,k) for(int i=j;i<k;++i)
#define wl(x) while(x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
const int maxn=500500;
int hsh[5]={'a','e','i','o','u'};
char s[300];
int cnt[257];
int main(int argc, char const *argv[])
{
    int T;
    in(T);
    getchar();
    wl(T--)
    {
        ms(cnt);
        gets(s);
        it len=strlen(s);
        rep(i,0,len)
        {
            cnt[s[i]]++;
        }
        rep(i,0,5)
        {
            printf("%c:%d\n",hsh[i],cnt[hsh[i]]);
        }
        if(T)puts("");
    }
    return 0;
}