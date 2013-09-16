#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;

int c[1030][1030],order[1002][21],cap[21],pre[1030];
int n,b;

void Build_G(int k,int mid)
{
    for(int i=0;i<=n+b+1;i++)
        for(int j=0;j<=n+b+1;j++)
            c[i][j]=0;
    for(int i=1;i<=n;i++)c[0][i]=1;
    for(int i=1;i<=b;i++)c[i+n][n+b+1]=cap[i];
    for(int i=1;i<=n;i++)
        for(int j=k;j<k+mid;j++)
            c[i][order[i][j]+n]=1;
}
int Max_Flow(int s,int t)
{    
    int flow=0;
    while(1)
    {
        int mini=inf,i;
        memset(pre,-1,sizeof(pre));
        queue<int>Q;
        Q.push(s);
        while(!Q.empty()&&pre[t]==-1)
        {
            i=Q.front();Q.pop();
            for(int j=1;j<=t;j++)
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
            if(c[pre[i]][i]<mini)mini=c[pre[i]][i];
        for(i=t;i!=s;i=pre[i])
        {
            c[pre[i]][i]-=mini;
            c[i][pre[i]]+=mini;
        }
        flow+=mini;
    }
}
int main()
{
    while(scanf("%d%d",&n,&b)!=EOF)
    {
        int i,flag;
        for(i=1;i<=n;i++)
            for(int j=0;j<b;j++)
                scanf("%d",&order[i][j]);
        for(i=1;i<=b;i++)
            scanf("%d",cap+i);
        int left=1,right=b+1,mid;
        while(left<=right)
        {
            flag=0;
            mid=(left+right)/2;
            for(i=0;i<b-mid+1;i++)
            {
                //printf("try %d %d\n",mid,i);
                Build_G(i,mid);
                //system("pause");
                if(Max_Flow(0,n+b+1)==n)
                {
                    flag=1; break;
                }
            }
            if(flag)right=mid-1;
            else left=mid+1;
        }
        printf("%d\n",left);
    }
    return 0;
}
