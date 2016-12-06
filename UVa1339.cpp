#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;
int cmp(const void *a, const void *b)
{
	return *(int *) a - *(int *) b;
}
int main()
{
	string s1;
	string s2;
	while (cin >> s1)
	{
		cin >> s2;
		int alp1[26], alp2[26];
		memset(alp1, 0, sizeof(alp1));
		memset(alp2, 0, sizeof(alp2));
		for (int i = 0; i < s1.length(); i++)
		{
			alp1[s1[i] - 'A']++;
		}
		for (int i = 0; i < s2.length(); i++)
		{
			alp2[s2[i] - 'A']++;
		}
		qsort(alp1, 26, sizeof(alp1[0]), cmp);
		qsort(alp2, 26, sizeof(alp2[0]), cmp);
		bool ok = true;
		for (int i = 0; i < 26; i++)
		{
			if (alp1[i] != alp2[i])
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			printf("YES\n");
		} else
		{
			printf("NO\n");
		}
		s1.erase();
		s2.erase();
	}
	return 0;
}