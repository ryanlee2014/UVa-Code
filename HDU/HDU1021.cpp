#include<iostream>
#include <stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    int arr[8];
    arr[0]=7%3;
    arr[1]=11%3;
    for (int i = 2; i < 8; i++) {
        arr[i]=(arr[i-1]+arr[i-2])%3;
    }
    while (cin>>n)
    {
        if(arr[n%8]==0)
        {
            cout<<"yes"<<endl;
        } else
        {
            cout<<"no"<<endl;
        }
    }
    return 0;
}
