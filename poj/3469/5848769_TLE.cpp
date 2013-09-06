#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;
struct node{
    int to,c,f,r,next;
}e[1000010];
int vert[20010],t,L[20010],p[20010][2],n,m;

void Add_Edge(int u,int v,int va)
{
    //printf("%d->%d %d\n",u,v,va);
    e[++t].to=v;e[t].c=va;e[t].f=0;
    e[t].r=t+1;e[t].next=vert[u];vert[u]=t;

    e[++t].to=u;e[t].c=0;e[t].f=0;
    e[t].r=t-1;e[t].next=vert[v];vert[v]=t;
}

int Dinic(int s,int t)
{
    int flow=0;
    while(1)
    {
        memset(L,-1,sizeof(L));
        queue<int>Q;
        Q.push(s);L[s]=0;
        while(!Q.empty())
        {
            int i=Q.front();Q.pop();
            for(int j=vert[i]; j!=-1; j=e[j].next)
            {
                if(L[e[j].to]==-1&&e[j].c>e[j].f)
                {
                    L[e[j].to]=L[i]+1;
                    Q.push(e[j].to);
                }
            }
        }
        if(L[t]==-1)return flow;
        int top=0;
        p[0][0]=s;p[0][1]=vert[s];
        while(top>=0)
        {
            if(p[top][0]!=t)
            {
                while(p[top][1]>=0)
                {
                    if(L[p[top][0]]<L[e[p[top][1]].to]&&e[p[top][1]].c>e[p[top][1]].f)
                    {
                        p[top+1][0]=e[p[top][1]].to;
                        p[top+1][1]=vert[p[top+1][0]];
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
                int min=1000000000;
                int k=top-1,flag=1;
                for(int i=0;i<top;i++)
                    if(min>e[p[i][1]].c-e[p[i][1]].f){
                        min=e[p[i][1]].c-e[p[i][1]].f;
                        k=min;
                    }
                flow+=min;
                for(int i=top-1;i>=0;i--)
                {
                    e[p[i][1]].f+=min;
                    e[e[p[i][1]].r].f=-e[p[i][1]].f;
                }
                top=k;
                p[top][1]=e[p[top][1]].next;
            }
        }
    }
}
int main()
{
    int a,b,c;
    t=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n+1;i++)
        vert[i]=-1;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&a,&b);
        Add_Edge(0,i,a);
        Add_Edge(i,n+1,b);
    }
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&c);
        Add_Edge(a,b,c);
        Add_Edge(b,a,c);
        /*e[++t].to=b;e[t].c=c;e[t].f=0;
        e[t].r=t+1;e[t].next=vert[a];vert[a]=t;

        e[++t].to=a;e[t].c=c;e[t].f=0;
        e[t].r=t-1;e[t].next=vert[b];vert[b]=t;*/
    }
    printf("%d\n",Dinic(0,n+1));
    system("pause");
    return 0;
}
