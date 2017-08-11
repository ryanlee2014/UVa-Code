**输入输出挂**

输入输出对象:
```static iofstream fin```

换行对象:```ln```

使用方法:

对于任意类型T的变量，如

```
int main(void)
{
	T a;
    fin>>a;
    fin<<a<<ln;//输出a后换行
}
```

对于浮点数的输出方式:
使用fin.setw()函数设定浮点数位数。

如:
```
int main(void)
{
	double a=3.1415926535;
    fin.setw(5);
    fin<<a<<ln;//Output:3.14159
}
```

对于多组数据的输入输出，可以使用
```
int main(void)
{
	int a,b;
    while(fin>>a>>b)
    {
    	fin<<a+b<<ln;
    }
}
```
或

```
int main(void)
{
	int a,b;
    while(fin.endfile())
    {
    	fin>>a>>b;
        fin<<a+b<<ln;
    }
}
```

完成输入输出。

对于读入一行字符串的情况，可以使用fin.getline()函数完成。

如
```
int main(void)
{
	char str[50];
    fin.getline(str);//注：不会检测数组越界
    fin<<str<<ln;
}
```

对于获取一个字符的情况，可以使用fin.getchar()函数。

如
```
int main(void)
{
	char c;
    c=fin.getchar();
    fin<<c<<ln;
}
```