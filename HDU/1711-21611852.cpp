#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
const int maxn=1000000+100;
int arr1[maxn],arr2[10000+100];
int dict[10000+100];
int a,b;
int ans=-1;
void init()
{
    int len=b;
    int i=0;
    int j=-1;
    dict[0]=-1;
    while(i<len)
    {
        while(j!=-1&&arr2[i]!=arr2[j])
            j=dict[j];
        dict[++i]=++j;
    }
}

void kmp()
{
    int i=0,j=0;
    int len=a;
    while(i<len)
    {
        while(j!=-1&&arr1[i]!=arr2[j])
            j=dict[j];
        ++i,++j;
        if(j==b)
        {
            out(i-j+1);
            return ;
        }
    }
    out(-1);
    return;
}

int main(void)
{
    int T;
    in(T);
    while(T--)
    {
        ans=-1;
        in(a),in(b);
        for (int i = 0; i < a; ++i)
        {
            in(arr1[i]);
        }
        for (int i = 0; i < b; ++i)
        {
            in(arr2[i]);
        }
        init();
        kmp();
    }
    return 0;
}