#include <iostream>
#include <cstdio>
#include <unordered_map>
using namespace std;
unordered_map<string, int> tree;
int main(void)
{
    ios::sync_with_stdio(false);
    string s;
    getline(cin, s);
    while (s.length())
    {
        int len =s.length();
        for (int i = 1; i < len + 1; i++)
        {
            string temp(s, 0, i);
            tree[temp]++;
        }
        getline(cin, s);
    }
    string ans;
    while (cin >> ans)
        cout << tree[ans] << endl;
    return 0;
}
