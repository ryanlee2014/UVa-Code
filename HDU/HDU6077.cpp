#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define pf printf
typedef long long ll;
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 50100;
char number[10][10][10];

void init()
{
    strcpy(number[0][0],".XX.");
    strcpy(number[0][1],"X..X");
    strcpy(number[0][2],"X..X");
    strcpy(number[0][3],"....");
    strcpy(number[0][4],"X..X");
    strcpy(number[0][5],"X..X");
    strcpy(number[0][6],".XX.");
    strcpy(number[1][0],"....");
    strcpy(number[1][1],"...X");
    strcpy(number[1][2],"...X");
    strcpy(number[1][3],"....");
    strcpy(number[1][4],"...X");
    strcpy(number[1][5],"...X");
    strcpy(number[1][6],"....");
    strcpy(number[2][0],".XX.");
    strcpy(number[2][1],"...X");
    strcpy(number[2][2],"...X");
    strcpy(number[2][3],".XX.");
    strcpy(number[2][4],"X...");
    strcpy(number[2][5],"X...");
    strcpy(number[2][6],".XX.");
    strcpy(number[3][0],".XX.");
    strcpy(number[3][1],"...X");
    strcpy(number[3][2],"...X");
    strcpy(number[3][3],".XX.");
    strcpy(number[3][4],"...X");
    strcpy(number[3][5],"...X");
    strcpy(number[3][6],".XX.");
    strcpy(number[4][0],"....");
    strcpy(number[4][1],"X..X");
    strcpy(number[4][2],"X..X");
    strcpy(number[4][3],".XX.");
    strcpy(number[4][4],"...X");
    strcpy(number[4][5],"...X");
    strcpy(number[4][6],"....");
    strcpy(number[5][0],".XX.");
    strcpy(number[5][1],"X...");
    strcpy(number[5][2],"X...");
    strcpy(number[5][3],".XX.");
    strcpy(number[5][4],"...X");
    strcpy(number[5][5],"...X");
    strcpy(number[5][6],".XX.");
    strcpy(number[6][0],".XX.");
    strcpy(number[6][1],"X...");
    strcpy(number[6][2],"X...");
    strcpy(number[6][3],".XX.");
    strcpy(number[6][4],"X..X");
    strcpy(number[6][5],"X..X");
    strcpy(number[6][6],".XX.");
    strcpy(number[7][0],".XX.");
    strcpy(number[7][1],"...X");
    strcpy(number[7][2],"...X");
    strcpy(number[7][3],"....");
    strcpy(number[7][4],"...X");
    strcpy(number[7][5],"...X");
    strcpy(number[7][6],"....");
    strcpy(number[8][0],".XX.");
    strcpy(number[8][1],"X..X");
    strcpy(number[8][2],"X..X");
    strcpy(number[8][3],".XX.");
    strcpy(number[8][4],"X..X");
    strcpy(number[8][5],"X..X");
    strcpy(number[8][6],".XX.");
    strcpy(number[9][0],".XX.");
    strcpy(number[9][1],"X..X");
    strcpy(number[9][2],"X..X");
    strcpy(number[9][3],".XX.");
    strcpy(number[9][4],"...X");
    strcpy(number[9][5],"...X");
    strcpy(number[9][6],".XX.");
}
char str[30][50];
int main(void)
{
    int T;
    in(T);
    init();
    while(T--)
    {
        rep(i,0,7)
            ins(str[i]);
        char a,b,c,d;
        bool fa=true,fb=true,fc=true,fd=true;
        rep(i,0,10)
        {
            fa=true;
            rep(j,0,7)
            {
                rep(k,0,4)
                {
                    if(str[j][k]!=number[i][j][k])fa=false;
                }
            }
            if(fa)
            {
                a='0'+i;
                break;
            }
        }
        rep(i,0,10)
        {
            fb=true;
            rep(j,0,7)
            {
                rep(k,0,4)
                {
                    if(str[j][k+5]!=number[i][j][k])fb=false;
                }
            }
            if(fb)
            {
                b='0'+i;
                break;
            }
        }
        rep(i,0,10)
        {
            fc=true;
            rep(j,0,7)
            {
                rep(k,0,4)
                {
                    if(str[j][k+12]!=number[i][j][k])fc=false;
                }
            }
            if(fc)
            {
                c='0'+i;
                break;
            }
        }
        rep(i,0,10)
        {
            fd=true;
            rep(j,0,7)
            {
                rep(k,0,4)
                {
                    if(str[j][k+17]!=number[i][j][k])fd=false;
                }
            }
            if(fd)
            {
                d='0'+i;
                break;
            }
        }
        printf("%c%c:%c%c\n",a,b,c,d);
    }
    return 0;
}