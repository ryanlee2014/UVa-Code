#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <cstdlib>
#define in(x) scanf("%d",&x)
#define ein(x) ~scanf("%d",&x)
#define inl(x) scanf("%lld",&x)
#define ins(x) scanf("%s",x)
#define inf(x) scanf("%lf",&x)
#define inc(x) scanf("%c",&x)
#define gc() getchar()
#define out(x) printf("%d\n",x)
#define outl(x) printf("%lld\n",x)
#define od(x, y) printf("%d %d\n",x,y)
#define ms(x) memset(x,0,sizeof(x))
#define msc(x, n) memset(x,n,sizeof(x))
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
#define cr char
#define ctn continue
#define stt struct
#define il inline
#define tpl template
#define cl class
#define db double
#define sf(x) sizeof(x)
#define vt void
#define pf printf
typedef long long ll;
using namespace std;
cst ll INF = 1ll<<60;
using namespace std;
/*
 * 输入挂
 * 场场AK buff
 */
cst it MAXBUF = 10000;
cr buf[MAXBUF], *ps = buf, *pe = buf + 1;
il vt rnext()
{
	if (++ps == pe)
		pe = (ps = buf) + fread(buf, sf(cr), sf(buf) / sf(cr), stdin);
}

tpl<cl T>
il bl fin(T &ans)
{
	ans = 0;
	T f = 1;
	if (ps == pe) rtn false;//EOF
	do
	{
		rnext();
		if ('-' == *ps) f = -1;
	} wl(!isdigit(*ps) && ps != pe);
	if (ps == pe) rtn false;//EOF
	do
	{
		ans = (ans << 1) + (ans << 3) + *ps - 48;
		rnext();
	} wl(isdigit(*ps) && ps != pe);
	ans *= f;
	rtn true;
}

/*
 * 输出挂
 * 超强 超快
 */


cst it MAXOUT = 10000;
cr bufout[MAXOUT], outtmp[50], *pout = bufout, *pend = bufout + MAXOUT;
il vt write()
{
	fwrite(bufout, sf(cr), pout - bufout, stdout);
	pout = bufout;
}
il bl out_char(cr c)
{
	*(pout++) = c;
	if (pout == pend) write();
	write();
	rtn true;
}
il bl out_str(cr *s)
{
	wl(*s)
	{
		*(pout++) = *(s++);
		if (pout == pend) write();
	}
	write();
	rtn true;
}
tpl<cl T>
il bl out_int(T x)
{
	if (!x)
	{
		out_char('0');
		rtn true;
	}
	if (x < 0) x = -x, out_char('-');
	it len = 0;
	wl(x)
	{
		outtmp[len++] = x % 10 + 48;
		x /= 10;
	}
	outtmp[len] = 0;
	for (it i = 0, j = len - 1; i < j; i++, j--) swap(outtmp[i], outtmp[j]);
	out_str(outtmp);
	rtn true;
}

tpl<cl T>
il bl out_intln(T x)
{
	out_int(x),out_char('\n');
	write();
}
const int MAXN = 2e5 + 5;
const double PI = acos(-1.0);
#define max(a, b) (a) > (b) ? (a) : (b)
class Complex
{
public:
	double real, imag;
	Complex(double real = 0.0, double imag = 0.0)
	{
		this->real = real, this->imag = imag;
	}
	Complex operator - (const Complex &elem) const
	{
		return Complex(this->real - elem.real, this->imag - elem.imag);
	}
	Complex operator + (const Complex &elem) const
	{
		return Complex(this->real + elem.real, this->imag + elem.imag);
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
it n,m;
it len;
ll sum,t;
void Swap(Complex &a, Complex &b)
{
	Complex tmp = a;
	a = b;
	b = tmp;
}
void Prepare()
{
	sum=t=0;
	len = 1;
	// 将 len 扩大到 2 的整数幂
	while(len < (n << 1)+1)
		len <<= 1;
	//初始化多项式的系数
	rep(i,1,n+1)
	{
		it x;
		fin(x);
		A[i].setValue(x,0);
		A[i+n].setValue(x,0);
		sum+=x*x;
		t+=x;
	}
	rep(i,1,n+1)
	{
		it x;
		fin(x);
		B[n-i+1].setValue(x,0);
		sum+=x*x;
		t-=x;
	}
}
//雷德算法 位逆序置换
void Rader(Complex y[])
{
	for(int i = 1, j = len >> 1, k; i < len - 1; ++ i)
	{
		if(i < j)
			Swap(y[i], y[j]);
		k = len >> 1;
		while(j >= k)
		{
			j -= k;
			k >>= 1;
		}
		if(j < k)
			j += k;
	}
}
//DFT : op == 1
//IDFT : op == -1
void FFT(Complex y[], int op)
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
			for(int j = i; j < i + h / 2; ++ j)
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
		for(int i = 0; i < len; ++ i)
			y[i].real /= len;
}
//DFT 后将 A 和 B 相应点值相乘，将结果放到 res 里面
void Convolution(Complex *A, Complex *B)
{
	//evaluation
	FFT(A, 1), FFT(B, 1);
	rep(i,0,len)A[i]=A[i]*B[i];
	//interpolation
	FFT(A, -1);
	t=abs(t);
	ll ans=INF;
	rep(i,0,m+1)
		ans=min(ans,i*i*n-2*i*t);
	ans+=sum;
	ll p=0;
	rep(i,0,len)
		p=max(p,(ll)(A[i].real+0.45));
	ans-=2*p;
	out_intln(ans);
}


it main(vt)
{
	wl(fin(n)&&fin(m))
	{
		Prepare();
		Convolution(A, B);
	}
	rtn 0;
}