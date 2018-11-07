#include <iostream>
using namespace std;

int p = 47;
bool grid[3010][3010];
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    for(int i = 0;i<2000;++i){
        for(int j = 0;j<p;++j) {
            grid[i][j*p+(i/p+i%p*j)%p] = true;
        }
    }
    cout << 2000 << "\n";
    for(int i = 0;i<2000;++i) {
        for(int j = 0;j<2000;++j) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
