#include<cstdio>
#include<cstring>
#include<cstdlib>

int n,top,mp1[20][20],mp2[20][20],map[20][20],Lx[20],Ly[20];
int xflag[20],yflag[20],oppo[20];

int Get_Map(int i,int j)
{
    int ans=0;
    for(int k=0;k<n;k++)
        if(mp1[i-1][k]==j){ans+=k;break;}
    for(int k=0;k<n;k++)
        if(mp2[j-1][k]==i){ans+=k;break;}
    return ans;
}
bool Path(int s)
{
    xflag[s]=1;
    for(int i=1;i<=n;i++)
    {
        if(!yflag[i]&& (Lx[s]+Ly[i]==map[s][i]))
        {
            yflag[i]=1;
            if(oppo[i]==0||Path(oppo[i]))
            {
                oppo[i]=s;
                return true;
            }
        }
    }
    return false;
}
int KM_Match(int maxi)
{
    int sum=0;
    memset(oppo,0,sizeof(oppo));
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int d=1000000;//赋为最大值 
            memset(xflag,0,sizeof(xflag));
            memset(yflag,0,sizeof(yflag));
            if(Path(i))break;
            /*没找到增广路，则需要减小顶点权值*/
            for(int j=1;j<=n;j++)
            {
                if(xflag[j])
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(!yflag[k]&&(Lx[j]+Ly[k]-map[j][k])<d)
                            d=Lx[j]+Ly[k]-map[j][k];
                    }
                }
            }
            for(int j = 1;j <= n;j ++)
                if( xflag[j] ) 
                    Lx[j] -= d;
            for(int j = 1;j <= n;j ++)
                if( yflag[j] ) 
                    Ly[j] += d;
        }
    }
    for(int i = 1;i <= n;i ++ )
        if(oppo[i])sum += maxi-map[oppo[i]][i];
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
        scanf("%d",&n);
        memset(map,0,sizeof(map));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mp1[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&mp2[i][j]);
        int maxi=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                map[i][j]=Get_Map(i,j);
                if(maxi<map[i][j])maxi=map[i][j];
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                map[i][j]=maxi-map[i][j];
                Lx[i]=map[i][j];
                //printf("%d ",map[i][j]);
            }
            //puts("");
        }
        memset(Ly,0,sizeof(Ly));
        
        int tem = KM_Match(maxi);
        double ans=tem*0.5/n;
        printf("Data Set %d, Best average difference: %.6lf\n",ii,ans);
        
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=maxi-map[i][j];
        memset(yflag,0,sizeof(yflag));
        top=1;  DFS_Trace(1,0,tem);
    }
    system("pause");
    return 0;
}
