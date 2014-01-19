#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;

int n,m,deg[12],s,t,pre[160],c[160][160],f[160][160];
int fi[12]={0,2,4,8,16,32,64,128,256,512,1024,2048};
int Max_Flow()
{
    int flow=0;
    memset(f,0,sizeof(f));
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
                if(pre[j]==-1&&c[i][j]>f[i][j])
                {
                    pre[j]=i;
                    Q.push(j);
                }
            }
        }
        if(pre[t]==-1)return flow;
        for(int i=t;i!=s;i=pre[i])
            if(mini>c[pre[i]][i]-f[pre[i]][i])mini=c[pre[i]][i]-f[pre[i]][i];
        for(int i=t;i!=s;i=pre[i])
        {
            f[pre[i]][i]+=mini;
            f[i][pre[i]]-=mini;
        }
        flow+=mini;
    }
}
int main()
{
    int tcase;
    scanf("%d",&tcase);
    while(tcase--)
    {
        char ch;
        n=0;
        do{
            int d;
            scanf("%d%c",&d,&ch);
            deg[n++]=d;
        }while(ch!='\n');

        m=n*(n-1)/2;    s=0;    t=m+n+1;
        memset(c,0,sizeof(c));
        for(int i=1;i<=m;i++)   c[s][i]=1;
        for(int i=m+1;i<=m+n;i++)   c[i][t]=deg[i-m-1];
        int ans=0,aa[12];
        for(int i=1;i<fi[n];i++)
        {
            int xx=0,cnt=0,tem=i,top=1;
            memset(aa,0,sizeof(aa));
            while(tem){
                aa[xx++]=tem%2;
                if(tem%2)cnt++;
                tem/=2;
            }
            if(cnt<=ans)continue;
            for(int j=1;j<=m;j++)
                for(int k=m+1;k<=m+n;k++)
                    c[j][k]=0;
            for(int j=m+1;j<=m+n;j++)
                for(int k=j+1;k<=m+n;k++)
                    if(aa[j-m-1]&&deg[j-m-1]<deg[k-m-1])c[top++][j]=1;
                    else{c[top][j]=1;c[top++][k]=1;}
            if(Max_Flow()==m)ans=cnt;
        }
        printf("%d\n",ans);
    }
    return 0;
}
