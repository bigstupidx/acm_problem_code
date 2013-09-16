#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    int d;
    edge *next;
}edg[1000010],*vert[2][2000];
int n,m,dis[2][2000],mark[2][2000],s1,s2,t1,t2,map[31][61];
const int inf =1000000000;
struct QN {
    int u;
    int d;
    int ss;//标志左右脚 
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
int ABS(int x){return x>0?x:-x;}
void Add_Edge(int x,int y,int va,int now,int &top)
{
    //printf("[%d][%d] -> [%d][%d] %d\n",x/m+1,x%m+1,y/m+1,y%m+1,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[now][x]; vert[now][x]=p;
}
void Build_G()
{
    int top=-1;
    memset(vert,0,sizeof(vert));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(map[i][j]==-1||map[i][j]==inf)continue;
            for(int ii=0;ii<n;ii++){
                for(int jj=j+1;jj<m&&jj<=j+3;jj++){
                    if(map[ii][jj]==-1||map[ii][jj]==0)continue;
                    if((ABS(ii-i)+jj-j)<=3){
                        Add_Edge(i*m+j,ii*m+jj,map[i][j],0,top);
                    }
                }
            }
            for(int ii=0;ii<n;ii++){
                for(int jj=0;jj<j;jj++){
                    if(map[ii][jj]==-1||map[ii][jj]==0)continue;
                    if((ABS(ii-i)+j-jj)<=3){
                        Add_Edge(i*m+j,ii*m+jj,map[i][j],1,top);
                    }
                }
            }
        }
    }
}
void dijkstra()
{
    QN now;
    priority_queue<QN>Q;
    for(int i=0;i<2;i++){
        for(int j=0;j<m*n;j++){
            dis[i][j]=inf;mark[i][j]=0;
        }
    }
    now.d=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0){
                now.u=i*m+j;now.ss=0;
                Q.push(now);now.ss=1;Q.push(now);
                dis[0][now.u]=dis[1][now.u]=0;
            }
        }
    }
    while(!Q.empty()){
        now=Q.top();Q.pop();
        int i=now.ss,k=now.u;
        if(mark[i][k])continue;
        mark[i][k]=1;
        //printf("%d [%d][%d]->",i,k/m+1,k%m+1);
        for(edge *p=vert[i][k];p;p=p->next)
        {
            if(!mark[i^1][p->to]&&dis[i^1][p->to]>dis[i][k]+p->d)
            {
                dis[i^1][p->to]=dis[i][k]+p->d;
                now.u=p->to;
                now.d=dis[i^1][p->to];
                now.ss=i^1;
                //printf(" [%d][%d] %d",p->to/m+1,p->to%m+1,dis[i^1][p->to]);
                Q.push(now);
            }
        }
        //puts("");
    }
}
int main()
{
    while(scanf("%d%d",&m,&n),n||m)
    {
        char str[4];
        t1=t2=s1=s2=-1;
        memset(map,-1,sizeof(map));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%s",str);
                if(str[0]=='S')
                    map[i][j]=0;
                else if(str[0]=='T')
                    map[i][j]=inf;
                else if(str[0]!='X')map[i][j]=str[0]-'0';
            }
        }
        Build_G();
        dijkstra();
        int mini=inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]==inf){
                    if(mini>dis[0][i*m+j])mini=dis[0][i*m+j];
                    if(mini>dis[1][i*m+j])mini=dis[1][i*m+j];
                }
        if(mini==inf)puts("-1");
        else printf("%d\n",mini);
    }
    return 0;
}
