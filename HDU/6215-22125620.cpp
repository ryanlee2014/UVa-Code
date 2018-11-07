#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <algorithm>

using namespace std;

struct node
{
    node() :l(-1), r(-1) {};
    int l, r;
};

list<node> a;
vector<int> ans;

int k1[100010];
int k2[100010];

int main()
{
    int T, n, t;
    bool p;
    node now;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &k1[i]);
        }
        t = 0;
        for (int i = 0; i < n; ++i)
        {
            if ((i > 0 && k1[i] < k1[i - 1]) || (i < n - 1 && k1[i] > k1[i + 1]))
            {
                continue;
            }
            k2[t++] = k1[i];
        }
        k2[t++] = -1;
        a.clear();
        now.l = 0;
        for (int i = 1; i < t; ++i)
        {
            if (k2[i] < k2[i - 1])
            {
                now.r = i - 1;
                a.push_back(now);
                now.l = i;
            }
        }
        p = true;
        list<node>::iterator j;
        list<node>::iterator k;
        while (p)
        {
            p = false;
            j = a.begin();
            k = a.begin();
            if (a.begin() != a.end()) k++;  
            for (int i = 0; i < (int)a.size() - 1; ++i, ++j, ++k)
            {
                
                if (k2[j->r] > k2[k->l])
                {
                    (j->r)--;
                    (k->l)++;
                    p = true;
                }
            }
            for (j = a.begin(); j != a.end(); ++j)
            {
                if ((j->r) - (j->l) < 0)
                {
                    j = a.erase(j);
                }
            }
        }
        ans.clear();
        for (j = a.begin(); j != a.end(); ++j)
        {
            for (int i = j->l; i <= j->r; ++i)
            {
                ans.push_back(k2[i]);
            }
        }
        printf("%d\n", ans.size());
        for (int i = 0; i < ans.size(); ++i)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    //system("pause");              
    return 0;
}