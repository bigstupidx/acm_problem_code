#include <cstdio>
#include <cstring>
#define zeros(x) (2*x)
#define ones(x) (2*x+1)
struct edge{
    int to;
    edge *next;
}edg[4000010],r_edg[4000010],*vert[2020],*r_vert[2020];

int top,n,order[2020],id[2020],start[2020],end[2020],choose[2020];
bool v[2020];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&r_edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
bool intersect(int i,int j)
{
    if(end[i]<=start[j]||start[i]>=end[j])return false;
    return true;
}
void DFS(int s)
{
    v[s]=1;
    for(edge *p=vert[s];p;p=p->next)
    {
        if(!v[p->to])DFS(p->to);
    }
    order[top++]=s;
}
void DFS_RG(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to);
}
void Display()
{
    int i,j;
    int tot=0;
    memset(vert,0,sizeof(vert));
    for(i=0;i<2*n;i++)
    {
        for(edge *p=r_vert[i];p;p=p->next)
        {
            if(id[i]==id[p->to])continue;
            edge *q=&edg[tot++];
            q->to=id[p->to];
            //printf("%d->%d\n",i,p->to);
            q->next=vert[id[i]];    vert[id[i]]=q;
        }
    }
    int nn=top;
    top=0;
    memset(v,0,sizeof(v));
    for(i=0;i<nn;i++)
        if(!v[i])DFS(i);
    
    for(i=0;i<2*n;i++)choose[i]=1;
    for(i=top-1;i>=0;i--)
    {
        if(choose[order[i]]==1)
            for(j=0;j<2*n;j++)
                if(id[j]==order[i])
                    choose[id[j^1]]=0;
    }
    for(i=0;i<2*n;i++)
    {
        if(choose[id[i]]){
            printf("%.2d:%.2d ",start[i]/60,start[i]%60);
            printf("%.2d:%.2d\n", end[i] / 60, end[i] % 60);
        }
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        top=0;
        for(int i=0;i<2*n;i++){r_vert[i]=NULL;vert[i]=NULL;}
        for(int i=0;i<n;i++)
        {
            int a1,a2,b1,b2,c;
            scanf("%d:%d %d:%d %d",&a1,&a2,&b1,&b2,&c);
            a1=a1*60+a2;    b1=b1*60+b2;
            start[zeros(i)]=a1; end[zeros(i)]=a1+c;
            start[ones(i)]=b1-c;    end[ones(i)]=b1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int ii=i<<1,jj=j<<1;
                if(intersect(ii,jj))
                {
                    Add_Edge(ii,jj+1);
                    Add_Edge(jj,ii+1);
                }
                if(intersect(ii,jj+1))
                {
                    Add_Edge(ii,jj);
                    Add_Edge(jj+1,ii+1);
                }
                if(intersect(ii+1,jj))
                {
                    Add_Edge(ii+1,jj+1);
                    Add_Edge(jj,ii);
                }
                if(intersect(ii+1,jj+1))
                {
                    Add_Edge(ii+1,jj);
                    Add_Edge(jj+1,ii);
                }
            }
        }
        top=0;
        memset(v,0,sizeof(v));
        for(int i=0;i<2*n;i++)
            if(!v[i])DFS(i);
        
        top=0;
        memset(v,0,sizeof(v));
        for(int i=2*n-1;i>=0;i--)
            if(!v[order[i]]){DFS_RG(order[i]);top++;}

        bool flag=false;
        for(int i=0;i<n;i++)
            if(id[zeros(i)]==id[ones(i)]){flag=true;   break;}

        if(flag)    puts("NO");
        else{
            puts("YES");
            Display();
        }
    }
    return 0;
}
