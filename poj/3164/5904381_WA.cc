#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
using namespace std;

struct node{
    int x,y;
}nd[120];
double map[120][120];
int n,flag[120],pre[120];
bool visit[120];
const double inf = 1000000000;

double Distance(int x,int y)
{
    return sqrt((nd[x].x-nd[y].x)*(nd[x].x-nd[y].x)+(nd[x].y-nd[y].y)*(nd[x].y-nd[y].y));
}
void DFS(int s)
{
    visit[s]=true;
    for(int i=1;i<=n;i++)
        if(!visit[i]&&map[s][i]<inf)
            DFS(i);
}
double Mini_ST()
{
    double ans=0;
    memset(flag,0,sizeof(flag));
    while(1)
    {
        int i;
        for(i=2;i<=n;i++)
        {
            if(flag[i])continue;
            pre[i]=i;
            map[i][i]=inf-1;
            for(int j=1;j<=n;j++)
                if(!flag[j]&&map[j][i]<map[pre[i]][i])
                    pre[i]=j;
        }
        for(i=2;i<=n;i++)
        {
            if(flag[i])continue;
            int j=i;
            memset(visit,0,sizeof(visit));
            visit[1]=true;
            do{
                visit[j]=true;
                j=pre[j];
            }while(!visit[j]);
            
            if(j==1)continue;
            i=j;
            //printf("%lf+%lf\n",ans,map[pre[i]][i]);
            ans+=map[pre[i]][i];
            
            for(j=pre[i];j!=i;j=pre[j])
            {
                flag[j]=1;
                //printf("%lf+%lf\n",ans,map[pre[j]][j]);
                ans+=map[pre[j]][j];
            }
            for(j=1;j<=n;j++)
                if(!flag[j]&&map[j][i]<inf-1)
                    map[j][i]-=map[pre[i]][i];
            for(int k=1;k<=n;k++)
                if(!flag[k]){
                    for(j=pre[i];j!=i;j=pre[j])
                    {
                        if(map[j][k]<map[i][k])map[i][k]=map[j][k];
                        if(map[k][j]<inf-1&&
                            map[k][j]-map[pre[j]][j]<map[k][i])
                            map[k][i]=map[k][j]-map[pre[j]][j];
                    }
                }
            break;
        }
        if(i==n+1){
            for(int j=2;j<=n;j++)
                if(!flag[j]){
                    //printf("%d %lf+%lf\n",j,ans,map[pre[j]][j]);
                    ans+=map[pre[j]][j];
                }
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
            scanf("%d%d",&nd[i].x,&nd[i].y);
        while(m--){
            int x,y;
            scanf("%d%d",&x,&y);
            map[x][y]=Distance(x,y);
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
