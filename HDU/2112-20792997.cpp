#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#define inf 0x3f3f3f3f
using namespace std;
int mapp[200][200],dist[200];
bool vis[200];
void init()
{
    for(int i=0;i<200;i++)
        for(int j=0;j<200;j++)
         {
            if(i==j)
              mapp[i][i]=0;
            else
              mapp[i][j]=inf;
         }
    for(int i=0;i<200;i++)
      dist[i]=inf;
    memset(vis,0,sizeof(vis));
}
void dijkstra(int s,int n)
{
   int minn=inf,p=0,tmp;
   for(int i=0;i<=n;i++)
   {
     if((i!=s)&&mapp[s][i]<minn)
     {
        minn=mapp[s][i];
        p=i;
     }
   }
   if(minn==inf)return;
   dist[p]=minn;
   while(1)
   {
      vis[p]=1;
      for(int i=0;i<=n;i++)
      {
          tmp=dist[p]+mapp[p][i];
          if(tmp<dist[i])
            dist[i]=tmp;
      }
      minn=inf;
      for(int i=0;i<=n;i++)
      {
        if(!vis[i]&&dist[i]<minn)
        {
            minn=dist[i];
            p=i;
        }
      }
      if(minn==inf)
        break;
   }
}
map <string,int> refl;
int main()
{
    int n,cnt,val,f,t;
    string sta,des,fm,to;
    while(cin>>n)
    {
       cnt=0;
       if(n==-1)break;
       refl.clear();
       cin>>sta>>des;
       refl[sta]=0;
       init();
       dist[0]=0;
       for(int i=0;i<n;i++)
       {
           cin>>fm>>to>>val;
           if(refl.count(fm))
             f=refl[fm];
           else
           {
              refl[fm]=++cnt;
              f=cnt;
           }
           if(refl.count(to))
             t=refl[to];
           else
           {
             refl[to]=++cnt;
             t=cnt;
           }
           if(val<mapp[f][t])
           {
             mapp[f][t]=val;
             mapp[t][f]=val;
           }
       }
       if(!refl.count(des))
       {
           refl[des]=++cnt;
       }
       dijkstra(0,cnt);
       if(des==sta)
       {
         cout<<"0\n";
         continue;
       }
       if(dist[refl[des]]==inf)
         cout<<"-1\n";
       else
         cout<<dist[refl[des]]<<endl;
    }
    return 0;
}