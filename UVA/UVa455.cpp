#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int T;
    char str[100];
    cin>>T;
    while(getchar()!='\n');
    while(T--)
    {
        gets(str);
        for(unsigned int i=1;i<strlen(str);i++)
        {
          //  printf("str[%d+1]=%c,str[%d]=%c,str[2*%d+1]=%c\n",i,str[i+1],i,str[i],i,str[2*i+1]);
           if (strlen(str) % i == 0)
            {
                bool ok = true;
                for (unsigned j = i; j < strlen(str); j++)
                    if (str[j] != str[j % i])
                    {
                        ok = false;
                        break;
                    }
                if (ok)
                {
                    printf("%d\n", i);
                    if (T) putchar('\n');
                    break;
                }
            }
        }
    }
    return 0;
}