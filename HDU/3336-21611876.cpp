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
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
using namespace std;
const int maxn=1e6+100;
char str[maxn];
int dict[maxn];

void init(int len)
{
    int i=0;
    int j=-1;
    dict[0]=-1;
    while(i<len)
    {
        if(j==-1||str[i]==str[j])
        {
            ++i,++j;
            dict[i]=j;
        }
        else
        {
            j=dict[j];
        }
    }
}

int find(int len)
{
    int j;
    int sum=0;
    rep(i,1,len+1)
    {
        j=i;
        while(j)
        {
            sum=(sum+1)%10007;
            j=dict[j];
        }
    }
    return sum;
}

int main(void)
{
    int t;
    in(t);
    while(t--)
    {
        ms(dict);
        int len;
        in(len);
        c();
        ins(str);
        init(len);
        out(find(len));
    }
    return 0;
}