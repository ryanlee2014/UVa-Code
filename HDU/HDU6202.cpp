#include <bits/stdc++.h>

#define ms(x, y) memset(x, y, sizeof(x))

using namespace std;

int color[73];
inline void R()
{
    static const int pos[27] = {9, 14, 15, 16, 17, 18, 23, 63, 62, 58, 57, 55, 64, 37, 39, 38, 42, 41, 54, 49, 53, 52, 46, 48, 47, 51, 50};
    static const int aim[27] = {23, 63, 62, 58, 57, 55, 64, 37, 39, 38, 42, 41, 9, 14, 15, 16, 17, 18, 50, 52, 51, 47, 54, 53, 49, 48, 46};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void L()
{
    static const int pos[27] = {5, 45, 44, 40, 39, 37, 46, 55, 57, 56, 60, 59, 27, 32, 33, 34, 35, 36, 68, 70, 69, 65, 72, 71, 67, 66, 64};
    static const int aim[27] = {46, 55, 57, 56, 60, 59, 27, 32, 33, 34, 35, 36, 5, 45, 44, 40, 39, 37, 64, 65, 66, 67, 68, 69, 70, 71, 72};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void U()
{
    static const int pos[27] = {19, 10, 12, 11, 15, 14, 54, 41, 42, 43, 44, 45, 68, 36, 35, 31, 30, 28, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    static const int aim[27] = {54, 41, 42, 43, 44, 45, 68, 36, 35, 31, 30, 28, 19, 10, 12, 11, 15, 14, 9, 4, 8, 7, 1, 3, 2, 6, 5};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void F()
{
    static const int pos[27] = {14,54,53,49,48,46,55,64,66,65,69,68,36,5,6,7,8,9,41,43,42,38,45,44,40,39,37};
    static const int aim[27] = {55,64,66,65,69,68,36,5,6,7,8,9,14,54,53,49,48,46,37,38,39,40,41,42,43,44,45};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void RR()
{
    static const int pos[27] = {10, 19, 21, 22, 26, 27, 59, 72, 71, 70, 69, 68, 45, 5, 6, 2, 3, 1, 28, 29, 30, 31, 32, 33, 34, 35, 36};
    static const int aim[27] = {59, 72, 71, 70, 69, 68, 45, 5, 6, 2, 3, 1, 10, 19, 21, 22, 26, 27, 32, 34, 33, 29, 36, 35, 31, 30, 28};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void LL()
{
    static const int pos[27] = {28, 19, 21, 20, 24, 23, 63, 50, 51, 52, 53, 54, 41, 9, 8, 4, 3, 1, 10, 11, 12, 13, 14, 15, 16, 17, 18};
    static const int aim[27] = {63, 50, 51, 52, 53, 54, 41, 9, 8, 4, 3, 1, 28, 19, 21, 20, 24, 23, 18, 13, 17, 16, 10, 12, 11, 15, 14};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void UU()
{
    static const int pos[27] = {37, 46, 48, 47, 51, 50, 18, 23, 24, 25, 26, 27, 32, 72, 71, 67, 66, 64, 55, 56, 57, 58, 59, 60, 61, 62, 63};
    static const int aim[27] = {18, 23, 24, 25, 26, 27, 32, 72, 71, 67, 66, 64, 37, 46, 48, 47, 51, 50, 63, 58, 62, 61, 55, 57, 56, 60, 59};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void FF()
{
    static const int pos[27] = {1, 28, 30, 29, 33, 32, 72, 59, 60, 61, 62, 63, 50, 18, 17, 13, 12, 10, 19, 20, 21, 22, 23, 24, 25, 26, 27};
    static const int aim[27] = {72, 59, 60, 61, 62, 63, 50, 18, 17, 13, 12, 10, 1, 28, 30, 29, 33, 32, 27, 22, 26, 25, 19, 21, 20, 24, 23};
    static int tmp[27];
    for (int i = 0; i < 27; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 27; ++i) color[aim[i]] = tmp[i];
}
inline void ML()
{
    static const int pos[18] = {2, 6, 7, 43, 42, 38, 49, 48, 47, 58, 62, 61, 25, 26, 22, 29, 30, 31};
    static const int aim[18] = {49, 48, 47, 58, 62, 61, 25, 26, 22, 29, 30, 31, 2, 6, 7, 43, 42, 38};
    static int tmp[18];
    for (int i = 0; i < 18; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 18; ++i) color[aim[i]] = tmp[i];
}
inline void MR()
{
    static const int pos[18] = {7, 8, 4, 11, 12, 13, 20, 24, 25, 61, 60, 56, 67, 66, 65, 40, 44, 43};
    static const int aim[18] = {20, 24, 25, 61, 60, 56, 67, 66, 65, 40, 44, 43, 7, 8, 4, 11, 12, 13};
    static int tmp[18];
    for (int i = 0; i < 18; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 18; ++i) color[aim[i]] = tmp[i];
}
inline void MU()
{
    static const int pos[18] = {40, 39, 38, 49, 53, 52, 16, 17, 13, 20, 21, 22, 29, 33, 34, 70, 69, 65};
    static const int aim[18] = {16, 17, 13, 20, 21, 22, 29, 33, 34, 70, 69, 65, 40, 39, 38, 49, 53, 52};
    static int tmp[18];
    for (int i = 0; i < 18; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 18; ++i) color[aim[i]] = tmp[i];
}
inline void MF()
{
    static const int pos[18] = {56, 57, 58, 47, 51, 52, 16, 15, 11, 4, 3, 2, 31, 35, 34, 70, 71, 67};
    static const int aim[18] = {16, 15, 11, 4, 3, 2, 31, 35, 34, 70, 71, 67, 56, 57, 58, 47, 51, 52};
    static int tmp[18];
    for (int i = 0; i < 18; ++i) tmp[i] = color[pos[i]];
    for (int i = 0; i < 18; ++i) color[aim[i]] = tmp[i];
}
inline void R_() {R(); R();}
inline void L_() {L(); L();}
inline void U_() {U(); U();}
inline void F_() {F(); F(); }
inline void RR_() {RR(); RR(); }
inline void LL_() {LL(); LL(); }
inline void UU_() {UU(); UU(); }
inline void FF_() {FF(); FF(); }
inline void ML_() {ML(); ML(); }
inline void MR_() {MR(); MR(); }
inline void MU_() {MU(); MU(); }
inline void MF_() {MF(); MF(); }
void (*fptrs[24])() = {R, L, U, F, RR, LL, UU, FF, MR, ML, MU, MF, R_, L_, U_, F_, RR_, LL_, UU_, FF_, MR_, ML_, MU_, MF_};
bool check()
{
    for (int i = 0; i < 8; ++i)
        for (int j = 2; j <= 9; ++j)
            if (color[i * 9 + 1] != color[i * 9 + j])
                return false;
    return true;
}
bool dfs(int depth)
{
    if (depth == 3) return check();
    if (check()) return true;
    // printf("debug\n");
    for (int i = 0; i < 24; ++i)
    {
        fptrs[i]();
        if (dfs(depth + 1)) return true;
        fptrs[(i + 12) % 24]();
    }
    return false;
}
int main(int argc, char const *argv[])
{
    // freopen("out.txt", "w", stdout);
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        for (int i = 1; i <= 72; ++i) scanf("%d", &color[i]);
        printf("%s\n", dfs(0) ? "YES" : "NO");
    }
    return 0;
}
