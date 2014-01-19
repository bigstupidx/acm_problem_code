#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int c[400][400],pre[400],arr[7];
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
    int nca;
    scanf("%d",&nca);
    while(nca--){
        int n,maxi=-1,sum=0;
        memset(c,0,sizeof(c));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            int d,w;
            for(int j=0;j<7;j++){
                scanf("%d",arr+j);
            }
            scanf("%d%d",&d,&w);
            if(maxi<w)maxi=w;
            c[0][i]=d;  sum+=d;
            for(int j=0;j<7;j++){
                if(arr[j]){
                    for(int k=0;k<w;k++)
                        c[i][k*7+n+j+1]=1;
                }
            }
        }
        int t=maxi*7+n+1;
        for(int i=n+1;i<t;i++)
            c[i][t]=1;
        if(max_flow(0,t)==sum)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}
