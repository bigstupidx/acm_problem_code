#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
using namespace std;
struct node{
    int to,c,f,r,next;
}e[40020];
int n,p[110][110],tail,L[110],head[110];
int Dinic(int s,int t)
{
    int flow=0;
    while(1)
    {
        queue<int>Q;
        memset(L,-1,sizeof(L));
        Q.push(s);L[s]=0;
        while(!Q.empty())
        {
            int i=Q.front();Q.pop();
            for(int j=head[i];j!=-1;j=e[j].next)
            {
                if(L[e[j].to]==-1 && e[j].c > e[j].f)
                {
                    L[e[j].to]=L[i]+1;
                    Q.push(e[j].to);
                }
            }
        }
        if(L[t]==-1)return flow;
        int top=0;
        p[0][0]=s;p[0][1]=head[s];
        while(top>=0)
        {
            if(p[top][0]!=t)
            {
                while(p[top][1]>=0)
                {
                    if(L[p[top][0]]<L[e[p[top][1]].to]&& e[p[top][1]].c > e[p[top][1]].f)
                    {
                        p[top+1][0]=e[p[top][1]].to;
                        p[top+1][1]=head[p[top+1][0]];
                        top++;break;
                    }
                    p[top][1]=e[p[top][1]].next;
                }
                if(p[top][1]<0)
                {
                    top--;
                    p[top][1]=e[p[top][1]].next;
                }
            }
            else
            {
                int min=1000000000,k=top-1,flag=1;
                for(int i=0;i<top;i++)
                    if(min > e[p[i][1]].c-e[p[i][1]].f)min = e[p[i][1]].c-e[p[i][1]].f;
                flow+=min;
                for(int i = top-1;i>=0;i--)
                {
                    e[p[i][1]].f+=min;
                    e[e[p[i][1]].r].f=-e[p[i][1]].f;
                    if(flag&&e[p[i][1]].f==e[p[i][1]].c){flag=0;k=i;}
                }
                top=k;
                p[top][1]=e[p[top][1]].next;
            }
        }
    }
}
void add_edge(int u,int v,int z)
{
    e[++tail].to=v;e[tail].c=z;e[tail].f=0;
    e[tail].r=tail+1;e[tail].next=head[u];head[u]=tail;

    e[++tail].to=u;e[tail].c=0;e[tail].f=0;
    e[tail].r=tail-1;e[tail].next=head[v];head[v]=tail;
}
int main()
{
    int np,nc,m;
    while(scanf("%d%d%d%d",&n,&np,&nc,&m)!=EOF)
    {
        int u,v,z,i;
        memset(head,-1,sizeof(head));
        tail=-1;
        for(i=0;i<m;i++){
            while(getchar()!='(');
            scanf("%d,%d)%d",&u,&v,&z);
            add_edge(u+1,v+1,z);
        }
        for(i=0;i<np;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&z);
            add_edge(0,u+1,z);
        }
        for(i=0;i<nc;i++){
            while(getchar()!='(');
            scanf("%d)%d",&u,&z);
            add_edge(u+1,n+1,z);
        }
        printf("%d\n",Dinic(0,n+1));
    }
    return 0;
}
