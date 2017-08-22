#include<iostream>
using namespace std;
int main()
{
 long m,n,x=0,y=0,i,temp;
 while(cin>>m>>n)
 {
  x=0,y=0;           //不要忘记
  if(n<m)            //记得考略这种情况
  {
   temp=n;
   n=m;
   m=temp;
  }
  
  for(i=m;i<=n;i++)
   {
    if(i%2==0)
    {x+=i*i;}
    else
    {y+=i*i*i;}
   }
  
  cout<<x<<" "<<y<<endl; 
 }
return 0;
}
