#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <queue>
using namespace std;
struct edge{
    int to,c,f,next;
}e[200000];
char str[2000];
int n,m,head[2000],L[2000],p[2000][2],top;
void add_edge(int x,int y,int c,int &top)
{
    //printf("%d -> %d %d\n",x,y,c);
    e[++top].to=y;  e[top].c=c;     e[top].f=0;
    e[top].next=head[x];    head[x]=top;
    
    e[++top].to=x;  e[top].c=0;     e[top].f=0;
    e[top].next=head[y];    head[y]=top;
}
void build_g(int mid)
{
    for(int i=0;i<top;i++)e[i].f=0;
    for(int i=n+1;i<=n+m;i++){
        for(int j=head[i];j!=-1;j=e[j].next){
            if(e[j].to==n+m+1){
                e[j].c=mid;
                break;
            }
        }
    }
}
int max_flow(int s,int t)
{
    int flow=0;
    while(1)
    {
        queue<int>Q;
        memset(L,-1,sizeof(L));
        Q.push(s);  L[s]=0;
        while(!Q.empty())
        {
            int i=Q.front();Q.pop();
            for(int j=head[i];j!=-1;j=e[j].next)
            {
                if(L[e[j].to]==-1&&e[j].c>e[j].f)
                {
                    L[e[j].to]=L[i]+1;
                    Q.push(e[j].to);
                }
            }
        }
        if(L[t]==-1)return flow;
        int tot=0;
        p[0][0]=s;  p[0][1]=head[s];
        while(tot>=0)
        {
            if(p[tot][0]!=t)
            {
                while(p[tot][1]>=0)
                {
                    int pp=p[tot][1];
                    if(L[p[tot][0]]<L[e[pp].to]&&e[pp].c>e[pp].f)
                    {
                        p[tot+1][0]=e[pp].to;
                        p[tot+1][1]=head[p[tot+1][0]];
                        tot++;break;
                    }
                    p[tot][1]=e[p[tot][1]].next;
                }
                if(p[tot][1]<0)
                {
                    tot--;
                    if(tot<0)break;
                    p[tot][1]=e[p[tot][1]].next;
                }
            }
            else{
                int mini=1000000000,k=tot-1;
                for(int i=0;i<tot;i++)
                {
                    if(mini>e[p[i][1]].c-e[p[i][1]].f)
                    {
                        mini=e[p[i][1]].c-e[p[i][1]].f;
                        k=i;
                    }
                }
                flow+=mini;
                for(int i=0;i<tot;i++)
                {
                    e[p[i][1]].f+=mini;
                    e[p[i][1]^1].f-=mini;
                }
                tot=k;
                p[tot][1]=e[p[tot][1]].next;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m),n||m)
    {
        top=-1; getchar();
        memset(head,-1,sizeof(head));
        for(int i=1;i<=n;i++)
        {
            int u;
            gets(str);
            string st(str);
            istringstream in(st);
            in>>str;
            while(in>>u)add_edge(i,u+n+1,1,top);
            add_edge(0,i,1,top);
        }
        for(int i=n+1;i<=n+m;i++)
            add_edge(i,n+m+1,n,top);
        int l=0,r=n,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            build_g(mid);
            if(max_flow(0,n+m+1)==n)
                r=mid-1;
            else
                l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}
