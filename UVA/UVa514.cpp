#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;
int main()
{
	stack<int>train;
	int temp[1010];
	memset(temp,'0', sizeof(temp[0]));
	int length;
	int A,B;
	bool ok=true;
	while(scanf("%d",&length),length!=0)
	{
		A=1,B=1;
		while(scanf("%d",&temp[1]),temp[1]!=0)
		{
			for (int i = 2; i <= length; i++)
			{
				scanf("%d", &temp[i]);
			}
			while(B<=length)
			{
				if(A==temp[B])
				{
					A++;
					B++;
				}
				else if(!train.empty()&&train.top()==temp[B])
				{
					train.pop();
					B++;
				}
				else if(A<=length)
				{
					train.push(A++);
				}
				else
				{
					ok=false;
					break;
				}
			}
			printf("%s\n",ok?"Yes":"No");
			ok=true;
			A=1,B=1;
			while(!train.empty())
			{
				train.pop();
			}
		}
		while (getchar()!='\n');
		printf("\n");
	}
	return 0;
}