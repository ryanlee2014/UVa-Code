#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>

struct trie
{
    bool isword;
    trie* next[26];
    trie():isword(false)
    {
        for (int i = 0; i < 26; ++i)
        {
            next[i]=NULL;
        }
    }
};

trie root;
void insert(char* word)
{
    trie* cur=&root;
    for (int i = 0; word[i] ; ++i)
    {
        if(!cur->next[word[i]-'a'])
            cur->next[word[i]-'a']=new trie;
        cur=cur->next[word[i]-'a'];
    }
    cur->isword=true;
}

bool word(char* w)
{
    trie* cur=&root;
    for (int i = 0; w[i]; ++i)
    {
        if(!cur->next[w[i]-'a'])return false;
        cur=cur->next[w[i]-'a'];
    }
    return cur->isword;
}

char w[50100][110];
char temp[110];
int main(void)
{
    int size=1;
    while(~scanf("%s",w[size]))
    {
        insert(w[size++]);
    }
    for (int i = 1; i < size; ++i)
    {
        int len=strlen(w[i]);
        for (int j = 1; j < len; ++j)
        {
            char* arr=w[i];
            strncpy(temp,w[i],j);
            temp[j]=0;
            arr+=j;
            if(word(arr)&&word(temp))
            {
                puts(w[i]);
                break;
            }
        }
    }
    return 0;
}