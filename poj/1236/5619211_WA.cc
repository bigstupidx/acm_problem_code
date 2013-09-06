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
        memset(in,0,sizeof(in));
        for(i=1;i<=n;i++)
        {
            int vv;
            while(scanf("%d",&vv),vv){in[vv]++;Add_Edge(i,vv);}
        }
        int ans=0;
        for(i=1;i<=n;i++){
            if(in[i]==0)ans++;
            //printf("%d ",in[i]);
        }
        if(ans==0)ans++;
        printf("%d\n",ans);

        memset(v,0,sizeof(v));
        top=1;
        for(int i=1;i<=n;i++)
            if(!v[i])DFS_RG(i);

        memset(v,0,sizeof(v));
        top=1;
        for(i=n;i>0;i--)
            if(!v[order[i]]){DFS(order[i]);top++;}

        if(top==2)
        {
            puts("0");
            continue;
        }
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
        int m1=0,m2=0,m3=0;
        for(i=1;i<top;i++)
        {
            if(!in[i]&&!out[i])m3++;
            else if(!in[i]&&out[i])m2++;
            else if(in[i]&&!out[i])m1++;
        }
        printf("%d\n",m3+m2>m1?m2:m1);
    }
    return 0;
}
