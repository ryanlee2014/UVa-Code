#include <cstring>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
#define maxn 211111

char P[maxn], T[maxn];
int n, m;
#define next Next
int next[maxn];
char change[33], ss[33];

void get_next (char *p) {
    int t;
    t = next[0] = -1;
    int j = 0, m = strlen (p);
    while (j < m) {
        if (t < 0 || p[j] == p[t]) {//匹配
            j++, t++;
            next[j] = t;
        }
        else //失配
            t = next[t];
    }
}

void Change (char *s) {
    for (int i = 0; i < 26; i++)
        change[ss[i]-'a'] = 'a'+i;
    int n = strlen (s);
    for (int i = 0; i < n; i++) {
        s[i] = change[s[i]-'a'];
    }
    return  ;
}

int main () {
    //freopen ("in.txt", "r", stdin);
    int t;
    scanf ("%d", &t);
    while (t--) {
        scanf ("%s%s", ss, T);
        memset (P, 0, sizeof P);
        strcpy (P, T);
        n = strlen (T);
        m = n*2;
        Change (P);
        strcat (P, T);
        get_next (P);
        int j = m, mid = n/2;
        while (next[j] > 0 && next[j] > mid) j = next[j];
        int len = n-next[j];
        for (int i = 0; i < len; i++) printf ("%c", T[i]);
        for (int i = len; i < len*2; i++) printf ("%c", change[T[i-len]-'a']);
        cout << "\n";
    }
    return 0;
}