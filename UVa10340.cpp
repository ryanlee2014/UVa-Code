#include<stdio.h>
#define M 100000
int main(){
	char s[M],a[M];
	int i,j;
	while(scanf("%s%s",s,a)!=EOF){
		for(i=0,j=0;a[i]!='\0'&&s[j]!='\0';i++)
			if(s[j]==a[i]) j++;
		if(s[j]=='\0') printf("Yes\n");
		else printf("No\n");
	}
}