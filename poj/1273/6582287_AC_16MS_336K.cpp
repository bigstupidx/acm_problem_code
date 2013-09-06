#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m,c[202][202],pre[202];
const int inf = 1000000000;
int max_flow(int s,int t){
    int flow=0;
    while(1){
        int mini=inf;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1){
            int i=Q.front();Q.pop();
            for(int j=1;j<=n;j++){
                if(pre[j]==-1&&c[i][j]>0){
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i])
                mini=c[pre[i]][i];
        flow+=mini;
        for(int i=t;i!=s;i=pre[i]){
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
    }
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF){
        memset(c,0,sizeof(c));
        for(int i=0;i<m;i++){
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            c[u][v]+=d;
        }
        printf("%d\n",max_flow(1,n));
    }
    return 0;
}
