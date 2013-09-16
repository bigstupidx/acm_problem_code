#include<cstdio>
#include<cmath>
#include<cstring>

struct node{
    double x,y;
}nod[202];
int n,m,y[102],flag[102],g[102][102];
double Distance(int i,int j)
{
    return sqrt((nod[i].x-nod[j].x)*(nod[i].x-nod[j].x)+
        (nod[i].y-nod[j].y)*(nod[i].y-nod[j].y));
}
bool Path(int s)
{
    for(int i=1;i<=m;i++)
    {
        if(!flag[i]&&g[s][i])
        {
            flag[i]=1;
            if(y[i]==-1||Path(y[i]))
            {
                y[i]=s;
                return true;
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    memset(y,-1,sizeof(y));
    for(int i=1;i<=n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    return ans;
}
int main()
{
    int s,v;
    while(scanf("%d%d%d%d",&n,&m,&s,&v)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&nod[i].x,&nod[i].y);
        for(int i=n+1;i<=n+m;i++)
            scanf("%lf%lf",&nod[i].x,&nod[i].y);
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                double d=Distance(i,j+n);
                if(s*v<d)continue;
                g[i][j]=1;
            }
        }
        printf("%d\n",n-Max_Match());
    }
    return 0;
}
