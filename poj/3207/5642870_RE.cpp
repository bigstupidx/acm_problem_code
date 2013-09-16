#include<cstdio>
#include<cstring>
#define ones(x) (2*x)
#define zeros(x) (2*x+1)
struct links{
    int x,y;
}link[505];
struct edge{
    int to;
    edge *next;
}edg[20000],*vert[1010],*r_vert[1010];
int n,top,order[1010],id[1010];
bool v[1010];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
void DFS(int s)
{
    v[s]=true;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s)
{
    v[s]=true;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to);
}
bool Cross(int i,int j)
{
    int a=link[i].x,b=link[i].y;
    int c=link[j].x,d=link[j].y;
    if(a>=c&&b<=d||a<=c&&b>=d||a<c&&b<=c||a>=d&&b>d)return false;
    return true;
}
int main()
{
    int m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            scanf("%d%d",&a,&b);
            if(a>b){c=a;a=b;b=c;}
            link[i].x=a,link[i].y=b;;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=i+1;j<m;j++)
            {
                if(Cross(i,j))
                {
                    Add_Edge(zeros(i),ones(j));
                    Add_Edge(ones(j),zeros(i));
                }
            }
        }
        memset(v,0,sizeof(v));top=0;
        for(int i=0;i<2*m;i++)
            if(!v[i])DFS(i);
/*        for(int i=0;i<2*m;i++)
            printf("%d ",order[i]);
        puts("");
         * */
        memset(v,0,sizeof(v));top=1;
        for(int i=2*m-1;i>=0;i--)
            if(!v[order[i]]){DFS_RG(order[i]);top++;}
        bool flag=false;
        /*
        for(int i=0;i<2*m;i++)
            printf("%d ",id[i]);
        puts("");*/
        for(int i=0;i<m;i++)
            if(id[ones(i)]==id[zeros(i)]){flag=true;break;}
        if(flag)printf("the evil panda is lying again\n");
        else printf("panda is telling the truth...\n");
    }
    return 0;
}
