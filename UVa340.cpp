#include <cstdio>
#include <cstring>
int main()
{
	int a;
	int td=1;
	while(scanf("%d",&a),a!=0)
	{
		bool first=true;
		int ans[10000];
		memset(ans,0,(size_t)a);
		for (int i = 0; i < a; i++)
		{
			scanf("%d",&ans[i]);
		}
		int res[10000];
		memset(res,0, (size_t)a);
		while(1)
		{
			int t[10000],alive[10000];
			memset(t,0,(size_t)a);
			memset(alive,0,(size_t)a);
			int countr=0;
			for (int i = 0; i < a; i++)
			{
				scanf("%d",&res[i]);
				if(ans[i]==res[i])
					countr++;
			}
			bool zero=true;
			for (int j = 0; j < a; j++)
			{
				if(res[j]!=0)
					zero=false;
			}
			if(zero)
				break;
			for (int i = 0; i < a; i++)
			{
				t[ans[i]]++;
			}
			int countwr=0;
			for (int i = 1; i <=9 ; i++)
			{
				int c1=0,c2=0;
				for (int j = 0; j < a; j++)
				{
					if(ans[j]==i)c1++;
					if(res[j]==i)c2++;
				}
				if(c1<c2)countwr+=c1;else countwr+=c2;
			}
			if(first)
			{
				printf("Game %d:\n", td);
				first=false;
			}
			printf("    (%d,%d)\n",countr,countwr-countr);
		}
		td++;
	}
	return 0;
}