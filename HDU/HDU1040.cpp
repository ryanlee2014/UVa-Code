#include<iostream>
#include <stdio.h>
void parse(int a[],int len)
{
    int tmp;
    for (int i = 0; i < len-1; i++) {
        for (int j = i; j < len; j++) {
            if(a[i]>a[j])
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }
}
using namespace std;
int main()
{
    int n;
    int a;
    int arr[10000];
    cin>>n;
    for (int j = 0; j <n ; j++) {
        cin>>a;
        for (int i = 0; i < a; i++) {
            cin >> arr[i];
        }
        parse(arr, a);
        for (int i = 0; i < a; i++) {
            if(i!=a-1)
            cout << arr[i]<<" ";
            else
            {
                cout<<arr[i]<<endl;
            }
        }
    }
    return 0;
}
