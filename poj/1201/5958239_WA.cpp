#include <cstdio>
#include <cstring>
struct edge{
    int to,d;
    edge *next;
}edg[200000],*vert[50002];
const int inf=1000000000;
int dis[50002],que[50002],flag[50002];
void Add_Edge(int x,int y,int va,int &top)
{
    //printf("%d->%d %d\n",x,y,va);
    edge *p=&edg[++top];
    p->to=y;
    p->d=va;
    p->next=vert[x];vert[x]=p;
}
int Bellman_Ford(int s,int t)
{
    int front=-1,tail=-1,n=t-s+1;
    for(int i=s;i<=t;i++){dis[i]=-inf;flag[i]=0;}
    dis[s]=0;   que[++tail]=s;  flag[s]=1;
    while(front<tail)
    {
        int i=que[(++front)%n];
        for(edge *p=vert[i];p;p=p->next)
        {
            if(dis[p->to]<dis[i]+p->d)
            {
                dis[p->to]=dis[i]+p->d;
                if(!flag[p->to]){
                    flag[p->to]=1;
                    que[(++tail)%n]=p->to;
                }
            }
        }
        flag[i]=0;
    }
    return dis[t];
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int maxi=-1,mini=inf,top=-1;
        memset(vert,0,sizeof(vert));
        for(int i=0;i<n;i++)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            if(a<mini)mini=a;
            if(b>maxi)maxi=b+1;
            Add_Edge(a,b+1,c,top);
        }
        for(int i=mini;i<maxi;i++)
        {
            //Add_Edge(mini,i+1,0,top);
            Add_Edge(i,i+1,0,top);
            Add_Edge(i+1,i,-1,top);
        }
        printf("%d\n",Bellman_Ford(mini,maxi));
    }
    return 0;
}
