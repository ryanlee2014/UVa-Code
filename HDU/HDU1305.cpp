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
    bool isprefix;
    trie* next[2];
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
            t->next[*cur-'0']->isprefix=false;
            memset(t->next[*cur-'0']->next,0, sizeof(t->next[*cur-'0']->next));
        }
        if(t->next[*cur-'0']->isprefix)
        {
            f=true;
        }
        t=t->next[*cur-'0'];
        cur++;
    }
    t->isprefix=true;
    for (int i = 0; i < 2; ++i)
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
    for (int i = 0; i < 2; ++i)
    {
        if(root->next[i])
        {
            del(root->next[i]);
        }
    }
    free(root);
}
char str[100005];
int main(void)
{
    int k=0;
    f=false;
    trie* root=(trie*)malloc(sizeof(trie));
    root->isprefix=false;
    ms(root->next);
    while(~scanf("%s",str))
    {
        if(str[0]=='9')
        {
            if(!f)
            {
                printf("Set %d is immediately decodable\n",++k);
            }
            else
                printf("Set %d is not immediately decodable\n",++k);
            del(root);
            f=false;
            root=(trie*)malloc(sizeof(trie));
            ms(str);
            ms(root->next);
            root->isprefix=false;
            continue;
        }
        else
        {
            if(!f)
                insert(root,str);
        }
    }
    return 0;
}
