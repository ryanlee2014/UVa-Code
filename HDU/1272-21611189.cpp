#include<cstdio>
using namespace std;
int set[100010];
bool mark[100010];

int find(int x)
{
    int r=x;
    while(set[r]!=r)
        r=set[r];
    return r;
}
bool merge(int x,int y)
{
    int fx,fy;
    fx= find(x);
    fy= find(y);
    if(fx!=fy)
    {
        set[fx]=fy;
        return true;
    }
    else
        return false;
}
int main(void)
{
    int a,b,i,flag,cnt;
    int min,max;
    while(scanf("%d%d",&a,&b)&&(a!=-1 && b!=-1))
    {
        flag=1;cnt=0;
        if(a==0 && b==0)
        {
            printf("Yes\n");
            continue;
        }
        for(i=0;i<100010;i++)
        {
            set[i]=i;mark[i]=0;
        }
        min=9999999;max=-1;
        while(a||b)
        {
            if(a>max) max=a;
            if(b>max) max=b;
            if(a<min) min=a;
            if(b<min) min=b;
            mark[a]=1;mark[b]=1;
            if(!merge(a,b))
                flag=0;
            scanf("%d%d",&a,&b);
        }

        if(flag==0)
            printf("No\n");
        else
        {
            for(i=min;i<=max;i++)
                if(mark[i] && set[i]==i)
                    cnt++;
            if(cnt==1)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
    return 0;
}