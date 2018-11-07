#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a;
    while (cin>>a)
    {
        if(a<=100&&a>=90)
        {
            cout<<"A"<<endl;
        }
        else if(a<90&&a>=80)
        {
            cout<<"B"<<endl;
        }
        else if(a<80&&a>=70)
        {
            cout<<"C"<<endl;
        }
        else if(a<70&&a>=60)
        {
            cout<<"D"<<endl;
        }
        else if(a<60&&a>=0)
        {
            cout<<"E"<<endl;
        }
        else
        {
            cout<<"Score is error!"<<endl;
        }
    }
    return 0;
}