#include <iostream>
#include <stdio.h>
int main()
{
	char string[81];
	int a;
	int temp=0;
	int sum=0;
	scanf("%d",&a);
	for (int i = 0; i < a; i++)
	{
		scanf("%s",string);
		for (int j = 0; string[j]!='\0'; j++)
		{
			if(string[j]=='O')
			{
				temp++;
				sum+=temp;
			}
			else
			{
				temp=0;
			}
		}
		printf("%d\n",sum);
		sum=0;
		temp=0;
	}
	return 0;
}