#include <iostream>
using namespace std;
string s1,s2;
int main(void)
{
    ios::sync_with_stdio(false);
    while(cin>>s1>>s2)
    {
        s1+=s1;
        if(s1.find(s2)!=s1.npos)
        {
            cout<<"yes"<<endl;
        }
        else
            cout<<"no"<<endl;
    }
    return 0;
}
