#include <cstdio>
#include <stack>
#include <set>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <functional>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <string>
#include <map>
#include <iomanip>
#include <cmath>
#define LL long long
#define ULL unsigned long long
#define SZ(x) (int)x.size()
#define MP(a, b) make_pair(a, b)
#define MS(arr, num) memset(arr, num, sizeof(arr))
#define PB push_back
#define F first
#define S second
#define ROP freopen("input.txt", "r", stdin);
#define MID(a, b) (a + ((b - a) >> 1))
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
#define lrt rt << 1
#define rrt rt << 1|1
#define root 1,n,1
#define BitCount(x) __builtin_popcount(x)
#define BitCountll(x) __builtin_popcountll(x)
#define LeftPos(x) 32 - __builtin_clz(x) - 1
#define LeftPosll(x) 64 - __builtin_clzll(x) - 1
const double PI = acos(-1.0);
const int INF = 1e7;
using namespace std;
const double eps = 1e-5;
const int MAXN = 300 + 10;
const int MOD = 1000007;
const int N=1000100;
const int MAX=log2(N*1.0);
typedef pair<int, int> pii;
typedef pair<int, string> pis;
int n,m,ans,vis[N],v;
char s[N];
int slove(char *c)
{
    int i=0,j,k,len=strlen(c);
    while(i<len) {
        if (c[i++]=='c') {
            k=0;
            while(i<len && c[i]=='f') i++,k++;
            if (k<2) {
                if (i==len) return k;
                else {
                    return -1;
                }
            }
            else if (i==len) break;
            else  {
                ans++;
            }
        }
    }
    return k;
}
int main()
{
    int i,j,T,K=1;
    cin>>T;
    getchar();
    while(T--)
    {
        ans=0;
        int flag=0;

        gets(s);  // 可能有空格
        for (i=0;s[i];i++) if(s[i]!='c' && s[i]!='f') break;//有c 和 f 之外的字符的话直接输出-1
        if (s[i]) {
            printf("Case #%d: -1\n",K++);
            continue ;
        }
        for (i=0;s[i];i++) if (s[i]=='c') {
                break;
            }
        v=i;
        if (!s[i]) {
            if (i<=2) ans=1;
            else if (i&1) ans=i/2+1;
            else ans=i/2;
        }
        else {
            int k=slove(s+i);
            if (k<0 || k+v<2) ans=-1;
            else  {
                ans++;
            }
        }
        printf("Case #%d: %d\n",K++,ans);
    }
}

