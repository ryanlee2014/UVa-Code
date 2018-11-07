#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int N=201;
struct Node
{
    int x,y,z;
    bool operator < (const Node & v)const
    {
        if(x!=v.x)
            return x<v.x;
        return y<v.y;
    }
    Node(){}
    Node(int a,int b,int c):x(a),y(b),z(c){}
};
vector<Node>arr;
int dp[N];
int main(void)
{
    int x,y,z;
    int n;
    int kase=0;
    while(~scanf("%d",&n)&&n)
    {
        memset(dp,0, sizeof(dp));
        arr.clear();
        for (int i = 0; i < n; ++i)
        {
            scanf("%d%d%d",&x,&y,&z);
            arr.push_back(Node(x,y,z));
            arr.push_back(Node(x,z,y));
            arr.push_back(Node(y,x,z));
            arr.push_back(Node(y,z,x));
            arr.push_back(Node(z,x,y));
            arr.push_back(Node(z,y,x));
        }
        sort(arr.begin(),arr.end());
        int size=arr.size();
        for (int i = 0; i < size; ++i)
        {
            int pre_max=0;
            for (int j = 0; j < i; ++j)
            {
                if(arr[j].x<arr[i].x&&arr[j].y<arr[i].y&&dp[j]>pre_max)
                {
                    pre_max=dp[j];
                }
            }
            dp[i]=pre_max+arr[i].z;
        }
        printf("Case %d: maximum height = %d\n",++kase,*max_element(dp,dp+size));
    }
    return 0;
}