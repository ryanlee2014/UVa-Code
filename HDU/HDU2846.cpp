#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
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
struct trie
{
    int num;
    int id;
    trie* next[26];
};

void insert(trie* root,char* str,int id)
{
    trie* p=root;
    for (char* i = str; *i ; ++i)
    {
        if(p->next[*i-'a']==NULL)
        {
            trie* t=(p->next[*i-'a']=(trie*)malloc(sizeof(trie)));
            t->num=0;
            t->id=-1;
            ms(t->next);
        }
        p=p->next[*i-'a'];
        if(p->id!=id)
        {
            p->id=id;
            p->num++;
        }
    }
}

int res(trie* root,char* str)
{
    trie* p=root;
    for (int i = 0; str[i] ; ++i)
    {
        if(p->next[str[i]-'a']==NULL)return 0;
        p=p->next[str[i]-'a'];
    }
    return p->num;
}

void del(trie* root)
{
    rep(i,0,26)
    {
        if(root->next[i])del(root->next[i]);
    }
    free(root);
}

int main(void)
{
    char str[30];
    int n,m;
    while(~in(n))
    {
        trie* root=(trie*)malloc(sizeof(trie));
        root->num=0;
        root->id=-1;
        ms(root->next);
        rep(i,0,n)
        {
            ins(str);
            int len=strlen(str);
            rep(j,0,len)insert(root,str+j,i);
        }
        in(m);
        rep(i,0,m)ins(str),out(res(root,str));
        del(root);
    }
    return 0;
}
