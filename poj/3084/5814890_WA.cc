#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define inf 10000000
using namespace std;
int n,t,c[24][24],f[24][24],pre[24];
int Max_Flow(int s,int t)
{
    int flow=0;
    memset(f,0,sizeof(f));
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
                if(pre[j]==-1&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    Q.push(j);
                }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i]-f[pre[i]][i])
                mini=c[pre[i]][i]-f[pre[i]][i];
        for(int i=t;i!=s;i=pre[i])
        {
            f[pre[i]][i]+=mini;
            f[i][pre[i]]-=mini;
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
        vector<int>aa;
        memset(c,0,sizeof(c));
        scanf("%d%d",&n,&t);
        for(int i=0;i<n;i++)
        {
            char str[4];
            int m,to;
            scanf("%s%d",str,&m);
            if(strcmp(str,"I")==0)aa.push_back(i);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&to);
                c[i][to]+=inf;
                c[to][i]+=1;
            }
        }
        int flag=1,cnt=0;
        for(int i=0;i<aa.size();i++){
            if(aa[i]==t){flag=0;break;}
            int tem=Max_Flow(aa[i],t);
            if(tem>=inf){flag=0;break;}
            else cnt+=tem;
        }
        if(!flag)puts("PANIC ROOM BREACH");
        else printf("%d\n",cnt);
    }
    return 0;
}
