#include<iostream>
#include <stdio.h>
#include<string.h>
using namespace std;

#define MAX 1010
int add1[MAX], add2[MAX], res[MAX];
char tmp1[MAX], tmp2[MAX];
int main()
{
    int N, i, j, len, len1, len2, tmp, k;
    scanf("%d",&N);
    getchar();
    for(j=0;j<N;j++)
    {
        memset(add1,0,sizeof(add1));
        memset(add2,0,sizeof(add2));
        memset(res,0,sizeof(res));
        memset(tmp1,0,sizeof(tmp1));
        memset(tmp2,0,sizeof(tmp2));
        scanf("%s %s",tmp1,tmp2);
        len1 = strlen(tmp1);
        len2 = strlen(tmp2);
        for(i=len1-1,k=0;i>=0;i--)
            add1[k++] = tmp1[i] - '0';

        for(i=len2-1,k=0;i>=0;i--)
            add2[k++] = tmp2[i] - '0';
        tmp = 0;
        if(len1 >= len2)
        {
            for(i=0;i<=len1;i++)
            {
                res[i] = (add1[i] + add2[i] +tmp)%10;
                tmp = (add1[i] + add2[i] +tmp)/10;
            }
        }
        else if(len1 < len2)
        {
            for(i=0;i<=len2;i++)
            {
                res[i] = (add1[i] + add2[i] +tmp)%10;
                tmp = (add1[i] + add2[i] +tmp)/10;
            }
        }
        if(len1 >= len2) len = len1;
        else len = len2;
        printf("Case %d:\n%s + %s = ",j+1, tmp1 , tmp2);
        if(res[len]!=0) printf("%d",res[len]);
        for(i=len-1;i>=0;i--)
            printf("%d",res[i]);

        printf("\n");
        if(j!=N-1) printf("\n");
    }
    return 0;
}