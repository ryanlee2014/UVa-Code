#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int arr[10000];
	int kase=1;
	int d;
	memset(arr,0, sizeof(arr));
	int length=0,search=0;
	int target;
	while (scanf("%d%d",&length,&search)==2&&length)
	{
		for (int i = 0; i < length; i++)
		{
			scanf("%d",&arr[i]);
		}
		qsort(arr,length, sizeof(arr[0]),cmp);
		printf("CASE# %d:\n", kase++);
		for (int p = 0; p < search; p++)
		{
			scanf("%d", &target);
			int flag = 0;
			for (int i = 0; i < length; i++)
			{
				if (arr[i] == target)
				{
					flag = 1;
					d = i + 1;
					break;
				}
			}
			if (!flag)
				printf("%d not found\n",target);
			else
			{
				printf("%d found at %d\n", target, d);
			}
		}
	}
	return 0;
}