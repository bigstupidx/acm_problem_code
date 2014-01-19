#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
#include<algorithm>
#define ones(x) (2*x+1)
#define zeros(x) (2*x)
using namespace std;
struct edge{
    int to;
    edge *next;
}edg[10010],r_edg[10010],*vert[2020],*r_vert[2020];

int n,top,order[2020],id[2020],start[2020],end[2020],in[2020],choose[2020];
bool v[2020];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
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
        if(!v[p->to])
            DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s,int root)
{
    v[s]=1;
    id[s]=root;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to,root);
}
void Display()
{
    top=0;
    memset(vert,0,sizeof(vert));
    for(int i=0;i<2*n;i++)
    {
        if(id[i]==i)
        {
            for(int j=0;j<2*n;j++)
                if(id[j]==i)
                {
                    for(edge *p=r_vert[j];p;p=p->next)
                    {
                        edge *q=&edg[top++];
                        q->to=id[p->to];
                       // printf("%d->%d\n",i,p->to);
                        q->next=vert[i];vert[i]=q;
                    }
                }
        }
    }
    memset(v,0,sizeof(v));top=0;
    for(int i=0;i<2*n;i++)
        if(id[i]==i&&!v[i])DFS(i);

    memset(choose,-1,sizeof(choose));
    for(int i=top-1;i>=0;i--)
        if(choose[order[i]/2]==-1)
            for(int j=0;j<2*n;j++)
                if(id[j]==order[i])
                    choose[j/2]=j&1;
    for(int i=0;i<n;i++){
        int j=2*i+choose[i];
        printf("%.2d:%.2d %.2d:%.2d\n",start[j]/60,start[j]%60,end[j]/60,end[j]%60);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        top=0;
        for(int i=0;i<2*n;i++){vert[i]=NULL;r_vert[i]=NULL;}
        for(int i=0;i<n;i++)
        {
            int a1,a2,b1,b2,c;
            scanf("%d:%d %d:%d %d",&a1,&a2,&b1,&b2,&c);
            a1=a1*60+a2;b1=b1*60+b2;
            start[zeros(i)]=a1;end[zeros(i)]=a1+c;
            start[ones(i)]=b1-c;end[ones(i)]=b1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(intersect(zeros(i),zeros(j)))
                {
                    Add_Edge(zeros(i),ones(j));
                    Add_Edge(zeros(j),ones(i));
                }
                if(intersect(zeros(i),ones(j)))
                {
                    Add_Edge(zeros(i),zeros(j));
                    Add_Edge(ones(j),ones(i));
                }
                if(intersect(ones(i),zeros(j)))
                {
                    Add_Edge(ones(i),ones(j));
                    Add_Edge(zeros(j),zeros(i));
                }
                if(intersect(ones(i),ones(j)))
                {
                    Add_Edge(ones(i),zeros(j));
                    Add_Edge(ones(j),zeros(i));
                }
            }
        }
        memset(v,0,sizeof(v));top=0;

        for(int i=0;i<2*n;i++)
            if(!v[i])DFS(i);

        for(int i=0;i<2*n;i++){v[i]=0; id[i]=i;}
        for(int i=2*n-1;i>=0;i--)
            if(!v[order[i]])DFS_RG(order[i],order[i]);

        bool flag=false;
        for(int i=0;i<n;i++)
            if(id[ones(i)]==id[zeros(i)]){flag=true;break;}

        if(flag){puts("NO");continue;}
        else{
            puts("YES");
            Display();
        }
    }
    return 0;
}
