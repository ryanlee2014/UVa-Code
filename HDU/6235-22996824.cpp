#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
    int n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int num1=1,num2=(n+1)/2+1,i=1;
        while(i<=n)
        {
            if(i%2==1)
            {
                if(i==1)
                    printf("%d",num1++),i++;
                else
                    printf(" %d",num1++),i++;
            }
            if(i%2==0&&i<=n)
                printf(" %d",num2++),i++;
        }
        printf("\n");
    }
}