#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
typedef long long ll;
const int maxn = 5005;
char s[5005];
unsigned short dp[maxn][maxn];
int len, m;
bool check(int mid)
{
    for(int i = 1; i <= len; i++)
    {
        if(i + mid*2-1 > len) break;
        for(int  j= i + mid; j <= len; j++)
        {
            if(j + mid - 1 > len) break;
            if(dp[i][j+mid-1] - dp[i+mid][j-1] <= m)
                return true;
        }
    }
    return false;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &m);
        scanf("%s", s+1);
        len = strlen(s+1);
        for(int k = 1; k <= len; k++)
        {
            for(int i = 1; i <= len; i++)
            {
                int j = i + k - 1;
                if(j > len) break;
                if(i == j) dp[i][j] = 0;
                else if(j - i == 1) dp[i][j] = abs(s[i] - s[j]);
                else dp[i][j] = dp[i+1][j-1] + abs(s[i] - s[j]);

            }
        }
        int left = 1, right = len/2, mid, ans;
        while(left <= right)
        {
            mid = (left + right) >> 1;
            if(check(mid))
            {
                ans = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}