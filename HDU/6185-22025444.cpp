#include <cstdio>
#include <iostream>
#include <cstring>
const long long int mod = 1e9 + 7;
using namespace std;
const int N = 4;
struct mat
{
    long long int a[5][5];
    mat()
    {
        memset(a, 0, sizeof(a));
    }
    void init()
    {
        memset(a, 0, sizeof(a));
    }
    mat operator *(const mat &o) const
    {
        mat t;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
                for(int k = 0; k < N; k++)
                {
                    t.a[i][j] = (1LL*t.a[i][j] + (a[i][k]%mod*o.a[k][j])%mod +mod)%mod;
                }
        }
        return t;
    }
} a, b;
int main()
{

    long long int n;
    while(~scanf("%lld", &n))
    {
        a.a[0][0] = 1, a.a[0][1] = 5, a.a[0][2] = 1, a.a[0][3] = -1;
        a.a[1][0] = 1, a.a[1][1] = 0, a.a[1][2] = 0, a.a[1][3] = 0;
        a.a[2][0] = 0, a.a[2][1] = 1, a.a[2][2] = 0, a.a[2][3] = 0;
        a.a[3][0] = 0, a.a[3][1] = 0, a.a[3][2] = 1, a.a[3][3] = 0;
        b.init();
        b.a[0][0] = 5;
        b.a[1][0] = 1;
        b.a[2][0] = 1;
        b.a[3][0] = 0;
        if(n == 1)
        {
            printf("1\n");
        }
        else
        {
            n-=2;
            while(n > 0)
            {
                if(n&1)
                {
                    b = a*b;
                }
                n >>= 1;
                a = a*a;
            }
            printf("%lld\n", b.a[0][0]);
        }

    }
    return 0;
}