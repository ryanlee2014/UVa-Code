#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
const int maxn=10010;
char str[maxn];
char arr[maxn];
char brr[maxn];
char convert[maxn];
map<string, string> mp;
int main(void)
{
    gets(str);
    while (~scanf("%s%s", arr, brr), strcmp(arr, "END"))
    {
        mp[brr] = arr;
    }
    getchar();
    char ch;
    int k = 0;
    while (~scanf("%c", &ch))
    {
        if (isalpha(ch))
            convert[k++] = ch;
        else
        {
            convert[k] = '\0';
            k = 0;
            if (strcmp(convert, "END") == 0)
                break;
            if (mp.find(convert) != mp.end())
            {
                printf("%s", mp[convert].c_str());
            } 
            else 
                printf("%s", convert);
            printf("%c", ch);
        }
    }
    return 0;
}