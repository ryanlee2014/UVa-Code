#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
set<string>dict;
int main(void)
{
    string str;
    while(getline(cin,str)&&str!="#")
    {
        dict.clear();
        int len=str.size();
        for (int i = 0; i <len ; ++i)
        {
            string tmp;
            while(i<len&&isalpha(str[i]))
            {
                tmp+=str[i++];
            }
            if(tmp!="")dict.insert(tmp);
        }
        len=dict.size();
        printf("%d\n",len);
    }

    return 0;
}