#include <iostream>
using namespace std;
const long long MAX = 50 ;
const int mod = 7 ;
int a[MAX], A, B, n;

int main(){
    a[1] = a[2] = 1 ;
    while(cin >> A >> B >> n ){
        if( A == 0 && B == 0 && n == 0 ) break ;
        for(int i=3; i<=50; i++)
        a[i] = ( A * a[i-1] + B * a[i-2] ) % mod ;
        cout << a[n%49] << endl ;
        }
    
    return 0;
}