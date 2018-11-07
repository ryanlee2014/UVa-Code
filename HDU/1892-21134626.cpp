#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
int  bit[N][N];

int lowbit(int x){
    return x&(-x);
}

void add(int x,int y,int val){
    while(x < N){
        int tmp = y;
        while(tmp < N){
            bit[x][tmp] += val;
            tmp += lowbit(tmp);
        }
        x += lowbit(x);
    }
}

int sum(int x,int y){
    int ans = 0;
    while(x > 0){
        int tmp = y;
        while(tmp > 0){
            ans += bit[x][tmp];
            tmp -= lowbit(tmp);
        }
        x -= lowbit(x);
    }
    return ans;
}

int solve(int x,int y){
    return sum(x,y)-sum(x-1,y)-sum(x,y-1)+sum(x-1,y-1);
}

int main(){
    int T,t = 1;
    scanf("%d",&T);
    while(T--){
        printf("Case %d:\n",t++);
        int n;
        scanf("%d",&n);
        memset(bit,0,sizeof(bit));
        for(int i = 1; i < N; ++i)
            for(int j = 1; j < N; ++j)
                add(i,j,1);
        char op[5];
        int x1,y1,x2,y2,x;
        for(int i = 0; i < n; ++i){
            scanf("%s",op);
            if(op[0]=='A' || op[0]=='D'){
                scanf("%d%d%d",&x1,&y1,&x);
                if(op[0] == 'D')
                       x = -min(x,solve(x1+1,y1+1));
                add(x1+1,y1+1,x);
            }
            else if(op[0] == 'M'){
                scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&x);
                int  tmp = min(x,solve(x1+1,y1+1));
                add(x1+1,y1+1,-tmp);
                add(x2+1,y2+1,tmp);
            }
            else{
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                if(x1 > x2)
                    swap(x1,x2);
                if(y1 > y2)
                    swap(y1,y2);
                int tmp = sum(x2+1,y2+1)-sum(x1,y2+1)-sum(x2+1,y1)+sum(x1,y1);
                printf("%d\n",tmp);
            }
        }
    }
    return 0;
}