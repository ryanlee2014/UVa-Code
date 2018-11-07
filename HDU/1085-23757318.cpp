#include <iostream>
using namespace std;
inline int solve(int a,int b,int c)
{
    if(a==0)return 1;
    int key = b*2+a+1;
    if(key<5)return key;
    return c*5+key;
}
int main()
{
    ios::sync_with_stdio(false);
    int a,b,c;
    while(cin>>a>>b>>c&&(a||b||c))
    {
        cout<<solve(a,b,c)<<endl;
    }
}