#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
int aa[220],map[220][220];
int flag[202],y[202],x[202];
int xx[202],yy[202],n,r,c;
bool a1[202],a2[202];
int Path(int s)
{
    for(int i=1;i<c;i++)
        if(!flag[i]&&map[s][i])
        {
            flag[i]=1;
            if(y[i]==-1||Path(y[i]))
            {
                y[i]=s;
                x[s]=i;
                return 1;
            }
        }
    return 0;
}
int Max_Match()
{
    int ans=0;
    memset(y,-1,sizeof(y));
    memset(x,-1,sizeof(x));
    for(int i=1;i<r;i++)
    {
        for(int j=1;j<c;j++)
            flag[j]=0;
        if(Path(i))ans++;
    }
    return ans;
}
void Get_Ans()
{
    queue<int>Q;
    memset(a1,0,sizeof(a1));
    memset(a2,0,sizeof(a2));
    for(int i=1;i<r;i++)
        if(x[i]==-1){
            a1[i]=true;Q.push(i);
        }
    while(!Q.empty())
    {
        int i=Q.front();Q.pop();
        for(int j=1;j<c;j++)
            if(!a2[j]&&map[i][j])
            {
                a2[j]=true;
                a1[y[i]]=true;
                Q.push(y[i]);
            }
    }
    return ;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m;
        r=1,c=1;
        memset(map,0,sizeof(map));
        memset(aa,0,sizeof(aa));
        memset(xx,0,sizeof(xx));
        memset(yy,0,sizeof(yy));
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",&aa[i]);
        while(m--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(aa[u]==aa[v])continue;
            else{
                if(aa[u]==0)
                {
                    if(xx[u]==0)xx[u]=r++;
                    if(yy[v]==0)yy[v]=c++;
                    map[xx[u]][yy[v]]=1;
                }
                else{
                    if(xx[v]==0)xx[v]=r++;
                    if(yy[u]==0)yy[u]=c++;
                    map[xx[v]][yy[u]]=1;
                }
            }
        }
        int ans=Max_Match();
        Get_Ans();
        
        printf("%d",ans);

        for(int i=0;i<n;i++)
            if(aa[i]==0&&xx[i]&&!a1[xx[i]]||aa[i]==1&&yy[i]&&a2[yy[i]])printf(" %d",i);
        puts("");
    }
    return 0;
}
