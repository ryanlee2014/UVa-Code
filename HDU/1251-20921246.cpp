#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;
unordered_map<string, int> table;

int main(void)
{
    string s;
    getline(cin, s);
    while (s != "")
    {
        int len = (int) s.length();
        for (int i = 1; i < len + 1; i++)
        {
            string temp(s, 0, i);
            table[temp]++;
        }
        getline(cin, s);
    }

    string ans;
    while (cin >> ans)
        cout << table[ans] << endl;
    return 0;
}