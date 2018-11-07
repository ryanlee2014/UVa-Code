#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,T;
    cin>>T;
    for(int t=1;t<=T;++t)
    {
        cin>>n;
        int sum=0;
        for(int i=0;i<n;++i)
        {
            int x;
            cin>>x;
            sum+=(x+9)/10+x;
        }
        cout<<"Case #"<<t<<": "<<sum<<endl;
    }
}