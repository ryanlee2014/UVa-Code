#include<cstdio>  
#include<cmath>  
#include<cstring>  
#include<algorithm>  
using namespace std;  
#define ll long long  
#define N 50005  
int n,m,ans;  
int q[N],p[N];  
char s[N];  
void fun(int l,int r) {  
    int x,y,v;  
    x=y=v=0;  
    q[y]=0;  
    p[y]=r-1;  
    y++;  
    while(l>=0&&r<n) {  
        v+=abs(s[r]-s[l]);  
        q[y]=v;  
        p[y]=r;  
        y++;  
        while(v-q[x]>m)x++;  
        ans=max(ans,r-p[x]);  
        l--,r++;  
    }  
    //printf("%d\n",ans);  
}  
int main() {  
    int T;  
    int i;  
    scanf("%d",&T);  
    while(T--) {  
        scanf("%d",&m);  
        scanf("%s",s);  
        n=strlen(s);  
        ans=0;  
        for(i=1; i<n; i++) {  
            fun(i-1,i);  
            fun(i-2,i);  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}  