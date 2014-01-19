#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct edge{
    int to;
    edge *next;
}edg[2000000],*vert[4010],r_edg[2000000],*r_vert[4010];

int n,top,v[4020],order[4020],id[4020],mat[2020][2001];

void Add_Edge(int u,int v)
{
    edge *p=&edg[++top];
    p->to=v;
    p->next=vert[u];    vert[u]=p;
    
    p=&r_edg[top];
    p->to=u;
    p->next=r_vert[v];  r_vert[v]=p;
}

void DFS(int s)
{
    v[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int m,u;
        top=-1;
        memset(vert,0,sizeof(vert));
        memset(r_vert,0,sizeof(r_vert));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&m);
            mat[i][0]=m;
            for(int j=1;j<=m;j++)
            {
                scanf("%d",&u);
                Add_Edge(i,u+n);
                mat[i][j]=u+n;
            }
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&u);
            Add_Edge(u+n,i);
        }
        top=1;
        memset(v,0,sizeof(v));
        for(int i=1;i<=2*n;i++)
            if(!v[i])DFS(i);
        
        top=1;
        memset(v,0,sizeof(v));
        for(int i=2*n;i>0;i--)
            if(!v[order[i]]){DFS_RG(order[i]);top++;}
        
        for(int i=1;i<=n;i++)
        {
            vector<int>aa;
            for(int j=1;j<=mat[i][0];j++)
                if(id[mat[i][j]]==id[i])
                    aa.push_back(mat[i][j]-n);
            sort(aa.begin(),aa.end());
            printf("%d",aa.size());
            for(int j=0;j<aa.size();j++)
                printf(" %d",aa[j]);
            puts("");
        }
    }
    return 0;
}
