#include <cstdio>
using namespace std;

const int MAXN = 30001;
int root[MAXN];
int rank[MAXN];
int num[MAXN];

void make_set(int x)
{/*创建一个单元集*/
	root[x] = x;
	rank[x] = 0;
	num[x] = 1;
}

int find(int x)
{
	/*int r = x, temp;

	while(root[r] != r) r = root[r];
	while(x != r)
	{
		temp = root[x];
		root[x] = r;
		x = temp;
		}
	return x;*/
	if(x != root[x])
	 root[x] = find(root[x]);
	return root[x];
}

void union_set(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y)return ;
	if(rank[x] > rank[y])
	{
		root[y] = x;
		num[x] += num[y];
		}
	else
	{
		root[x] = y;
		if(rank[x] == rank[y])
		rank[y]++;
		num[y] += num[x];
		}
}

int main()
{
	int n, m, x, y, i, t, j;
	while(~scanf("%d%d", &n, &m)&&(m||n))
	{
		if(m == 0)
		{
			puts("1");
			continue;
		}
		for(i = 0; i < n; i++)
		make_set(i);
		for(i = 0; i < m; i++)
		{
			scanf("%d", &t);
			scanf("%d", &x);
			for(j = 1; j < t; j++){
				scanf("%d", &y);
				union_set(x, y);
				x = y;
				}
			}
		x = find(0);
		printf("%d\n",num[x]);
		}
	return 0;
}