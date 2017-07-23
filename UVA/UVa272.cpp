#include <cstdio>
int main()
{
	bool left=true;
	int c;
	while((c=getchar())!=EOF)
	{
		if(c=='"')
		{
			printf("%s",left?"``":"''");
			left=!left;
		}
		else
		{
			printf("%c",c);
		}
	}
	return 0;
}