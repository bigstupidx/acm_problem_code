#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;

int pre[120],c[120][120],n,f[120][120];
int Max_Flow(int s,int t)
{
    int flow=0;
    memset(f,0,sizeof(f));
    while(1)
    {
        int mini=inf,k;
        queue<int>Q;
        Q.push(s);
        memset(pre,-1,sizeof(pre));
        while(!Q.empty()&&pre[t]==-1)
        {
            int i=Q.front();Q.pop();
            for(int j=0;j<2*n;j++)
                if(pre[j]==-1&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    if(c[i][j]-f[i][j]<mini)mini=c[i][j]-f[i][j];
                    Q.push(j);
                }
        }
        if(pre[t]==-1)break;
        for(int i=t;i!=s;i=pre[i])
        {
            //printf("%d ",i);
            f[pre[i]][i]+=mini;
            f[i][pre[i]]-=mini;
        }
        flow+=mini;
    }
    return flow;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(c,0,sizeof(c));
        while(m--)
        {
            int x,y;
            char ch;
            while(1){
                ch=getchar();
                if(ch=='(')break;
            }
            scanf("%d%*c%d%*c",&x,&y);
            c[x+n][y]=inf;//v''-u'
            c[y+n][x]=inf;//u''-v'
        }
        for(int i=1;i<n;i++)
            c[i][i+n]=1;//V'-v''

        c[0][n]=inf;
        int mini=inf,temp;
        for(int i=1;i<n;i++)
        {
            temp=Max_Flow(0,i);
            //printf("%d\n",temp);
            if(temp<mini)mini=temp;
        }
        if(mini==inf)mini=n;
        printf("%d\n",mini);
    }
    return 0;
}
