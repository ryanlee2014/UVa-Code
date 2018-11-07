#include<iostream>
using namespace std;
int main()
{
    int a;
    int n;
    int sum=0;
    while(cin>>n)
    {
            for (int i = 0; i < n; i++) {
                cin>>a;
                sum+=a;
            }
            cout<<sum<<endl;
            sum=0;
    }
    return 0;
}