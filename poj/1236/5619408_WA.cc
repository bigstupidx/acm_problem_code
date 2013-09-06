#include<cstdio>
#include<cstring>
struct edge{
    int to;
    edge *next;
}edg[10010],*vert[120],r_edg[10010],*r_vert[120];
int n,in[120],top,id[120],order[120],out[120];
bool v[120];

void Add_Edge(int x,int y)
{
    edge *p=&edg[top];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&r_edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
void DFS_RG(int s)
{
    v[s]=true;
    for(edge *p=r_vert[s]; p ;p=p->next)
    {
        if(!v[p->to])DFS_RG(p->to);
    }
    order[top++]=s;
}
void DFS(int s)
{
    v[s]=true;
    id[s]=top;
    for(edge *p=vert[s]; p ;p=p->next)
        if(!v[p->to])DFS(p->to);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int i;
        top=0;
        for(i=1;i<=n;i++)
            vert[i]=r_vert[i]=NULL;
        for(i=1;i<=n;i++)
        {
            int vv;
            while(scanf("%d",&vv),vv)Add_Edge(i,vv);
        }

        memset(v,0,sizeof(v));
        top=1;
        for(int i=1;i<=n;i++)
            if(!v[i])DFS_RG(i);

        memset(v,0,sizeof(v));
        top=1;
        for(i=n;i>0;i--)
            if(!v[order[i]]){DFS(order[i]);top++;}

        memset(in,0,sizeof(in));
        memset(out,0,sizeof(out));
        for(i=1;i<=n;i++)
        {
            for(edge *p=vert[i];p;p=p->next)
            {
                if(id[i]!=id[p->to])
                    in[id[p->to]]++,out[id[i]]++;
            }
        }
        if(top==2)
        {
            printf("1\n0\n");
        }
        int m1=0,m2=0;
        for(i=1;i<top;i++)
        {
            if(!in[i])m2++;
            if(!out[i])m1++;
        }
        printf("%d\n%d\n",m2,m2>m1?m2:m1);
    }
    return 0;
}
