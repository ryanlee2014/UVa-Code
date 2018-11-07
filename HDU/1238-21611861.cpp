#include <iostream>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
#define s(a,b) sort(a,b)
using namespace std;
string str[110];
int main(void)
{
    int t;
    bool f;
    in(t);
    int i,j,k,n;
    while (t--)
    {
        in(n);
        for (i = 0; i < n; i++)
            cin >> str[i];
        s(str,str+n);
        f = false;
        int len=str[0].length();
        for (k = len; k; k--)
        {
            for (i = 0; i + k <= len; i++)
            {
                string a(str[0].substr(i, k));
                string b(a.rbegin(), a.rend());
                for (j = 1; j < n; j++)
                    if (str[j].find(a) == str[j].npos && str[j].find(b) == str[j].npos) break;
                if (j == n)
                {
                    f = true;
                    break;
                }
            }
            if (f) break;
        }
        f ? printf("%d\n", k) : puts("0");
    }
    return 0;
}