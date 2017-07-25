#include <iostream>
#include <cstring>
using namespace std;
int strint(int n)
{
	int cnt=0;
	while(n)
	{
		n/=10;
		cnt++;
	}
	return cnt;
}
void test()
{
	cout<<'\n';
}
int main(void)
{
	long long int a[10000];
	char arr[10000];
	int c[10000];
	int l[99];
	memset(c, 0, sizeof(c));
	memset(a, 0, sizeof(a));
	memset(l, 0, sizeof(l));
	long long b;
	int front=0;
	cin >> arr >> b;
	if(b)
	{
		int d = 0;
		for (int i = 0; i < strlen(arr); i++)
		{
			a[strlen(arr) - i - 1] = arr[i] - '0';
		}
		for (int i = strlen(arr) - 1; i >= 0; i--)
		{
			d = d * 10 + a[i];
			c[i] = d / b;
			d %= b;
			front++;
		}
		int p = strlen(arr);
		while (c[p - 1] == 0 && p > 1) p--;
		for (int i = p - 1; i >= 0; i--) printf("%d", c[i]);
		int q = d;
		int yu=0;
		if (q)
		{
			cout << ".";
			yu = q;
			for (int i = 0; i < 99; i++)
			{
				yu *= 10;
				l[i] = yu / b;
				yu %= b;
				if(front+i+1==100)break;
			}
			int zer = 99;
			while (l[zer - 1] == 0 && zer > 1)zer--;
			for (int i = 0; i < zer; i++) printf("%d", l[i]);
		}
		cout << "," << yu;
	}
	else
	{
		cout<<"Divisor is 0";
	}
	cout << endl;
	return 0;
}