#include<stdio.h>
#include<string.h>
#define MAX 3005
#define INF 0x3f3f3f3f

int dj[MAX];

int main()
{
    int n,m,u,v,w,i;
    while(~scanf("%d%d",&n,&m)){
        memset(dj,0,sizeof(dj));
        for(i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            if(u!=v){
                dj[u]+=w;
                dj[v]+=w;
            }
        }
        int min=INF;
        for(i=1;i<=n;i++){
            if(dj[i]<min) min=dj[i];
        }
        printf("%d\n",min);
    }
    return 0;
}