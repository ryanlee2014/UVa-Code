#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<map>
#define MAXN 100
#define EPS 1e-6
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;

char s[20][10]={"rat","ox","tiger","rabbit","dragon","snake","horse","sheep","monkey","rooster","dog","pig"};

map<string,int> dict;

void init()
{
    dict.clear();
    for(int i=0;i!=12;++i) dict[s[i]]=i+1;
}

char s1[MAXN],s2[MAXN];

int main()
{
    int T;
    scanf("%d",&T);
    init();
    while(T--)
    {
        scanf("%s%s",s1,s2);
        int ans=dict[s1]-dict[s2];
        if(!ans) ans+=12;
        else if(ans>0) ans=12-ans;
        else if(ans<0) ans=-ans;
        printf("%d\n",ans);
    }
}
