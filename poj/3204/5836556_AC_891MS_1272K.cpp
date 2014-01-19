#include<queue>
#include<cstdio>
#include<cstring>
#define inf 1000000000
using namespace std;
int edg[5002][2],c[520][520],pre[520];
int n,m,v[520];
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf,i;
        queue<int>Q;Q.push(s);
        memset(pre,-1,sizeof(pre));
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=1;j<n;j++)
            {
                if(pre[j]==-1&&c[i][j]>0)
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1){
            //printf("flow %d\n",flow);
            return flow;
        }
        for(i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])mini=c[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
void DFS(int s)
{
    v[s]=1;
    for(int i=1;i<n;i++)
        if(!v[i]&&c[s][i]>0)
            DFS(i);   
}
void DFS_2(int t)
{
    v[t]=2;
    for(int i=0;i<n;i++)
        if(!v[i]&&c[i][t]>0)
            DFS_2(i);
}
int main()
{
    int k=0;
    memset(c,0,sizeof(c));
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        scanf("%d",&c[x][y]);
        if(c[x][y]==0)continue;
        edg[k][0]=x;  edg[k++][1]=y;
    }
    Max_Flow(0,n-1);
    memset(v,0,sizeof(v));
    DFS(0); DFS_2(n-1);
/*    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    puts("");   */
    int cnt=0;
    for(int i=0;i<k;i++)
        if(v[edg[i][0]]==1&&v[edg[i][1]]==2)
            cnt++;
    printf("%d\n",cnt);
    return 0;
}
