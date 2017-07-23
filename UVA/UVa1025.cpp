#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M = 210;
const int N = 60;
const int INF = 0x3f3f3f3f;
int n, T, M1, M2, t[N], d[N], e[N];
int dp[M][N], cas = 1;
bool has_train[M][N][2];

void init() {
	scanf("%d", &T);//接收车站时间间隔
	for(int i = 1; i <= n - 1; i++)
		scanf("%d", &t[i]);

	scanf("%d", &M1);//接收火车从左往右的数量
	for(int i = 1; i <= M1; i++)
		scanf("%d", &d[i]);//时刻

	scanf("%d", &M2);//从右往左
	for(int i = 1; i <= M2; i++)
		scanf("%d", &e[i]);//时刻

	memset(has_train, 0, sizeof(has_train));//初始化
	for(int i = 1;  i <= M1; i++) {
		int tmp = d[i];
		has_train[tmp][1][0] = true;//在第一个车站初始发车情况为true
		for(int j = 1; j <= n - 1; j++) {
			tmp += t[j];
			if(tmp > T)
				break;
			has_train[tmp][j+1][0] = true;//停靠时间为true
		}
	}

	for(int i = 1; i <= M2; i++) {
		int tmp = e[i];
		has_train[tmp][n][1] = true;//和上部分同理
		for(int j = n - 1; j >= 1; j--) {
			tmp += t[j];
			if(tmp > T)
				break;
			has_train[tmp][j][1] = true;
		}
	}
}

void solve() {

	for(int i = 1; i <= n - 1; i++)
		dp[T][i] = INF;
	dp[T][n] = 0;

	for(int i = T - 1; i >= 0; i--) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i+1][j] + 1;//等一分钟
			if(j < n && has_train[i][j][0] && i + t[j] <= T)//有火车，不在终点站，剩余时间加上火车的路程小于总时间
				dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]);//到下一站和原地不动哪一个时间更短
			if(j > 1 && has_train[i][j][1] && i + t[j-1] <= T)//不在第一站，有火车，剩余时间加上火车路程小于总时间
				dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]);//到上一站和原地不动哪一个时间更短
		}
	}

	printf("Case Number %d: ", cas++);
	if(dp[0][1] >= INF)//如果没有结果
		printf("impossible\n");
	else
		printf("%d\n", dp[0][1]);
}

int main() {
	while(scanf("%d", &n) != EOF && n) {//接收车站数量
		init();
		solve();
	}
	return 0;
}