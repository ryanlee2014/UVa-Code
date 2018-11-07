#include <iostream>
#include <cstring>

using namespace std;

int p = 47;
char grid[3010][3010];
int main() {
    ios::sync_with_stdio(false);
    cout.tie(0);
    memset(grid,'0',sizeof(grid));
    for(int i = 0;i<2000;++i){
        for(int j = 0;j<p;++j) {
            grid[i][j*p+(i/p+i%p*j)%p] = '1';
        }
    }
    cout << 2000 << "\n";
    for(int i = 0;i<2000;++i) {
        grid[i][2000] = 0;
        cout << grid[i] << "\n";
    }
}
