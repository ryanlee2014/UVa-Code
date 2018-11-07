#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#define ll long long

using namespace std;

int main()
{
    int T;
    ll a, b;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &a);
        a--;
        if (a % 3 != 0)
        {
            printf("NO\n");
            continue;
        }
        a /= 3;
        b = sqrt(a);
        if (b * (b + 1) == a)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    //system("pause");
    return 0;
}