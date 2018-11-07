#include <iostream>
using namespace std;
int main()
{
    int sum;
    int n=0;
    while(cin>>n)
    {
        sum=0;
        for (int i = 0; i <= n; i++) {
            sum+=i;
        }
        cout<<sum<<endl<<endl;
    }
    return 0;
}