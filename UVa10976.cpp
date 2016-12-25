#include <cstdio>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <bitset>
#include <deque>
#include <stack>
#include <climits>
#include <string>
#include <queue>
#include <memory.h>
#include <unordered_map>
#include <random>
#include <fstream>
using namespace std;
int main(void)
{
	ios::sync_with_stdio(false);
	int k;
	while(cin>>k)
	{
		int cnt=0;
		long long xp[1000],yp[1000];
		for (int y = k+1; y <=2*k;y++ )
		{
			long long x;
			x=k*y/(y-k);
			if(k*y%(y-k)==0)
			{
				xp[cnt]=x,yp[cnt]=y;
				cnt++;
			}
		}
		cout<<cnt<<endl;
		for (int i = 0; i < cnt; i++)
		{
			cout<<"1/"<<k<<" = 1/"<<xp[i]<<" + 1/"<<yp[i]<<endl;
		}
	}
	return 0;
}