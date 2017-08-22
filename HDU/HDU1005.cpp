#include <stdio.h>
#define in(x) scanf("%d",&x)
int arr[50];int main(void){int a,b,n;arr[1]=arr[2]=1;while(~in(a)&&~in(b)&&~in(n)&&a&&b&&n){for(int i=3;i<=n%49;i++)arr[i]=(a*arr[i-1]+b*arr[i-2])%7;printf("%d\n",arr[n%49]); }return 0; }
