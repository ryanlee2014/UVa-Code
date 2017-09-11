#include<cstdio>
#include<algorithm>
using namespace std;

int a[100010];
int d[100010];

int main()
{
    int T, n, k, ans1, ans2, pos; 
    scanf("%d", &T);
    while (T--)
    {
    scanf("%d %d", &n, &k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    d[1]=a[1];  
    int len=1;
    for (int i=2;i<=n;i++)
    {
        if (a[i]>=d[len]) d[++len]=a[i];  
        else  
        {
            pos =upper_bound(d+1,d+len+1,a[i])-d;  //找到第一个大于它的d的下标 
            d[pos]=a[i]; 
        }
    }
    ans1 = len;
    d[1]=a[n];  
    len=1;
    for (int i=n - 1;i>=1;i--)
    {
        if (a[i]>=d[len]) d[++len]=a[i];  
        else  
        {
            pos =upper_bound(d+1,d+len+1,a[i])-d;  
            d[pos]=a[i]; 
        }
    }
    ans2 = len;
    if (ans1 + k >= n || ans2 + k >= n)
    {
        printf("A is a magic array.\n");
    }
    else
    {
        printf("A is not a magic array.\n");
    }
    }
    return 0;
}
