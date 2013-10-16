#include<cstdio>
#include<cmath>
#include<cstring>
struct node{
    int x,y;
}nod[202];
int n,m,my[102],mx[102];
double dis[102][102],dd[102];
bool g[102][102],flag[102];
double Distance(int i,int j)
{
    return sqrt((nod[i].x-nod[j].x)*(nod[i].x-nod[j].x)
        +(nod[i].y-nod[j].y)*(nod[i].y-nod[j].y));
}
bool Path(int s)
{
    for(int i=0;i<m;i++)
    {
        if(!flag[i]&&g[s][i])
        {
            flag[i]=1;
            if(my[i]==-1||Path(my[i]))
            {
                mx[s]=i;
                my[i]=s;
                return true;
            }
        }
    }
    return false;
}
int Max_Match()
{
    int ans=0;
    memset(mx,-1,sizeof(mx));
    memset(my,-1,sizeof(my));
    for(int i=1;i<n;i++)
    {
        memset(flag,0,sizeof(flag));
        if(Path(i))ans++;
    }
    for(int i=0;i<n;i++)
        if(mx[i]!=-1)printf("%d %d\n",i,mx[i]);
    return ans;
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);
        for(int i=n;i<n+m;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);
        for(int i=1;i<n;i++)
            dd[i]=Distance(i-1,i);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                dis[i][j]=Distance(i,j+n);
        }
        memset(g,0,sizeof(g));
        for(int i=1;i<n;i++)
            for(int j=0;j<m;j++)
                if(dd[i]*2>dis[i-1][j]+dis[i][j])
                    g[i][j]=1;
        printf("%d\n",n+Max_Match());
        printf("%d %d",nod[0].x,nod[0].y);
        for(int i=1;i<n;i++){
            if(mx[i]!=-1){
                printf(" %d %d",nod[n+mx[i]].x,nod[n+mx[i]].y);
            }
            printf(" %d %d",nod[i].x,nod[i].y);
        }
        puts("");
    }
    return 0;
}
