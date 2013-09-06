#include<cstdio>
#include<cstring>

int m,n,k,aa[51][51],bb[51][51],cc[51][51][51];
int Lx[200],Ly[200],map[200][200],oppo[200],xflag[200],yflag[200];
bool Path(int s,int m)
{
    xflag[s]=1;
    for(int i=1;i<m;i++)
    {
        if(!yflag[i]&&Lx[s]+Ly[i]==map[s][i])
        {
            yflag[i]=1;
            if(oppo[i]==0||Path(oppo[i],m))
            {
                oppo[i]=s;
                return true;
            }
        }
    }
    return false;
}
int KM_Match(int n,int m)
{
    memset(Lx,0,sizeof(Lx));
    memset(Ly,0,sizeof(Ly));
    memset(oppo,0,sizeof(oppo));
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
        {
            map[i][j]=200-map[i][j];
            if(map[i][j]>Lx[i])Lx[i]=map[i][j];
        }
    for(int i=1;i<n;i++)
    {
        while(1)
        {
            int d=1000000000;
            memset(xflag,0,sizeof(xflag));
            memset(yflag,0,sizeof(yflag));
            if(Path(i,m))break;
            for(int j=1;j<n;j++)
                if(xflag[j])
                {
                    for(int k=1;k<m;k++)
                        if(!yflag[k]&&Lx[j]+Ly[k]-map[j][k]<d)
                            d=Lx[j]+Ly[k]-map[j][k];
                }
            for(int j=1;j<n;j++)
                if(xflag[j])Lx[j]-=d;
            for(int j=1;j<m;j++)
                if(yflag[j])Ly[j]+=d;
        }
    }
    int sum=0;
    for(int i=1;i<m;i++)
        if(oppo[i])sum+=200-map[oppo[i]][i];
    return sum;
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&k),n||m||k)
    {
        for(int i=1;i<=n;i++)
            for(int j=0;j<k;j++)
                scanf("%d",&aa[i][j]);
        for(int i=1;i<=m;i++)
            for(int j=0;j<k;j++)
                scanf("%d",&bb[i][j]);
        for(int x=0;x<k;x++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=m;j++)
                    scanf("%d",&cc[x][i][j]);
        int ans=0,flag=0;
        for(int x=0;x<k;x++)
        {
            int n1=1,n2=1;
            for(int i=1;i<=n;i++)
            {
                int y=1;
                for(int j=1;j<=m;j++)
                {
                    for(int p=n1;p<n1+aa[i][x];p++)
                        for(int q=y;q<y+bb[j][x];q++)
                            map[p][q]=cc[x][i][j];
                    y+=bb[j][x];
                }
                n2=y;
                n1+=aa[i][x];
            }
            if(n1>n2){flag=1;break;}
            ans+=KM_Match(n1,n2);
        }
        if(flag)puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}
