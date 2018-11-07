#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <regex>
#include <vector>
#include <array>

using ll = long long;

namespace IO {
    using namespace std;

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
                pe = (ps = buf) + fread(buf, sizeof(char), sizeof(buf) / sizeof(char), stdin), eof = true;
            eof = ps != pe;
        }

        inline void write() {
            fwrite(bufout, sizeof(char), pout - bufout, stdout);
            pout = bufout;
        }

    public:
        iofstream() : idx(-1), eof(true) {
            pe = (ps = buf) + 1;
            pend = (pout = bufout) + 100005;
        }

        ~iofstream() {
            write();
        }

        template<class T>
        inline bool fin(T &ans) {
#ifdef ONLINE_JUDGE
            ans = 0;
            T f = 1;
            if (ps == pe) {
                return eof = false;
            }
            do {
                rnext();
                if ('-' == *ps) f = -1;
            } while (!isdigit(*ps) && ps != pe);
            if (ps == pe) {
                return eof = false;
            }
            do {
                ans = (ans << 1) + (ans << 3) + *ps - 48;
                rnext();
            } while (isdigit(*ps) && ps != pe);
            ans *= f;
#else
            cin >> ans;
#endif
            return true;
        }

        template<class T>
        inline bool fdb(T &ans) {
#ifdef ONLINE_JUDGE
            ans = 0;
            T f = 1;
            if (ps == pe) return false;//EOF
            do {
                rnext();
                if ('-' == *ps) f = -1;
            } while (!isdigit(*ps) && ps != pe);
            if (ps == pe) return false;//EOF
            do {
                ans = ans * 10 + *ps - 48;
                rnext();
            } while (isdigit(*ps) && ps != pe);
            ans *= f;
            if (*ps == '.') {
                rnext();
                T small = 0;
                do {
                    small = small * 10 + *ps - 48;
                    rnext();
                } while (isdigit(*ps) && ps != pe);
                while (small >= 1) {
                    small /= 10;
                }
                ans += small;
            }
#else
            cin >> ans;
#endif
            return true;
        }

