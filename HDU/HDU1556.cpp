#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
int tr[100010];
int n;
inline int lowbit(int x)
{
    return x&-x;
}

void add(int num,int k)
{
    while(k<=n)
    {
        tr[k]+=num;
        k+=lowbit(k);
    }
}

int sum(int k)
{
    int sum=0;
    while(k)
    {
        sum+=tr[k];
        k-=lowbit(k);
    }
    return sum;
}
int main(void)
{
    while(~in(n)&&n) {
        ms(tr);
        for (int i = 0; i < n; ++i) {
            int a,b;
            in(a),in(b);
            add(1,a);
            add(-1,b+1);
        }
        for (int i = 1; i <n ; ++i) {
            printf("%d ",sum(i));
        }
        out(sum(n));
    }
}