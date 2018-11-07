#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int cst[]={2,3,5,7};
int humble[6100];
int main()
{
    priority_queue<ll,vector<ll>,greater<ll> >q;
    set<ll>s;
    q.push(1);
    s.insert(1);
    for(int i=1;i<=5842;++i)
    {
        ll num=q.top();
        q.pop();
        humble[i]=num;
        for(int j=0;j<4;++j)
        {
            ll tmp=num*cst[j];
            if(!s.count(tmp))
            {
                s.insert(tmp);
                q.push(tmp);
            }
        }
    }
    int n;
    while(cin>>n&&n)
    {
        printf("The %d",n);
        int t=n%10;
        int tt=n%100;
        if(tt!=11&&tt!=12&&tt!=13)
        {
            if(t==1)
                printf("st");
            else if(t==2)
                printf("nd");
            else if(t==3)
                printf("rd");
            else
                printf("th");
        }
        if(tt==11||tt==12||tt==13)
            printf("th");
        printf(" humble number is %d.\n",humble[n]);
    }
}