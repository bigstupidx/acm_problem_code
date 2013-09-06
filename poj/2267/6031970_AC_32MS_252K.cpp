#include <map>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
struct edge{
    int to;
    int d;
    edge *next;
}e[1000010],*vert[1200];
using namespace std;
struct QN {
    int u;
    int d;
    bool operator<(const QN a)const
    {
        return a.d<d;
    }
};
char aa[40],bb[40];
int n,m,dis[1200],mark[1200],edg[1010][4];
const int inf =1000000000;
void Add_Edge(int x,int y,int va,int &top)
{
   // printf("%d->%d %d\n",x,y,va);
    edge *p=&e[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];    vert[x]=p;
}
void Dijkstra(int s)
{
    QN now;
    priority_queue<QN>Q;
    now.d=0;
    for(int i=0;i<n;i++){
        dis[i]=inf;    mark[i]=0;
        if(edg[i][0]==s){
            now.u=i;dis[i]=0;
            Q.push(now);
        }
    }
    for(int k,i=1;i<n;i++)
    {
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(mark[k]);
        mark[k]=1;
        for(edge *p=vert[k];p;p=p->next)
        {
            if(!mark[p->to]&&dis[p->to]>dis[k]+p->d)
            {
                dis[p->to]=dis[k]+p->d;
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int main()
{
    //freopen("in.in","r",stdin);
    //freopen("out.txt","w",stdout);
    int tt;
    scanf("%d",&tt);
    for(int ii=1;ii<=tt;ii++)
    {
        int k=0,u,v,st,tim,top=-1;
        scanf("%d",&m);
        n=1;
        map<string,int>mp;
        map<string,int>::iterator p;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<m;i++)
        {
            scanf("%s%s%d%d",aa,bb,&st,&tim);
            if(st>=24)st%=24;
            if(tim>12||st>6&&st<18)continue;
            if(st<=6&&st+tim>6)continue;
            if(st>=18&&st+tim>30)continue;
            p=mp.find(aa);
            if(p==mp.end())
            {
                mp[aa]=n;
                u=n++;
            }
            else u=p->second;
            p=mp.find(bb);
            if(p==mp.end())
            {
                mp[bb]=n;
                v=n++;
            }
            else v=p->second;
            edg[k][0]=u;edg[k][1]=v;
            edg[k][2]=st;
            if(st+tim>=24)st=(st+tim)%24;
            else st=st+tim;
            edg[k++][3]=st;
        }
        n=k;
       // for(int i=0;i<k;i++)
       //     printf("%d %d %d %d\n",edg[i][0],edg[i][1],edg[i][2],edg[i][3]);
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<k;j++)
            {
                if(edg[i][1]==edg[j][0])
                {
                    if(edg[i][3]<=edg[j][2]&&edg[j][2]<7)
                        Add_Edge(i,j,0,top);
                    else if(edg[i][3]<=edg[j][2]&&edg[i][3]>17)
                        Add_Edge(i,j,0,top);
                    else if(edg[j][2]<7&&edg[i][3]>17)
                        Add_Edge(i,j,0,top);
                    else
                        Add_Edge(i,j,1,top);
                }
            }
        }
        scanf("%s%s",aa,bb);
        /*for(int i=1;i<n;i++){
            for(int j=1;j<n;j++)
                printf("%d ",gra[i][j]);
            puts("");
        }*/
        printf("Test Case %d.\n",ii);
        p=mp.find(aa);
        if(p==mp.end())
        {
            puts("There is no route Vladimir can take.");
            continue;
        }
        else u=p->second;
        
        p=mp.find(bb);
        if(p==mp.end())
        {
            puts("There is no route Vladimir can take.");
            continue;
        }
        else v=p->second;
        if(u==v){
            printf("Vladimir needs 0 litre(s) of blood.\n");
            continue;
        }
        Dijkstra(u);
        int mini=inf;
        for(int i=0;i<n;i++)
            if(edg[i][1]==v&&mini>dis[i])
                mini=dis[i];
        if(mini==inf)puts("There is no route Vladimir can take.");
        else printf("Vladimir needs %d litre(s) of blood.\n",mini);
    }
    return 0;
}
