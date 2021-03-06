#include<queue>
#include<cstdio>
#include<cstring>
#define INF 1000000000
using namespace std;

struct node{
    int to;
    int d;
    node *next;
}nod[100010],nod1[100010],*vert[1010],*vert1[1010];

int n,dis[1010],top,flag[1010];
struct gnode{
    int u;
    int d;
    bool operator<(const gnode a)const
    {
        return a.d<d;
    }
};
struct ggnode{
    int u;
    int d;
    bool operator<(const ggnode a)const
    {
        return a.d+dis[a.u]<d+dis[u];
    }
};
priority_queue<gnode>Q;
priority_queue<ggnode>Q1;
void Add_Edge1(int u,int v,int va)
{
    node *p=&nod[top];
    p->to=v;
    p->d=va;
    p->next=vert[u];
    vert[u]=p;
}
void Add_Edge2(int u,int v,int va)
{
    node *p=&nod1[top++];
    p->to=v;
    p->d=va;
    p->next=vert1[u];
    vert1[u]=p;
}
void Dijskra(int s)
{
    gnode now;
    for(int i=1;i<=n;i++)
    {
        flag[i]=0;
        dis[i]=INF;
    }
    dis[s]=0;
    while(!Q.empty())Q.pop();
    now.u=s;now.d=0;
    Q.push(now);
    for(int i=0;i<n;i++)
    {
        int k;
        do{
            if(Q.size()==0)return ;
            now=Q.top();Q.pop();
            k=now.u;
        }while(flag[k]);
        flag[k]=1;
        for(node *p=vert1[k];p;p=p->next)
        {
            if(!flag[p->to] && dis[p->to] > p->d+dis[k])
            {
                dis[p->to]=p->d+dis[k];
                now.u=p->to;
                now.d=dis[p->to];
                Q.push(now);
            }
        }
    }
}
int A_Star(int s,int t,int k)
{
    ggnode now,next;
    if(dis[s]==INF)return -1;
    
    memset(flag,0,sizeof(flag));
    while(!Q1.empty())Q1.pop();
    now.u=s;now.d=0;
    Q1.push(now);
    while(!Q1.empty())
    {
        int i;
        now=Q1.top();Q1.pop();
        i=now.u;
        flag[i]++;
        if(flag[t]==k)return now.d;
        if(flag[i]>k)continue;
        for(node *p=vert[i];p;p=p->next)
        {
            next.u=p->to;
            next.d=p->d+now.d;
            Q1.push(next);
        }
    }
    return -1;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        top=0;
        for(int i=1;i<=n;i++)
            vert[i]=NULL;
        while(m--)
        {
            int u,v,d;
            scanf("%d%d%d",&u,&v,&d);
            Add_Edge1(u,v,d);
            Add_Edge2(v,u,d);
        }
        int s,t,k;
        scanf("%d%d%d",&s,&t,&k);
        Dijskra(t);
        if(s==t)k++;/*Èç¹ûÔÚÍ¬Ò»µã£¬Ïàµ±ÓÚÒ»¿ªÊ¼¾Íµ½ÁËÖÕµã*/
        printf("%d\n",A_Star(s,t,k));
    }
    return 0;
}
