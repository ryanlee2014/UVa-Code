#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int main()
{
	char str[5][5];
	memset(str, ' ', sizeof(str));
	int count=0;
	int x=-1,y=-1;
	int flag=0;
	while(1)
	{
		for (int i = 0; i < 5; i++)
		{
			gets(str[i]);
			if(str[0][0]=='Z')
				exit(0);
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if(!isalpha(str[i][j])||str[i][j]==' ')
				{
					x=i,y=j;
				}
			}
		}
		char c;
		while((c=(char)getchar())!='0')
		{
			if(c=='A')
			{
				if(x==0)
				{
					flag=1;
					break;
				}
				else
				{
					str[x][y]=str[x-1][y];
					str[x-1][y]=' ';
					x-=1;
				}
			}
			else if(c=='B')
			{
				if(x==4)
				{
					flag=1;
					break;
				}
				else
				{
					str[x][y]=str[x+1][y];
					str[x+1][y]=' ';
					x+=1;
				}
			}
			else if(c=='L')
			{
				if(y==0)
				{
					flag=1;
					break;
				}
				else
				{
					str[x][y]=str[x][y-1];
					str[x][y-1]=' ';
					y-=1;
				}
			}
			else if(c=='R')
			{
				if(y==4)
				{
					flag=1;
					break;
				}
				else
				{
					str[x][y]=str[x][y+1];
					str[x][y+1]=' ';
					y+=1;
				}
			}
		}
		if (count++) printf("\n");
		if(!flag)
		{
			printf("Puzzle #%d:\n",count);
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					if (j == 0)
						printf("%c", str[i][j]);
					else
						printf(" %c", str[i][j]);
				}
				printf("\n");
			}
			getchar();
		}
		else
		{
			while (getchar()!='0');
			getchar();
			printf("Puzzle #%d:\n",count);
			printf("This puzzle has no final configuration.\n");
		}
		flag=0;
	}
}