/*
 * 输出挂
 * 超强 超快
 */

        inline bool out_char(const char c) {
#ifdef ONLINE_JUDGE
            *(pout++) = c;
            if (pout == pend) write();
#else
            cout << c;
#endif
            return true;
        }

        inline bool out_str(const char *s) {
#ifdef ONLINE_JUDGE
            while (*s) {
                *(pout++) = *(s++);
                if (pout == pend) write();
            }
#else
            cout << s;
#endif
            return true;
        }

        template<class T>
        inline bool out_double(T x, int idx) {
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

        template<class T>
        inline bool out_int(T x) {
#ifdef ONLINE_JUDGE
            if (!x) {
                out_char('0');
                return true;
            }
            if (x < 0) x = -x, out_char('-');
            int len = 0;
            while (x) {
                outtmp[len++] = x % 10 + 48;
                x /= 10;
            }
            outtmp[len] = 0;
            for (int i = 0, j = len - 1; i < j; ++i, --j) swap(outtmp[i], outtmp[j]);
            out_str(outtmp);
#else
            cout << x;
#endif
            return true;
        }


        inline iofstream &operator<<(const double &x) {
            out_double(x, idx);
            return *this;
        }

        inline iofstream &operator<<(const int &x) {
            out_int(x);
            return *this;
        }

        inline iofstream &operator<<(const unsigned long long &x) {
            out_int(x);
            return *this;
        }

        inline iofstream &operator<<(const unsigned &x) {
            out_int(x);
            return *this;
        }

        inline iofstream &operator<<(const long &x) {
            out_int(x);
            return *this;
        }

        inline iofstream &operator<<(const ll &x) {
            out_int(x);
            return *this;
        }

        inline iofstream &operator<<(const endln &x) {
            out_char('\n');
            return *this;
        }


        inline iofstream &operator<<(const char *x) {
            out_str(x);
            return *this;
        }

        inline iofstream &operator<<(const string &x) {
            out_str(x.c_str());
            return *this;
        }

        inline iofstream &operator<<(const char &x) {
            out_char(x);
            return *this;
        }

        inline bool setw(int x) {
            if (x >= 0) {
                idx = x;
                return true;
            }
            return false;
        }

        inline iofstream &operator>>(int &x) {
            if (!fin(x))eof = false;
            return *this;
        }

        inline iofstream &operator>>(ll &x) {
            if (!fin(x))eof = false;
            return *this;
        }

        inline iofstream &operator>>(double &x) {
            if (!fdb(x))eof = false;
            return *this;
        }

        inline iofstream &operator>>(float &x) {
            if (!fdb(x))eof = false;
            return *this;
        }

        inline iofstream &operator>>(unsigned &x) {
            if (!fin(x))eof = false;
            return *this;
        }

        inline iofstream &operator>>(unsigned long long &x) {
            if (!fin(x))eof = false;
            return *this;
        }

        inline explicit operator bool() {
            return eof;
        }

        inline char getchar() {
#ifdef ONLINE_JUDGE
            if (ps == pe) {
                return eof = false;
            }
            rnext();
            if (ps + 1 == pe)
                eof = false;
            return *ps;
#else
            return std::getchar();
#endif
        }

        inline iofstream &operator>>(char *str) {
#ifdef ONLINE_JUDGE
            if (ps == pe) {
                eof = false;//EOF
                return *this;
            }
            do {
                rnext();
            } while (isspace(*ps) && iscntrl(*ps) && ps != pe);
            if (ps == pe) {
                eof = false;//EOF
                return *this;
            }
            do {
                *str = *ps;
                ++str;
                rnext();
            } while (!(isspace(*ps) || iscntrl(*ps)) && ps != pe);
            *str = '\0';
            return *this;
#else
            cin >> str;
            return *this;
#endif
        }

        inline iofstream &operator>>(string &str) {
#ifdef ONLINE_JUDGE
            str.clear();
            if (ps == pe) {
                eof = false;//EOF
                return *this;
            }
            do {
                rnext();
            } while (isspace(*ps) && iscntrl(*ps) && ps != pe);
            if (ps == pe) {
                eof = false;//EOF
                return *this;
            }
            do {
                str += *ps;
                rnext();
            } while (!(isspace(*ps) || iscntrl(*ps)) && ps != pe);
            return *this;
#else
            cin >> str;
            return *this;
#endif
        }
    };

    static iofstream fin;
    static endln ln;
}
using namespace std;
using IO::fin;
const int maxn = 1e5 + 6;
int k;

struct Node {
    ll val;
    ll attr[5];

    ll sum() {
        ll s = val;
        for (int i = 0; i < k; ++i)s += attr[i];
        return s;
    }
};

Node mi[maxn], wi[maxn];

int main() {
    int T;
    fin >> T;
    while (T--) {
        int n, m;
        fin >> n >> m >> k;
        ll mn1[6];
        for (int i = 0; i < k; ++i)mn1[i] = 0;
        for (int i = 0; i < n; ++i) {
            fin >> mi[i].val;
            for (int j = 0; j < k; ++j)fin >> mi[i].attr[j], mn1[j] = min(mn1[j], mi[i].attr[j]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j)mi[i].attr[j] -= mn1[j];
        }
        ll mn2[6];
        for (int i = 0; i < k; ++i)mn2[i] = 0;
        for (int i = 0; i < m; ++i) {
            fin >> wi[i].val;
            for (int j = 0; j < k; ++j)fin >> wi[i].attr[j], mn2[j] = min(mn2[j], wi[i].attr[j]);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < k; ++j)wi[i].attr[j] -= mn2[j];
        }
        sort(mi, mi + n, [&](Node a, Node b) -> bool {
            return a.sum() > b.sum();
        });
        sort(wi, wi + m, [&](Node a, Node b) -> bool {
            return a.sum() < b.sum();
        });
        ll ans = 0;
        int u1 = min(600, n), u2 = min(600, m);
        for (int i = 0; i < u1; ++i) {
            for (int j = 0; j < u2; ++j) {
                ll tmp = mi[i].val + wi[j].val;
                for (int t = 0; t < k; ++t) {
                    tmp += abs(mi[i].attr[t] + mn1[t] - wi[j].attr[t] - mn2[t]);
                }
                ans = max(ans, tmp);
            }
        }
        fin << ans << '\n';
    }
}