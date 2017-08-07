#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#define in(x) scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x,y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x,n) memset(x,n,sizeof(x))
#define cp(x) while(!x.empty())x.pop()
#define rep(i, a, b) for(int i=a;i<b;++i)
#define rvep(i, a, b) for(int i=a;i>=b;--i)
#define elif else if
#define el else
#define wl(x) while(x)
#define sn scanf
#define bl bool
#define mp make_pair
#define pii pair<int,int>
#define rtn return
#define ope operator
#define cst const
#define it int
#define stt struct
#define il inline
#define db double
#define pf printf
#define vt void
typedef long long ll;
using namespace std;
cst it INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;
const double PI = acos(-1.0);
stt Complex
{
	db real, imag;
	Complex(db r=0.0,db i=0.0):real(r),imag(i){}
	il Complex operator - (const Complex &elem) const
	{
		return Complex(real - elem.real, imag - elem.imag);
	}
	Complex operator + (const Complex &elem) const
	{
		return Complex(real + elem.real, imag + elem.imag);
	}
	Complex operator * (const Complex &elem) const
	{
		return Complex(this->real * elem.real - this->imag * elem.imag, this->real * elem.imag + this->imag * elem.real);
	}
	void setValue(double real = 0.0, double imag = 0.0)
	{
		this->real = real, this->imag = imag;
	}
};
Complex A[MAXN], B[MAXN];
int res[MAXN], len, mlen, len1, len2;
char str1[MAXN >> 1], str2[MAXN >> 1];
il vt swap(Complex &a, Complex &b)
{
	Complex tmp = a;
	a = b;
	b = tmp;
}
il vt Prepare()
{
	len1 = strlen(str1), len2 = strlen(str2);
	mlen = max(len1, len2);
	len = 1;
	// 将 len 扩大到 2 的整数幂
	wl(len<(mlen<<1))len<<=1;
	//初始化多项式的系数
	rep(i,0,len1)A[i].setValue(str1[len1 - i - 1] - '0', 0);
	rep(i,0,len2)B[i].setValue(str2[len2 - i - 1] - '0', 0);
	// 补 0
	rep(i,len1,len)A[i].setValue();
	rep(i,len2,len)B[i].setValue();
}
//雷德算法 位逆序置换
il vt Rader(Complex *y)
{
	for(int i = 1, j = len >> 1, k; i < len - 1; ++ i)
	{
		if(i < j)
			swap(y[i], y[j]);
		k = len >> 1;
		wl(j>=k)
		{
			j-=k;
			k>>=1;
		}
		if(j < k)
			j += k;
	}
}
//DFT : op == 1
//IDFT : op == -1
il vt FFT(Complex *y, int op)
{
	//先位逆序置换
	Rader(y);
	// h 为每次要处理的长度， h = 1 时不需处理
	for(int h = 2; h <= len; h <<= 1)
	{
		// Wn = e^(2 * PI / n)，如果是插值，那么 Wn = e^(-2 * PI / n)
		Complex Wn(cos(op * 2 * PI / h), sin(op * 2 * PI / h));
		for(int i = 0; i < len; i += h)
		{
			//旋转因子，初始化为 e^0
			Complex W(1, 0);
			rep(j,i,i+h/2)
			{
				Complex u = y[j];
				Complex t = W * y[j + h / 2];
				//蝴蝶操作
				y[j] = u + t;
				y[j + h / 2] = u - t;
				//每次更新旋转因子
				W = W * Wn;
			}
		}
	}
	// 插值的时候要除以 len
	if(op == -1)
		rep(i,0,len)
			y[i].real /= len;
}
//DFT 后将 A 和 B 相应点值相乘，将结果放到 res 里面
void Convolution(Complex *A, Complex *B)
{
	//evaluation
	FFT(A, 1), FFT(B, 1);
	rep(i,0,len)
		A[i] = A[i] * B[i];
	//interpolation
	FFT(A, -1);
	rep(i,0,len)
		res[i] = (int)(A[i].real + 0.5);
}
il vt Adjustment(int *arr)
{
	//次数界为 len，所以不用担心进位不会进到第 len 位
	rep(i,0,len)
	{
		res[i + 1] += res[i] / 10;
		res[i] %= 10;
	}
	//去除多余的 0
	wl(-- len && res[len] == 0);
}
il vt Display(int *arr)
{
	rvep(i,len,0)
		putchar(arr[i] + '0');
	puts("");
}
int main(void)
{
	wl(gets(str1) && gets(str2))
	{
		Prepare();
		Convolution(A, B);
		Adjustment(res);
		Display(res);
	}
	return 0;
}