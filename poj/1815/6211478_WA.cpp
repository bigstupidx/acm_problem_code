#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
const int Max=404;
const int INF=1<<30;
int map[Max][Max],c[Max][Max];
int ans[Max];
int queue[Max],pre[Max];
void built_Graph(int n)
{
     memset(map,0,sizeof(map));
     for(int i=1;i<=n;i++)
     {
             map[i+n][i]=1;
             for(int j=1;j<=n;j++)
                 if(c[i][j])
                     map[i][j+n]=INF;
     }
}
int bfs(int s,int t,int n)
{
    int head=0,tail=0;
    queue[tail++]=s;
    memset(pre,-1,sizeof(pre));
    while(head<tail)
    {
         int u=queue[head++];
         for(int i=1;i<=n;i++)
         {
             if(c[u][i]>0&&pre[i]==-1)
             {
                   queue[tail++]=i;
                   pre[i]=u;
                   if(i==t) break;
             }
         }
    }
    if(pre[t]==-1) return 0;
    int delta=INF;
    for(int i=t;i!=s;i=pre[i])
       delta=min(delta,c[pre[i]][i]);
    if(delta==INF) return 0;
    else return delta;
}
int max_flow(int s,int t,int n)
{
     int flow=0;
     while(1)
     {
             int delta=bfs(s,t,n);
             if(delta==0) break;
             flow+=delta;
             for(int i=t;i!=s;i=pre[i])
             {
                     c[pre[i]][i]-=delta;
                     c[i][pre[i]]+=delta;
             }
     }
     return flow;
}
int main()
{
    int n,s,t;
    while(scanf("%d%d%d",&n,&s,&t)!=EOF)
    {
          memset(ans,0,sizeof(ans));
          memset(c,0,sizeof(c));
          for(int i=1;i<=n;i++)
              for(int j=1;j<=n;j++)
                      scanf("%d",&c[i][j]);
          if(c[s][t])
          {
              printf("NO ANSWER!\n");
              continue;
          }
          built_Graph(n);
          memcpy(c,map,sizeof(map));
          int F=max_flow(s,t,2*n);
          int num=0;
          for(int i=1;i<=n;i++)
              if(i!=s&&i!=t)
              {
                   memcpy(c,map,sizeof(map));
                   c[i+n][i]=0;
                   if(max_flow(s,t,2*n)!=F)
                   {
                        map[i+n][i]=0;
                        ans[++num]=i;
                        F--;
                   }
              }
          if(num==0)
          {
                    printf("%d\n",0);
                    continue;
          }
          printf("%d\n",num);
          for(int i=1;i<=num;i++)
          {
              if(i>1) printf(" ");
              printf("%d",ans[i]);
          }
          printf("\n");
    }
    return 0;
}