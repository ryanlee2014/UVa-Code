#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;
struct Matrix{
	int a,b;
	Matrix(int a=0,int b=0):a(a),b(b){}
}m[26];
stack<Matrix>matrix;
int main()
{
	int n;
	cin>>n;
	for (int i = 0; i <n; i++)
	{
		string name;
		cin>>name;
		int a=name[0]-'A';
		cin>>m[a].a>>m[a].b;
	}
	string expr;
	while(cin>>expr)
	{
		int len = expr.length();
		bool error=false;
		int ans=0;
		for (int i = 0; i < len; i++)
		{
			if(isalpha(expr[i]))
			{
				matrix.push(m[expr[i]-'A']);
			}
			else if(expr[i]==')')
			{
				Matrix m2=matrix.top();
				matrix.pop();
				Matrix m1=matrix.top();
				matrix.pop();
				if(m1.b!=m2.a)
				{
					error=true;
					break;
				}
				ans+=m1.a*m1.b*m2.b;
				matrix.push(Matrix(m1.a,m2.b));
			}
		}
		if(error)
		{
			printf("error\n");
		}
		else
		{
			printf("%d\n",ans);
		}
	}
	return 0;
}