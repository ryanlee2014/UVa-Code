#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	char str[]="1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./\0";
	int c;
	while((c=getchar())!=EOF)
	{
		int i;
		for (i = 0; str[i]&&str[i]!=c; i++);
		if(str[i])
			putchar(str[i-1]);
		else
			putchar(c);
	}
	return 0;
}