#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	char str[100005];
	int next[100005];
	int cur,last;
	while(cin>>str+1)
	{
		last=cur=0;
		int length=strlen(str+1);
		next[0]=0;
		for (int i = 0; i <= length; i++)
		{
			char ch=str[i];
			if(ch=='[')
			{
				cur=0;
			}
			else if(ch==']')
			{
				cur=last;
			}
			else
			{
				next[i]=next[cur];
				next[cur]=i;
				if(cur==last)
				{
					last=i;
				}
				cur=i;
			}
		}
		for (int i = next[0]; i !=0; i=next[i])
		{
			cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}