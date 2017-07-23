#include <stdio.h>
#include <string.h>
#include <ctype.h>
char string[100];
int main()
{
	int a;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%s", string);
		double che = 0;
		double ac = 0;
		int sum = 0;
		for (int j = 0; j < strlen(string); j++)
		{
			if (isalpha(string[j]))
			{
				char t;
				t = string[j];
				switch (t)
				{
					case 'C':
						che = 12.01;break;
					case 'H':
						che = 1.008;break;
					case 'O':
						che = 16.00;break;
					case 'N':
						che = 14.01;break;
				}
				sum=0;
			}
			while (isdigit(string[j]))
			{
				sum = sum * 10 + string[j] - '0';
				if (!isdigit(string[j + 1]))
				{
					break;
				}
				else
					j++;
			}
			if (sum!=0)
				ac += sum * che;
			else if (isalpha(string[j+1]) || j == strlen(string) - 1)
				ac += che;
		}
		printf("%.3f\n", ac);
	}
	return 0;
}