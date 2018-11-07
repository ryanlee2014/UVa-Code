#pragma GCC optimize("O3")

#include <iostream>
#include <cstdio>
#include <cstring>
#include <list>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <complex>
#include <array>

#define wl(x) while(x)
#define bl bool
#define rtn return
#define ope operator
#define cst const
#define it int
#define cr char
#define il inline
#define tpl template
#define cl class
#define db double
#define sf(x) sizeof(x)
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;

/*
 * 输入挂
 * 场场AK buff
 */

class endln {
};

class iofstream {
private:
    int idx;
    bool eof;
    char buf[100005], *ps, *pe;
    char bufout[100005], outtmp[50], *pout, *pend;

    inline void rnext() {
        if (++ps == pe)
            pe = (ps = buf) + fread(buf, sf(cr), sf(buf) / sf(cr), stdin), eof = true;
        if (ps == pe)
            eof = false;
    }

    inline void write() {
        fwrite(bufout, sf(cr), pout - bufout, stdout);
        pout = bufout;
    }

public:
    iofstream(char *in = NULL, char *out = NULL) : idx(-1), eof(true) {
        ps = buf, pe = buf + 1;
        pout = bufout, pend = bufout + 100005;
        if (in)
            freopen(in, "r", stdin);
        if (out)
            freopen(out, "w", stdout);
    }

    ~iofstream() {
        write();
    }

