#include<iostream>
#include<stdlib.h>
#include<queue>

using namespace std;
struct edge{
    int v;
    int dis;
    edge *next;
}edges[20010],*vert[1010];
struct node{
    int u;
    int mass;
    int total;
    bool operator<(const node a)const 
    {
        return a.total < total;
    }
};
int price[1010];
int dt[1010][102];
int m,n,top;
void add_edge(int u,int v,int dis)
{
    edge *p=&edges[top++];
    p->v=v;
    p->dis=dis;
    p->next=vert[u];
    vert[u]=p;
}
int mmax(int x,int y)
{
    if (x>y)return x;
    return y;
}
void solve(int c,int s,int e)
{
    node now,next;
    priority_queue<node>Q;
    for(int i=0;i<n;i++)
        for(int j=0;j<=c;j++)
            dt[i][j]=100000000;
    now.u=s;now.total=0;now.mass=0;
    Q.push(now);
    while(!Q.empty())
    {
        now=Q.top();Q.pop();
        if(now.u==e)
            break;
        if(now.total >= dt[now.u][now.mass]) continue;
        dt[now.u][now.mass] = now.total;
        for(edge *p = vert[now.u]; p ;p = p->next)
        {
            next.u=p->v;
            for(int i = mmax(p->dis,now.mass) ;i <= c;i++)
            {
                next.mass = i - p->dis;
                next.total=now.total+price[now.u]*(i-now.mass);
                Q.push(next);
            }
        }
    }
    if(now.u==e)
        cout<<now.total<<endl;
    else
        cout<<"impossible"<<endl;
    return ;
}
int main()
{
    top=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>price[i];
    for(int i=0;i<m;i++)
    {
        int u,v,dis;
        cin>>u>>v>>dis;
        add_edge(u,v,dis);
        add_edge(v,u,dis);
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int c,s,e;
        cin>>c>>s>>e;
        solve(c,s,e);
    }
    system("pause");
    return 0;
}
