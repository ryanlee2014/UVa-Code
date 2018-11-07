#include <iostream>
using namespace std;
string s1,s2;
int main(void)
{
    while(cin>>s1>>s2)
    {
        s1=s1+s1;
        if(s1.find(s2)!=s1.npos)
        {
            puts("yes");
        }
        else
            puts("no");
    }
    return 0;
}