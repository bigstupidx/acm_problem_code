#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[10010],r_edg[10010],*vert[102],*r_vert[102];
int top,n,in[102],out[102],id[102],order[102],visit[102];
void Add_Edge(int x,int y)
{
    edge *p=&edg[++top];
    p->to=y;
    p->next=vert[x];    vert[x]=p;
    
    p=&r_edg[top];
    p->to=x;
    p->next=r_vert[y];  r_vert[y]=p;
}
void DFS(int s)
{
    visit[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!visit[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s)
{
    visit[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!visit[p->to])DFS_RG(p->to);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        top=-1;
        for(int i=1;i<=n;i++)vert[i]=r_vert[i]=NULL;
        for(int i=1;i<=n;i++)
        {
            int j;
            while(scanf("%d",&j),j) Add_Edge(i,j);
        }
        top=1;
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
            if(!visit[i])DFS(i);
        
        top=0;
        memset(visit,0,sizeof(visit));
        for(int i=n;i>0;i--)
            if(!visit[order[i]]){DFS_RG(order[i]);top++;}
        if(top==1){
            puts("1\n0");
            continue;
        }
        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(int i=1;i<=n;i++)
            for(edge *p=vert[i];p;p=p->next)
                if(id[i]!=id[p->to])
                    out[id[i]]++,in[id[p->to]]++;
        int m1=0,m2=0,m3=0;
        for(int i=0;i<top;i++)
        {
            if(in[i]==0&&out[i]==0)m3++;
            else if(!in[i])m1++;
            else if(!out[i])m2++;
        }
        printf("%d\n%d\n",m1+m3,m3+(m1>m2?m1:m2));
    }
    return 0;
}
