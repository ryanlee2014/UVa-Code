#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a;
    int n;
    int sum=0;
    cin>>n;
    while (1)
    {
        if(n==0)
        {
            break;
        }
        else
        {
            for (int i = 0; i < n; i++) {
                cin>>a;
                sum+=a;
            }
            cout<<sum<<endl;
            sum=0;
            cin>>n;
        }
    }
    return 0;
}