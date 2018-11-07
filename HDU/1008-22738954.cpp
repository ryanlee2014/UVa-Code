#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    while(cin>>n)
    {
        if(n==0)break;
        int sum=0;
        int a[101];
        a[0]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            int dis=a[i]-a[i-1];
            if(dis>0)
            {
                sum+=dis*6+5;
            }
            else
            {
                sum+=-dis*4+5;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}