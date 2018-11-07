#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
struct Node
{
    string name;
    int h,m;
    bool operator<(const Node& v)const
    {
        if(h!=v.h)return h<v.h;
        if(m!=v.m)return m<v.m;
        return strcmp(name.c_str(),v.name.c_str())<0;
    }
    bool operator==(const Node& v)const
    {
        return h==v.h&&m==v.m;
    }
};
Node node[20];
int main(void)
{
    int t;
    int kase=0;
    while(~in(t))
    {
        if(t==0)break;
        if(kase)
        {
            puts("");
        }
        printf("Case #%d\n",++kase);
        for (int i = 0; i < t; ++i)
        {
            cin>>node[i].name;
            scanf("%d:%d",&node[i].h,&node[i].m);
        }
        sort(node,node+t);
        int k=1;
        for (int i = 0; i < t; ++i)
        {
            if(i==0)
            {
                printf("%s %d\n",node[i].name.c_str(),k);
            }
            else
            {
                if(node[i]==node[i-1])
                {
                    printf("%s %d\n",node[i].name.c_str(),k);
                }
                else
                {
                    k=i+1;
                    printf("%s %d\n",node[i].name.c_str(),k);
                }
            }
        }
    }
    return 0;
}