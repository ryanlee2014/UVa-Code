#include<iostream>
using namespace std;
int main()
{
    int a;
    int b;
    int p;
    int n;
    cin>>p;
    int sum=0;
    for (int i = 0; i <p ; i++)
    {
        cin>>n;
        for (int j = 0; j <n ; j++) {
            cin>>a;
            sum+=a;
        }
        if(i==p-1) {
            cout << sum<<endl;
            return 0;
        }
        else
        cout<<sum<<endl<<endl;
        sum=0;
    }
    return 0;
}