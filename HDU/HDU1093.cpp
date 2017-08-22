#include<iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int a;
    int n;
    int p;
    int sum=0;
    cin>>p;
    for (int j = 0; j < p; j++)
    {
        cin>>n;
            for (int i = 0; i < n; i++) {
                cin>>a;
                sum+=a;
            }
            cout<<sum<<endl;
            sum=0;
    }
    return 0;
}
