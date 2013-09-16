#include<cstdio>
#include<cstring>
#include<cmath>

struct node{
    double x,y;
}nod[120];

double map[120][120];
int n,visit[120],flag[120],pre[120];
const double inf=1000000000;
double Distance(int i,int j)
{
    return sqrt((nod[i].x-nod[j].x)*(nod[i].x-nod[j].x)+
        (nod[i].y-nod[j].y)*(nod[i].y-nod[j].y));
}
void DFS(int s)
{
    visit[s]=1;
    for(int i=1;i<=n;i++)
        if(!visit[i]&&map[s][i]<inf)
            DFS(i);
}
double Mini_ST()
{
    double ans=0;
    memset(flag,0,sizeof(flag));
    while(1){
        int i;
        for(i=2;i<=n;i++){
            if(flag[i])continue;
            pre[i]=i;
            map[i][i]=inf;
            for(int j=1;j<=n;j++)
                if(!flag[j]&&map[j][i]<map[pre[i]][i])
                    pre[i]=j;
        }
        for(i=2;i<=n;i++){
            if(flag[i])continue;
            int j=i;
            memset(visit,0,sizeof(visit));
            visit[1]=1;
            do{
                visit[j]=1;
                j=pre[j];
            }while(!visit[j]);
            
            if(j==1)continue;
            i=j;
            ans+=map[pre[i]][i];
            for(j=pre[i];j!=i;j=pre[j]){
                flag[j]=1;
                ans+=map[pre[j]][j];
            }
            for(j=1;j<=n;j++)
                if(!flag[j]&&map[j][i]<inf)
                    map[j][i]-=map[pre[i]][i];
            for(int k=1;k<=n;k++)
                if(!flag[k]){
                    for(j=pre[i];j!=i;j=pre[j]){
                        if(map[j][k]<map[i][k])map[i][k]=map[j][k];
                        if(map[k][j]<inf&&map[k][j]-map[pre[j]][j]<map[k][i])
                            map[k][i]=map[k][j]-map[pre[j]][j];
                    }
                }
            break;
        }
        if(i==n+1){
            for(i=2;i<=n;i++)
                if(!flag[i])
                    ans+=map[pre[i]][i];
            break;
        }
    }
    return ans;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=inf;
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&nod[i].x,&nod[i].y);
        while(m--)
        {
            int i,j;
            scanf("%d%d",&i,&j);
            map[i][j]=Distance(i,j);
        }
        memset(visit,0,sizeof(visit));  DFS(1);
        for(int i=1;i<=n;i++)
            if(!visit[i])goto exit;
        printf("%.2lf\n",Mini_ST());
        continue;
   exit:puts("poor snoopy");
    }
    return 0;
}
