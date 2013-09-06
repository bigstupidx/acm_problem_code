#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
const int INF = 1 << 30;
int in[220],out[220],c[220][220],pre[220];
int Max_Flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        int mini=INF;
        queue<int>Q;
        memset(pre,-1,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=0;j<=t;j++)
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
        flow+=mini;
        for(int i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
    }
}
int main() {
     int casn;
     scanf("%d", &casn);
     while(casn --) {
          int i, m, n;
          memset(in, 0, sizeof(in));
          memset(out, 0, sizeof(out));
          memset(c,0,sizeof(c));
          scanf("%d %d", &m, &n);
          int s = 0, t = m + 1;
          for(i = 1; i <= n; i ++) {
               int u, v, tag;
               scanf("%d %d %d", &u, &v, &tag);
               if(u == v) continue;
               in[v] ++; out[u] ++;
               if(tag == 0) c[u][v]=1;
          }
          int sum = 0;
          for(i = 1; i <= m; i ++) {
               out[i] -= in[i];
               if(out[i] & 1) break;
               out[i] >>= 1;
               if(out[i] > 0) {
                     sum += out[i];
                     c[s][i]=out[i];
               }else if(out[i] < 0) {
                    c[i][t]=-out[i];
               }
          }
          if(i == m + 1 && sum == Max_Flow(s, t)) printf("possible\n");
          else printf("impossible\n");
     }
     return(0);
}
