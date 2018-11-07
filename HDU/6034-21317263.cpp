#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
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
const int MOD = 1e9+7;
const int maxn = 100100;
int maxLen,num,power[maxn],sum[26];
int alpha[26][maxn];
bool leadingZero[26];
char str[maxn];
int a[26];
typedef long long ll;

bool cmp(int a,int b)
{
    for(int i=maxLen-1;i>=0;--i)
    {
        if(alpha[a][i]!=alpha[b][i])
            return alpha[a][i]<alpha[b][i];
    }
    return 0;
}

void prepare()
{
    power[0]=1;
    rep(i,1,maxn+1)power[i]=(ll)power[i-1]*26%MOD;
}

inline void init()
{
    ms(alpha);
    ms(leadingZero);
    ms(sum);
    rep(i,0,26)a[i]=i;
    maxLen=0;
}

void work()
{
    init();
    rep(i,0,num)
    {
        ins(str);
        int len=strlen(str);
        if(len>1)leadingZero[str[0]-'a']=true;
        rep(j,0,len)
        {
            ++alpha[str[j]-'a'][len-j-1];
            sum[str[j]-'a']+=power[len-j-1];
            if(sum[str[j]-'a']>MOD)sum[str[j]-'a']-=MOD;
        }
        maxLen=max(len,maxLen);
    }
    rep(i,0,26)
    {
        rep(j,0,maxLen)
        {
            alpha[i][j+1]+=alpha[i][j]/26;
            alpha[i][j]%=26;
        }
        while(alpha[i][maxLen]>26)
        {
            alpha[i][maxLen+1]+=alpha[i][maxLen]/26;
            alpha[i][maxLen++]%=26;
        }
    }
    sort(a,a+26,cmp);
    int zero_pos = -1;
    rep(i,0,26)
    {
        if(!leadingZero[a[i]])
        {
            zero_pos=a[i];
            break;
        }
    }
    int ans=0,al=25;
    rvep(i,25,0)
    {
        if(a[i]!=zero_pos)
        {
            ans+=(ll)(al--)*sum[a[i]]%MOD;
            ans%=MOD;
        }
    }
    static int kase=0;
    printf("Case #%d: %d\n",++kase,ans);
}


int main(void)
{
    prepare();
    while(~in(num))work();
    return 0;
}