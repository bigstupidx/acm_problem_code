
#include<cstdio>
#include<cstring>

struct edge{
    int to;
    edge *next;
}edg[6010],*vert[1010],r_edg[6010],*r_vert[1010];
int n,top,order[1010],id[1010],in[1010],stack[100];
bool v[1010],map[1010][1010];
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
int Top_Sort()
{
    int count=0,tt=0;
    for(int i=1;i<top;i++)
        if(in[i]==0){
            count++;
            if(count>1)return false;
            stack[++tt]=i;
        }
    while(tt)
    {
        count++;
        int cnt=0;
        int i=stack[tt--];
        for(int j=1;j<top;j++)
            if(map[i][j])
            {
                in[j]--;
                if(in[j]==0)
                {
                    cnt++;
                    if(cnt>1)return false;
                    stack[++tt]=j;
                }
            }
    }
    if(count==top-1)return true;
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,x,y;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            vert[i]=NULL;
            r_vert[i]=NULL;
        }
        top=0;
        while(m--)
        {
            scanf("%d%d",&x,&y);
            Add_Edge(x,y);
        }
        memset(v,0,sizeof(v));
        top=1;
        for(int i=1;i<=n;i++)
            if(!v[i])DFS_RG(i);

        memset(v,0,sizeof(v));
        top=1;
        for(int i=n;i>0;i--)
            if(!v[order[i]]){DFS(order[i]);top++;}
        if(top==2)
        {
            printf("Yes\n");
            continue;
        }
        memset(map,0,sizeof(map));
        for(int i=1;i<=n;i++)
        {
            int ii=id[i];
            for(edge *p=vert[i];p;p=p->next)
            {
                int jj=id[p->to];
                if(ii!=jj&&!map[ii][jj]){
                    map[ii][jj]=1;
                    in[jj]++;
                }
            }
        }
        if(Top_Sort())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
