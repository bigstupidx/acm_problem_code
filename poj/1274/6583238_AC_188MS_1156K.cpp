#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m,c[500][500],pre[500];
int max_flow(int s,int t){
    int flow=0;
    while(1){
        int mini=1000000000;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1){
            int i=Q.front();Q.pop();
            for(int j=0;j<=t;j++){
                if(pre[j]==-1&&c[i][j]>0){
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i]){
            if(mini>c[pre[i]][i]){
                mini=c[pre[i]][i];
            }
        }
        flow+=mini;
        for(int i=t;i!=s;i=pre[i]){
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF){
        int s=0,t=n+m+1;
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++){
            int mm,v;
            scanf("%d",&mm);
            for(int j=0;j<mm;j++){
                scanf("%d",&v);
                c[i][v+n]=1;
            }
            c[s][i]=1;
        }
        for(int i=n+1;i<=n+m;i++)
            c[i][t]=1;
        printf("%d\n",max_flow(s,t));
    }
    return 0;
}
