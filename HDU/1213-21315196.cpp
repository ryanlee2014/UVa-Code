#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define in(x) scanf("%d",&x)
int unionset[1001];
void bind(int x,int y)
{
    unionset[x]=y;
}
int find(int x)
{
    if(x!=unionset[x])
        x=find(unionset[x]);
    return unionset[x];
}
int main(void)
{
    int T;
    in(T);
    while(T--)
    {
        int friends,line;
        int x,y;
        in(friends);
        in(line);
        for(int i=1;i<=friends;i++)unionset[i]=i;
        for (int j = 0; j < line; ++j)
        {
            in(x);
            in(y);
            x=find(x);
            y=find(y);
            bind(x,y);
        }
        int cnt=0;
        for (int i = 1; i <=friends ; ++i)
        {
            if(unionset[i]==i)cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}