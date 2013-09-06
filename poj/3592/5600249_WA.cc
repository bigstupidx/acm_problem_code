
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
char map[50][50];
struct edge{
    int to;
    edge *next;
}edg[6440],*vert[1610],r_edg[6410],*r_vert[1610];
struct node{
    int x,y;
}nod[1610];
int w[1610],w2[1610],top,order[1610],id[1610];
bool visit[1610],G2[1610][1610];
void Add_Edge(int u,int v)
{
    edge *p=&edg[top];
    p->to=v;
    p->next=vert[u];vert[u]=p;

    p=&r_edg[top++];
    p->to=u;
    p->next=r_vert[v];r_vert[v]=p;
}
void DFS_RG(int s)
{
    visit[s]=1;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!visit[p->to])DFS_RG(p->to);
    order[top++]=s;
}
void DFS(int s)
{
    visit[s]=1;
    id[s]=top;
    for(edge *p=vert[s];p;p=p->next)
        if(!visit[p->to])DFS(p->to);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k=0;
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
        {
            scanf("%s",map[i]);
            for(int j=0;j<m;j++)
                if(map[i][j]=='*')k++;
        }
        for(int i=0;i<k;i++)
            scanf("%d%d",&nod[i].x,&nod[i].y);
        memset(w,0,sizeof(w));
        for(int i=0;i<n*m;i++)
        {
            vert[i]=NULL;
            r_vert[i]=NULL;
        }
        top=0;k=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(map[i][j]=='*')
                {
                    if(i+1<n && map[i+1][j] != '#')
                        Add_Edge(i*n+j,(i+1)*n+j);
                    if(j+1<m && map[i][j+1] != '#')
                        Add_Edge(i*n+j,i*n+j+1);
                    if(map[nod[k].x][nod[k].y]!='#')
                        Add_Edge(i*n+j,nod[k].x*n+nod[k].y);
                    k++;
                }
                else if(map[i][j]=='#')continue;
                else
                {
                    w[i*n+j]=map[i][j]-'0';
                    if(i+1<n&&map[i+1][j]!='#')
                        Add_Edge(i*n+j,(i+1)*n+j);
                    if(j+1<m&&map[i][j+1]!='#')
                        Add_Edge(i*n+j,i*n+j+1);
                }
            }
        }
        n=n*m;
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++)
            if(!visit[i])DFS_RG(i);
        /*
        for(int i=0;i<n;i++)
            printf("%d ",order[i]);
        puts("");
        for(int i=0;i<n;i++)
            printf("%d ",w[i]);
        puts("");
        */
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=n-1;i>=0;i--)
            if(!visit[order[i]]){DFS(order[i]);top++;}
        /*
        printf("%d\n",top);
        for(int i=0;i<n;i++)
            printf("%d ",id[i]);
        puts("");
        */
        memset(G2,0,sizeof(G2));
        for(int i=0;i<n;i++)
        {
            for(edge *p=vert[i]; p ;p=p->next)
                if(id[i]!=id[p->to])
                    G2[id[i]][id[p->to]]=1;
        }
        memset(w2,0,sizeof(w2));
        for(int i=0;i<n;i++)
            w2[id[i]]+=w[i];
        memset(visit,0,sizeof(visit));
        queue<int>Q;
        Q.push(id[0]);visit[id[0]]=1;
        while(!Q.empty())
        {
            int i=Q.front();Q.pop();
            for(int j=0;j<top;j++)
                if(map[i][j]&&!visit[j])
                {
                    visit[j]=1;
                    w2[j]+=w2[i];
                    Q.push(j);
                }
        }
        int max=-1;
        for(int i=0;i<top;i++)
            if(visit[i] && max < w2[i])max=w2[i];
        printf("%d\n",max);
    }
    return 0;
}
