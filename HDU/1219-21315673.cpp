#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100000];
    int i,len;
    while(gets(s)!=NULL)
    {
       int a[27]={0};//放在循环里面，起到清零的作用
       len=strlen(s);
       for(i=0;i<len;i++)
       {
           if(s[i]>='a'&&s[i]<='z')
           {
               a[s[i]-96]++;
           }
       }
       for(i=1;i<=26;i++)
       {
           printf("%c:%d\n",i+96,a[i]);
       }
       printf("\n");
    }
    return 0;
}