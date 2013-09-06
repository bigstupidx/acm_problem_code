#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 500
using namespace std;

int c[N][N],pre[N];
int m,n;//mÎª±ßÊý£¬nÎª¶¥µãÊý 
int Max_Flow(int s)
{
    int ans=0;
    while(1)
    {
        int min=1000000000,i;
        queue<int> Q;
        memset(pre,0,sizeof(pre));
        Q.push(s);
        while(!Q.empty()&&pre[n]==0)
        {
            i=Q.front();Q.pop();
            for(int j=2;j<=n;j++)
            {
                if(pre[j]==0&&c[i][j]>0)
                {
                    if(min>c[i][j])
                        min=c[i][j];
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[n]==0)break;//Ã»ÓÐÕÒµ½Ôö¹ãÂ·£¬Ìø³ö 
        for(i=n;i!=0;i=pre[i])
        {
            c[pre[i]][i]-=min;
            c[i][pre[i]]+=min;
        }
        ans+=min;
    }
    return ans;
}
int main()
{
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int a,b,va;
        memset(c,0,sizeof(c));
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&va);
            c[a][b]+=va;//Èç¹û¶¥µã a £¬b ÓÐ¶àÌõ±ß£¬Ó¦¸Ã¸ÄÎª c[a][b]+=va; 
        }
        printf("%d\n",Max_Flow(1));
    }
    return 0;
}
