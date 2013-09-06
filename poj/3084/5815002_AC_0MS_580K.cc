#include<cstdio>
#include<cstring>
#include<queue>
#define inf 10000
using namespace std;

int n,t,c[24][24],pre[24];
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);  pre[s]=0;
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=0;j<n;j++)
            {
                if(pre[j]==-1&&c[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])
                mini=c[pre[i]][i];
        for(int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&t);
        for(int i=0;i<n;i++)
        {
            char str[4];
            int m,to;
            scanf("%s%d",str,&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&to);
                c[i][to]+=inf;
                c[to][i]+=1;
            }
            if(strcmp(str,"I")==0)c[n][i]=inf;
        }
        int tem=Max_Flow(n,t);
        if(tem>=inf)puts("PANIC ROOM BREACH");
        else printf("%d\n",tem);
    }
    return 0;
}
