#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
string number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int convert(string& a)
{
    rep(i,0,10)
    {
        if(a==number[i])return i;
    }
    return -1;
}
int main(void)
{
    ios::sync_with_stdio(false);
    string a;
    string part_one,part_two;
    while(true)
    {
        part_one.clear();
        part_two.clear();
        while(true)
        {
            cin>>a;
            if(a!="+")
            {
                part_one+=convert(a)+'0';
            }
            else
                break;
        }
        while(true)
        {
            cin>>a;
            if(a!="=")
            {
                part_two+=convert(a)+'0';
            }
            else
                break;
        }
        if(part_one=="0"&&part_two=="0")break;
        cout<<atoi(part_one.c_str())+atoi(part_two.c_str())<<endl;
    }
    return 0;
}