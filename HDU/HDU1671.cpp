#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define in(x) scanf("%d",&x)
#define out(x) printf("%d\n",x)
#define ms(x) memset(x,0,sizeof(x))
using namespace std;
struct trie{
	bool isphone;
	trie* next[26];
};
bool f=false;
void insert(trie* root,char* cur)
{
	trie* t=root;
	while(*cur!='\0')
	{
		if(t->next[*cur-'0']==NULL)
		{
			t->next[*cur-'0']=(trie*)malloc(sizeof(trie));
			t->next[*cur-'0']->isphone=false;
			memset(t->next[*cur-'0']->next,0, sizeof(t->next[*cur-'0']->next));
		}
		if(t->next[*cur-'0']->isphone)
		{
			f=true;
		}
		t=t->next[*cur-'0'];
		cur++;
	}
	t->isphone=true;
	for (int i = 0; i < 26; ++i)
	{
		if(t->next[i])
		{
			f=true;
			break;
		}
	}
}
void del(trie* root)
{
	for (int i = 0; i < 26; ++i)
	{
		if(root->next[i])
		{
			del(root->next[i]);
		}
	}
	free(root);
}

int main(void)
{
	int t;
	in(t);
	while(t--)
	{
		f=false;
		trie* root=(trie*)malloc(sizeof(trie));
		memset(root->next,0, sizeof(root->next));
		root->isphone=false;
		char str[20];
		int n;
		in(n);
		for (int i = 0; i < n; ++i)
		{
			scanf("%s",str);
			if(!f)
				insert(root,str);
		}
		puts(f?"NO":"YES");
		del(root);
	}
	return 0;
}