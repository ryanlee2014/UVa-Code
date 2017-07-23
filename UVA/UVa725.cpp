#include<cstdio>
#include<cstring>
int a[10];
int Judge(int m,int n)
{
	int sum;
	if(n>98765)//简化
		return 0;
	memset(a,0,sizeof(a));
	if(m<10000)
		a[0]=1;
	while(m)
	{
		a[m%10]=1;
		m/=10;
	}
	while(n)
	{
		a[n%10]=1;
		n/=10;
	}
	sum=0;
	for(int i=0;i<10;i++)
		sum+=a[i];
	if(sum==10)
		return 1;
	return 0;
}
int main()
{
	int i,n,t=0,counter;
	while(~scanf("%d",&n)&&n)
	{
		if(t++)
			printf("\n");//用来控制分行
		counter=0;
		for(i=1234;i<99999;++i)
		{
			if(Judge(i,i*n))
			{
				printf("%05d / %05d = %d\n",i*n,i,n);
				counter++;
			}
		}
		if(!counter)
			printf("There are no solutions for %d.\n",n);
	}
}