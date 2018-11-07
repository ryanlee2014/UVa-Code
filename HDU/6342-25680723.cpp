#include <iostream>
#include <algorithm>
#include <array>
#include <cstring>
#include <vector>

#define NUMBER 0
#define OPERATOR 1
#define UNKNOWN 2
using ll = long long;
using namespace std;

int judge(char t) {
    if (t >= '0' && t <= '9') {
        return NUMBER;
    } else if (t == '+' || t == '*') {
        return OPERATOR;
    } else {
        return UNKNOWN;
    }
}

bool isprezero(string s, int pos) {
    int cnt = 1;
    while (pos >= 0) {
        int tp = judge(s[pos]);
        if (tp == OPERATOR) {
            if (s[pos + 1] == '0') {
                return true;
            } else {
                return false;
            }
        }
        --pos;
    }
    return s[0] == '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        string exp;
        cin >> s;
        int len = s.length();
        int prev_type = judge(s[0]);
        if (prev_type == NUMBER) {
            if (s[0] == '0' && judge(s[1]) == NUMBER) {
                cout << "IMPOSSIBLE" << "\n";
                continue;
            } else {
                exp += s[0];
            }
        } else if (prev_type == OPERATOR) {
            cout << "IMPOSSIBLE" << "\n";
            continue;
        } else {
            prev_type = NUMBER;
            exp += '1';
        }
        bool valid = true;
        for (int i = 1; i < len; ++i) {
            int tp = judge(s[i]);
            if (tp == OPERATOR && (prev_type == tp || i + 1 >= len)) {
                cout << "IMPOSSIBLE" << "\n";
                valid = false;
                break;
            } else if (tp == NUMBER && prev_type == OPERATOR
                       && i + 1 < len && (judge(s[i + 1]) == NUMBER || judge(s[i + 1]) == UNKNOWN)) {
                if (s[i] == '0' && judge(s[i + 1]) == NUMBER) {
                    cout << "IMPOSSIBLE" << "\n";
                    valid = false;
                    break;
                } else if (s[i] == '0' && judge(s[i + 1]) == UNKNOWN) {
                    s[i + 1] = '+';
                }
            } else if (tp == UNKNOWN) {
                if (isprezero(s, i - 1)) {
                    if (i + 1 < len) {
                        s[i] = '+';
                        exp += '+';
                        prev_type = OPERATOR;
                    } else {
                        cout << "IMPOSSIBLE" << "\n";
                        valid = false;
                        break;
                    }
                    continue;
                } else {
                    prev_type = NUMBER;
                    exp += '1';
                    continue;
                }
            }
            prev_type = tp;
            exp += s[i];
        }
        if (valid) {
            cout << exp << "\n";
        }
    }
}