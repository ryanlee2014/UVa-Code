#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <climits>
#include <cstring>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <queue>
#include <list>
#include <stack>
#include <vector>
#include <cassert>
#include <ctime>

#define rep(i, a, n) for(int i=a ; i<n ; i++)
#define clr(a, b) memset(a,b,sizeof(a))
#define lson u<<1
#define rson u<<1|1

using namespace std;

const int maxn = 3000, INF = 0x3f3f3f3f;
int m, n,s,t, dist[maxn];
bool vis[maxn];

struct Node{
	int u,w;
	Node(){}
	Node(int u,int w):u(u),w(w){}
	bool operator < (const Node &tmp) const {
		return w > tmp.w;
	}
};

vector<Node> edge[maxn];

int dijkstra_heap() {
	clr(dist, 0x3f);
	clr(vis, 0);
	priority_queue<Node> que;
	dist[s] = 0;
	que.push(Node(s,0));
	while(!que.empty()) {
		Node now = que.top();
		que.pop();
		int u = now.u;
		if(vis[u]) continue;
		vis[u] = true;
		int len=edge[u].size();
		for(int i=0;i<len;++i) {
			Node& e=edge[u][i];
			if(dist[e.u] > dist[u] + e.w) {
				dist[e.u] = dist[u] + e.w;
				que.push(Node(e.u,dist[e.u]));
			}
		}
	}
	return dist[t];
}

int main() {
	while(~scanf("%d%d%d%d",&n,&m,&s,&t)) {
		for(int i=0 ; i<=n ; i++) {
			edge[i].clear();
		}
		for(int i=0, u, v, w ; i<m ; i++)
		{
			scanf("%d%d%d",&u, &v, &w);
			edge[u].push_back(Node(v,w));
			edge[v].push_back(Node(u,w));
		}
		printf("%d\n",dijkstra_heap());
	}
	return 0;
}