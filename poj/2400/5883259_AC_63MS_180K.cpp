#include<cstdio>
#include<cstring>
int top,n;
int map[20][20],xflag[20],yflag[20],Lx[20],Ly[20],oppo[20];
bool Path(int s)
{
    xflag[s]=1;
    for(int i=1;i<=n;i++)
    {
        if(!yflag[i]&&Lx[s]+Ly[i]==map[s][i])
        {
            yflag[i]=1;
            if(oppo[i]==-1||Path(oppo[i]))
            {
                oppo[i]=s;
                return true;
            }
        }
    }
    return false;
}
int KM_Match()
{
    int sum=0;
    memset(oppo,-1,sizeof(oppo));
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int mini=100000;
            memset(xflag,0,sizeof(xflag));
            memset(yflag,0,sizeof(yflag));
            if(Path(i))break;
            for(int j=1;j<=n;j++)
                if(xflag[j])
                {
                    for(int k=1;k<=n;k++)
                        if(!yflag[k]&&Lx[j]+Ly[k]-map[j][k]<mini)
                            mini=Lx[j]+Ly[k]-map[j][k];
                }
            for(int j=1;j<=n;j++)
                if(xflag[j])Lx[j]-=mini;
            for(int j=1;j<=n;j++)
                if(yflag[j])Ly[j]+=mini;
        }
    }
    for(int i=1;i<=n;i++)
        sum+=100-map[oppo[i]][i];
    return sum;
}
void DFS_Trace(int s,int sum,int total)
{
    if(sum>total)return ;
    if(s==n+1){
        if(sum!=total)return ;
        printf("Best Pairing %d\n",top++);
        for(int i=1;i<=n;i++)
            printf("Supervisor %d with Employee %d\n",i,Ly[i]);
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(!yflag[i])
        {
            yflag[i]=1;
            Ly[s]=i;
            DFS_Trace(s+1,sum+map[s][i],total);
            yflag[i]=0;
        }
    }
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    for(int ii=1;ii<=ncase;ii++)
    {
        int tem;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&tem);
                map[tem][i]=j-1;
            }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&tem);
                map[i][tem]+=j-1;
            }
        memset(Lx,0,sizeof(Lx));
        memset(Ly,0,sizeof(Ly));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                map[i][j]=100-map[i][j];
                if(Lx[i]<map[i][j])Lx[i]=map[i][j];
            }
        tem=KM_Match();
        double ans=tem*0.5/n;
        printf("Data Set %d, Best average difference: %.6lf\n",ii,ans);
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=100-map[i][j];
        memset(yflag,0,sizeof(yflag));
        top=1;  DFS_Trace(1,0,tem);
        puts("");
    }
    return 0;
}
