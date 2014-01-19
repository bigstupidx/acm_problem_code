#include<cstdio>
#include<cstring>

int n,m,map[51][2502],Lx[51],Ly[2502];
int xflag[51],yflag[51],y[51],x[51],aa[51][51];
const int inf=1000000000;

bool Path(int s)
{
    xflag[s]=1;
    for(int i=1;i<=m*n;i++)
    {
        if(!yflag[i]&&Lx[s]+Ly[i]==map[s][i])
        {
            yflag[i]=1;
            if(y[i]==-1||Path(y[i]))
            {
                y[i]=s;
                x[s]=i;
                return true;
            }
        }
    }
    return false;
}
int KM_Match()
{
    memset(Lx,0,sizeof(Lx));
    memset(Ly,0,sizeof(Ly));
    memset(x,-1,sizeof(x));
    memset(y,-1,sizeof(y));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m*n;j++)
        {
            map[i][j]=inf-map[i][j];
            if(Lx[i]<map[i][j])Lx[i]=map[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        while(1)
        {
            int d=inf;
            memset(xflag,0,sizeof(xflag));
            memset(yflag,0,sizeof(yflag));
            if(Path(i))break;
            for(int j=1;j<=n;j++)
            {
                if(xflag[j])
                {
                    for(int k=1;k<=m*n;k++)
                        if(!yflag[k]&&Lx[j]+Ly[k]-map[j][k]<d)
                            d=Lx[j]+Ly[k]-map[j][k];
                }
            }
            for(int j=1;j<=n;j++)
                if(xflag[j])
                    Lx[j]-=d;
            for(int j=1;j<=m*n;j++)
                if(yflag[j])
                    Ly[j]+=d;
        }
    }
    int sum=0;
    for(int i=1;i<=m*n;i++)
        if(y[i]!=-1)sum+=inf-map[y[i]][i];
    return sum;
}
int main()
{
    int ncase;
    scanf("%d",&ncase);
    while(ncase--)
    {
        scanf("%d%d",&n,&m);
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&aa[i][j]);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=1;k<=n;k++)
                    map[i][(k-1)*m+j]=k*aa[i][j];
            }
        }
        printf("%.6lf\n",KM_Match()*1.0/n);
    }
    return 0;
}
