#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxn = 4;

struct Matrix {
    int v[maxn][maxn];
    Matrix() {
        memset(v, 0, sizeof(v));
    }
};
int n, m;

Matrix Mul(Matrix a, Matrix b) {
    Matrix c;
    for (int i = 0; i < maxn; i++) 
        for (int j = 0; j < maxn; j++) 
            for (int k = 0; k < maxn; k++)
                c.v[i][j] = (c.v[i][j]+a.v[i][k]*b.v[k][j])%m;
    return c;
}

Matrix powMul(Matrix a, int k) {
    Matrix tmp;
    for (int i = 0; i < maxn; i++)
        tmp.v[i][i] = 1;
    while (k) {
        if (k & 1)
            tmp = Mul(a, tmp);
        k >>= 1;
        a = Mul(a, a);
    }
    return tmp;
}

int main() {
    Matrix a, b, c;
    a.v[0][0] = 9;
    a.v[1][0] = 6;
    a.v[2][0] = 4;
    a.v[3][0] = 2;
    b.v[0][0] = b.v[0][2] = b.v[0][3] = b.v[1][0] = b.v[2][1] = b.v[3][2] = 1;
    while (scanf("%d%d", &n, &m) != EOF) {
        if (n <= 4) {
            if (n == 0)
                printf("0\n");
            else printf("%d\n", a.v[4-n][0]%m);
        }
        else {
            c = powMul(b, n-4);
            c = Mul(c, a);
            printf("%d\n", c.v[0][0]%m);
        }
    }
    return 0;
}