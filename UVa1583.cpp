#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int arr[100005];
	memset(arr,0, sizeof(arr));
	for (int i = 1; i < 100005; i++)
	{
		int a,b;
		a=b=i;
		while(a>0)
		{
			b+=a%10;
			a/=10;
		}
		if(arr[b]==0||i<arr[b])
		{
			arr[b]=i;
		}
	}
	int p;
	cin>>p;
	while(p--)
	{
		int num=0;
		cin>>num;
		printf("%d\n",arr[num]);
	}
	return 0;
}