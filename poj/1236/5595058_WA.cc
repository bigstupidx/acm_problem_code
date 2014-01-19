
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 110
#define M 10010
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[M],*vert[N],r_edg[M],*r_vert[N];

int v[N],order[N],id[N],in[N],out[N];
int n,top;

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
    v[s]=1;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to);
    order[top++]=s;
}
void DFS(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            vert[i]=NULL;
            r_vert[i]=NULL;
        }
        top=0;
        for(int i=1;i<=n;i++)
        {
            int v;
            while(scanf("%d",&v),v) Add_Edge(i,v);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(r_vert[i]==NULL)ans++;
        if(ans==0)ans++;
        printf("%d\n",ans);
        
        memset(v,0,sizeof(v));
        memset(order,0,sizeof(order));
        top=1;
        for(int i=1;i<=n;i++)
        {
            if(!v[i])DFS_RG(i);
        }

        memset(v,0,sizeof(v));
        top=1;
        for(int i=n;i>0;i--)
            if(!v[order[i]]){DFS(order[i]);top++;}

        memset(out,0,sizeof(out));
        memset(in,0,sizeof(int));
        for(int i=1;i<=n;i++)
        {
            for(edge *p=vert[i];p;p=p->next)
            {
                if(id[i]!=id[p->to])
                {
                    in[id[p->to]]++;
                    out[id[i]]++;
                }

            }
        }
        int m1=0,m2=0,m3=0;
        for(int i=1;i<top;i++)
        {
            if(in[i]==0&&out[i]==0)m3++;
            else if(in[i]==0&&out[i])m2++;
            else m1++;
        }
        ans=m3+(m1>m2?m1:m2);
        printf("%d\n",ans);
    }
    return 0;
}
