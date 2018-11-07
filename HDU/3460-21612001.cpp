#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define out(x) printf("%d\n",x)
#define qs(x,n,t,c) qsort(x,n,sizeof(t),c)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define len(x) strlen(x)
int cal(char* a,char *b)
{
    int l1=len(a),l2=len(b);
    int i;
    for(i=0;i<l1&&i<l2&&a[i]==b[i];++i);
    return l1+l2-2*i;
}

inline int cmp(const void* a,const void* b)
{
    char* s1=(char*)a;
    char* s2=(char*)b;
    return strcmp(s1,s2);
}

char str[50005][100];
int main(void)
{
    int n;
    while(~in(n))
    {
        rep(i,0,n)ins(str[i]);
        qs(str,n,str[0],cmp);
        int big=len(str[0]);
        int sum=big+1;
        rep(i,1,n)
        {
            sum+=cal(str[i],str[i-1])+1;
            big=max(big,(int)len(str[i]));
        }
        out(sum+len(str[n-1])-big);
    }
    return 0;
}