    tpl<cl T>
    il bl fin(T &ans) {
#ifdef ONLINE_JUDGE
        ans = 0;
        T f = 1;
        if (ps == pe) {
            eof = false;
            rtn false;//EOF
        }
        do {
            rnext();
            if ('-' == *ps) f = -1;
        } wl(!isdigit(*ps) && ps != pe);
        if (ps == pe) {
            eof = false;
            rtn false;//EOF
        }
        do {
            ans = (ans << 1) + (ans << 3) + *ps - 48;
            rnext();
        } wl(isdigit(*ps) && ps != pe);
        ans *= f;
#else
        cin >> ans;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl fdb(T &ans) {
#ifdef ONLINE_JUDGE
        ans = 0;
        T f = 1;
        if (ps == pe) rtn false;//EOF
        do {
            rnext();
            if ('-' == *ps) f = -1;
        } wl(!isdigit(*ps) && ps != pe);
        if (ps == pe) rtn false;//EOF
        do {
            ans = ans * 10 + *ps - 48;
            rnext();
        } wl(isdigit(*ps) && ps != pe);
        ans *= f;
        if (*ps == '.') {
            rnext();
            T small = 0;
            do {
                small = small * 10 + *ps - 48;
                rnext();
            } wl(isdigit(*ps) && ps != pe);
            wl(small >= 1) {
                small /= 10;
            }
            ans += small;
        }
#else
        cin >> ans;
#endif
        rtn true;
    }

/*
 * 输出挂
 * 超强 超快
 */

    il bl out_char(cst cr c) {
#ifdef ONLINE_JUDGE
        *(pout++) = c;
        if (pout == pend) write();
            //write();
#else
        cout << c;
#endif
        rtn true;
    }

    il bl out_str(cst cr *s) {
#ifdef ONLINE_JUDGE
        wl(*s) {
            *(pout++) = *(s++);
            if (pout == pend) write();
        }
        //write();
#else
        cout << s;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_double(T x, it idx) {
        char str[50];
        string format = "%";
        if (~idx) {
            format += '.';
            format += (char) (idx + '0');
        }
        format += "f";
        sprintf(str, format.c_str(), x);
        out_str(str);
        return true;
    }

    tpl<cl T>
    il bl out_int(T x) {
#ifdef ONLINE_JUDGE
        if (!x) {
            out_char('0');
            rtn true;
        }
        if (x < 0) x = -x, out_char('-');
        it len = 0;
        wl(x) {
            outtmp[len++] = x % 10 + 48;
            x /= 10;
        }
        outtmp[len] = 0;
        for (it i = 0, j = len - 1; i < j; ++i, --j) swap(outtmp[i], outtmp[j]);
        out_str(outtmp);
#else
        cout << x;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_intln(T x) {
#ifdef ONLINE_JUDGE
        out_int(x), out_char('\n');
        //write();
#else
        cout << x << endl;
#endif
        rtn true;
    }

    tpl<cl T>
    il bl out_doubleln(T x, it idx) {
        out_double(x, idx), out_char('\n');
        return true;
    }

    il iofstream &ope<<(cst db &x) {
        out_double(x, idx);
        rtn *this;
    }

    il iofstream &ope<<(cst it &x) {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst unsigned long long &x) {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst unsigned &x) {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst long &x) {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst ll &x) {
        out_int(x);
        rtn *this;
    }

    il iofstream &ope<<(cst endln &x) {
        out_char('\n');
        rtn *this;
    }

    il iofstream &ope<<(cst cr *x) {
        out_str(x);
        rtn *this;
    }

    il iofstream &ope<<(cst string &x) {
        out_str(x.c_str());
        rtn *this;
    }

    il iofstream &ope<<(cst char &x) {
        out_char(x);
        rtn *this;
    }

    il bl setw(it x) {
        if (x >= 0) {
            idx = x;
            rtn true;
        }
        rtn false;
    }

    il iofstream &ope>>(it &x) {
        if (!fin(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(ll &x) {
        if (!fin(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(db &x) {
        if (!fdb(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(float &x) {
        if (!fdb(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(unsigned &x) {
        if (!fin(x))eof = false;
        rtn *this;
    }

    il iofstream &ope>>(unsigned long long &x) {
        if (!fin(x))eof = false;
        rtn *this;
    }

    il ope bl() {
        rtn eof;
    }

    il cr getchar() {
#ifdef ONLINE_JUDGE
        if (ps == pe) {
            eof = false;//EOF
            rtn 0;
        }
        rnext();
        if (ps + 1 == pe)
            eof = false;
        rtn *ps;
#else
        rtn std::getchar();
#endif
    }

    il iofstream &ope>>(char *str) {
#ifdef ONLINE_JUDGE
        if (ps == pe) {
            eof = false;//EOF
            rtn *this;
        }
        do {
            rnext();
        } wl(isspace(*ps) && iscntrl(*ps) && ps != pe);
        if (ps == pe) {
            eof = false;//EOF
            rtn *this;
        }
        do {
            *str = *ps;
            ++str;
            rnext();
        } wl(!(isspace(*ps) || iscntrl(*ps)) && ps != pe);
        *str = '\0';
        rtn *this;
#else
        cin >> str;
        rtn *this;
#endif
    }

    il iofstream &ope>>(string &str) {
#ifdef ONLINE_JUDGE
        str.clear();
        if (ps == pe) {
            eof = false;//EOF
            rtn *this;
        }
        do {
            rnext();
        } wl(isspace(*ps) && iscntrl(*ps) && ps != pe);
        if (ps == pe) {
            eof = false;//EOF
            rtn *this;
        }
        do {
            str += *ps;
            rnext();
        } wl(!(isspace(*ps) || iscntrl(*ps)) && ps != pe);
        rtn *this;
#else
        cin >> str;
        rtn *this;
#endif
    }

    il iofstream &getline(char *str) {
#ifdef ONLINE_JUDGE
        if (ps == pe) {
            eof = false;//EOF
            rtn *this;
        }
        do {
            rnext();
            *str = *ps;
        } while (*ps != '\n' && ps != pe && str++);
        *str = '\0';
        rtn *this;
#else
        gets(str);
        rtn *this;
#endif
    }

    il bl endfile() {
        rtn eof;
    }
};

static iofstream fin;
static endln ln;

using namespace std;

struct Node {
    int com_val;
    int len;
    int def[10], exp[10];

    Node() : len(0) {}

    Node(int len) : len(len) {
        for (int i = 0; i < len; ++i) {
            def[i] = exp[i] = 0;
        }
    }

    bool operator<(const Node &v) const {
        return com_val > v.com_val;
    }
};


int main() {
    int T;
    fin >> T;
    while (T--) {
        int n, k;
        fin >> n >> k;
        int me[10];
        for (int i = 0; i < k; ++i) {
            fin >> me[i];
        }
        priority_queue<Node> q[5];

        for (int i = 0; i < n; ++i) {
            Node node(k);
            for (int j = 0; j < k; ++j) {
                fin >> node.def[j];
            }
            for (int j = 0; j < k; ++j) {
                fin >> node.exp[j];
            }
            node.com_val = node.def[0];
            q[0].push(node);
        }
        int cnt = 0;
        int prevcnt = 0;
        for (int cur = 0;;) {
            while (!q[cur].empty() && q[cur].top().com_val <= me[cur]) {
                Node top = q[cur].top();
                q[cur].pop();
                if (cur == k - 1) {
                    ++cnt;
                    for (int i = 0; i < k; ++i) {
                        me[i] += top.exp[i];
                    }
                } else {
                    top.com_val = top.def[cur + 1];
                    q[cur + 1].push(top);
                }
            }
            cur = (cur + 1) % k;
            if(cur == 0)
            {
                if (prevcnt == cnt) {
                    break;
                }
                prevcnt = cnt;
            }
        }
        fin << cnt << '\n';
        for (int i = 0; i < k; ++i) {
            if (i)fin << " ";
            fin << me[i];
        }
        fin << '\n';
    }
}