#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define inf 1000000000
using namespace std;
struct node{
    int u,v;
    int dis;
    bool operator<(node a)const
    {
        return a.dis>dis;
    }
}nod[40010];

int n,c[202][202],pre[202];

void Build_G(int mid)
{
    memset(c,0,sizeof(c));
    for(int i=0;i<=mid;i++)
    {
        c[nod[i].u][nod[i].v]++;
        c[nod[i].v][nod[i].u]++;
    }
}

int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=inf;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=1;j<=t;j++)
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
            if(mini>c[pre[i]][i])mini=c[pre[i]][i];
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
    int t,m;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        int i;
        for(i=0;i<m;i++){
            scanf("%d%d%d",&nod[i].u,&nod[i].v,&nod[i].dis);
        }
        sort(nod,nod+m);
        int left=0,right=m-1,mid;
        while(left<=right){
            mid=(left+right)/2;
            Build_G(mid);
            if(Max_Flow(1,n)>=t)
                right=mid-1;
            else
                left=mid+1;
        }
        printf("%d\n",nod[left].dis);
    }
    return 0;
}
