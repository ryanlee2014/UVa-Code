#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
using namespace std;
struct Node{
    int start,end,weight;
    Node(){}
    Node(int s,int e,int w):start(s),end(e),weight(w){}
    bool operator<(const Node& v)const
    {
        return weight<v.weight;
    }
};
Node node[210];
int village[50];
int num,cnt;
int find(int x)
{
    return (village[x]==x?x:find(village[x]));
}

void init()
{
    for(int i=0;i<50;i++)village[i]=i;
}

int Kruskal()
{
    sort(node,node+cnt);
    int sum=0;
    init();
    for (int i = 0; i < cnt; ++i)
    {
        int x=find(node[i].start);
        int y=find(node[i].end);
        if(x!=y)
        {
            sum+=node[i].weight;
            village[x]=village[y];
        }
    }
    return sum;
}

int main(void)
{
    while(~scanf("%d",&num)&&num)
    {
        cnt=0;
        for(int p=0;p<num-1;++p)
        {
            getchar();
            char v;
            int edge;
            scanf("%c%d", &v, &edge);
            int x = v - 'A';
            for (int i = 0; i < edge; ++i)
            {
                char l;
                int w;
                getchar();
                scanf("%c%d",&l,&w);
                int y=l-'A';
                node[cnt].start=x;
                node[cnt].end=y;
                node[cnt].weight=w;
                cnt++;
            }
        }
        printf("%d\n",Kruskal());
    }
    return 0;
}