#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;
int n,amount[1010],c[120][120],pre[120],mp[1010][120];
bool v[1010];
int Max_Flow(int s,int t)
{
    int ans=0;
    while(1)
    {
        int mini=inf,i;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(s);pre[s]=0;
        while(!Q.empty() && pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=0;j <= n+1;j++)
                if(pre[j] == -1 && c[i][j]>0)
                {
                    pre[j]=i;
                    if( c[i][j] < mini ) mini = c[i][j];
                    Q.push(j);
                }
        }
        if(pre[t]==-1)return ans;
        for(i=t;    i!=s;   i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        ans+=mini;
    }
}
int main()
{
    int m;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int i,j;
        for(i=0;i<n+2;i++)
            for(j=0;j<n+2;j++)
                c[i][j]=0;
        for(i=1;i<=m;i++){
            v[i]=0; mp[i][0]=0;
            scanf("%d",amount+i);
        }
        for(i=1;i<=n;i++)
        {//build the graph is most important,but why tle ?
            int len;
            scanf("%d",&len);
            while(len--)
            {
                scanf("%d",&j);
                mp[j][ ++mp[j][0] ]=i;
                if(!v[j]){
                    v[j]=1;
                    c[0][i]+=amount[j];
                }
                else{
                    for(int k=1;k<mp[j][0];k++)
                        c[mp[j][k]][i]=inf;
                }
            }
            scanf("%d",&len);
            c[i][n+1]=len;
        }
        printf("%d\n",Max_Flow(0,n+1));
    }
    return 0;
}