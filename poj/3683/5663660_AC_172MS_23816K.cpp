#include <cstdio>
#include <cstring>
#define zeros(x) (2*x)
#define ones(x)  (2*x+1)
struct edge{
    int to;
    edge *next;
}edg[4000000],*vert[2010],*r_vert[2010],r_edg[4000000];

int order[2020],color[2020],id[2020],n,top,start[2020],end[2020],choose[2020];

void Add_Edge(int x,int y)
{
    //printf("front :%d->%d\n",x,y);
    //printf("back  :%d->%d\n",y,x);
    edge *p=&edg[top];
    p->to=y;
    p->next=vert[x];vert[x]=p;
    
    p=&r_edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
bool intersect(int i,int j)
{//ÅÐ¶ÏÊ±¼äÊÇ·ñÓÐ³åÍ» 
    if(start[i]>=end[j]||end[i]<=start[j])return false;
    return true;
}
void DFS(int s)
{
    color[s]=1;
    for(edge *p=vert[s]; p;p=p->next)
        if(!color[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s,int root)
{
    color[s]=1;
    id[s]=root;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!color[p->to])DFS_RG(p->to,root);
}
void Display()
{
    top=0;
    for(int i=0;i< n + n;i++)vert[i]=NULL;
    for(int i = 0; i< n + n; i++)
        if(id[i] == i)
            for(int j=0;j<n+n;j++)
                if(id[j]==i)
                    for(edge *p = r_vert[j]; p ; p = p->next)
                    {
                        edge *q=&edg[top++];
                        q->to=id[p->to];
                       // printf("%d->%d\n",i,p->to);
                        q->next=vert[i];vert[i]=q;
                    }
    top=0;
    
    for(int i=0;i<2*n;i++){color[i]=0;choose[i]=-1;}
    
    for(int i=0;i<2*n;i++)
        if(id[i]==i && color[i]==0)DFS(i);
    
    for(int i=top-1;i>=0;i--)
        if(choose[order[i]/2]==-1)
            for(int j=0;j<2*n;j++)
                if(id[j]==order[i])
                    choose[j / 2] = j & 1;
    for(int i=0;i<n;i++)
    {
        int j=choose[i]+2*i;
        printf("%.2d:%.2d %.2d:%.2d\n",start[j]/60,start[j]%60,end[j]/60,end[j]%60);
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        top=0;
        for(int i=0;i<n + n;i++){vert[i]=NULL;r_vert[i]=NULL;}
        for(int i=0;i<n;i++)
        {
            int a1,a2,b1,b2,c;
            scanf("%d:%d %d:%d %d",&a1,&a2,&b1,&b2,&c);
            a1=a1*60+a2;b1=b1*60+b2;
            start[zeros(i)]=a1;end[zeros(i)]=a1+c;
            start[ ones(i)]=b1-c;end[ones(i)]=b1;
        }
        for(int i=0;i<n;i++)
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
        top=0;
        for(int i=0;i<2*n;i++)color[i]=0;
        
        for(int i=0;i<2*n;i++)
            if(!color[i])DFS(i);
        
        top=0;
        for(int i=0;i<2*n;i++)color[i]=0;
        
        for(int i=2*n-1;i>=0;i--)
            if(!color[order[i]])DFS_RG(order[i],order[i]);
        
        bool flag=false;
        for(int i=0;i<n;i++)
            if(id[ones(i)]==id[zeros(i)])
                {flag=true;break;}
        
        if(flag)printf("NO\n");
        else{
            printf("YES\n");
            Display();
        }
    }
    return 0;
}
