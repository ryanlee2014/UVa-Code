#include <cstdio>
#include <iostream>
#include <cstring>
#define in(x) scanf("%d",&x)
#define ins(x) scanf("%s",&x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define c() getchar()
#define out(x) printf("%d\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
using namespace std;
const int maxn=1005;
char inp[maxn],ans[maxn],tmp[maxn];
int nt;
const char keyboard[10][5]={{"\0"},{"\0"},{"abc"},{"def"},{"ghi"},{"jkl"},{"mno"},{"pqrs"},{"tuv"},{"wxyz"}};
struct trie
{
	int cnt;
	trie* next[26];
	trie():cnt(0){ms(next);}
	~trie(){
		rep(i,0,26)
		{
			if(next[i])delete next[i];
		}
	}
};

void insert(trie* root,char* str,int cnt)
{
	int len=strlen(str);
	trie* p=root;
	rep(i,0,len)
	{
		if(p->next[str[i]-'a']==NULL)
		{
			p->next[str[i]-'a']=new trie;
		}
		p->next[str[i]-'a']->cnt+=cnt;
		p=p->next[str[i]-'a'];
	}
}

void search(trie* root,int len,int idx)
{
	trie* p=root;
	if(len==idx)
	{
		if(p->cnt>nt)
		{
			strcpy(ans,tmp);
			nt=p->cnt;
		}
		return;
	}
	int l=strlen(keyboard[inp[idx]-'0']);
	rep(i,0,l)
	{
		char t=keyboard[inp[idx]-'0'][i];
		if(p->next[t-'a']==NULL)continue;
		tmp[idx]=t;
		tmp[idx+1]=0;
		search(p->next[t-'a'],len,idx+1);
	}
}

int main(void)
{
	int T,n,kase=0;
	trie* root=NULL;
	char str[1005];
	in(T);
	while(T--)
	{
		in(n);
		printf("Scenario #%d:\n",++kase);
		root=new trie;
		rep(i,0,n)
		{
			ins(str),in(nt);
			insert(root,str,nt);
		}
		in(n);
		rep(i,0,n)
		{
			ins(inp);
			int len=strlen(inp)-1;
			rep(j,0,len)
			{
				nt=0;
				search(root,j+1,0);
				!nt?puts("MANUALLY"):printf("%s\n",ans);
			}
			puts("");
		}
		delete root;
		puts("");
	}
	return 0;
}