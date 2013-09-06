#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;
struct edge{
    int to;
    double pp;
    edge *next;
}edg[40010],*vert[120];
int n,m,flag[120],S[120];
double dis[120];
void Add_Edge(int x,int y,double pp,int &top)
{
    edge *p=&edg[++top];
    p->to=y;
    p->pp=pp;
    p->next=vert[x];    vert[x]=p;
}
double spfa()
{
    int top=0;
    for(int i=1;i<=n;i++){dis[i]=-1000000;flag[i]=0;}
    dis[1]=0;   flag[1]=1;  S[top++]=1;
    while(top)
    {
        int u=S[--top];
        flag[u]=0;
        for(edge *p=vert[u];p;p=p->next)
        {
            if(dis[p->to]<dis[u]+p->pp)
            {
                dis[p->to]=dis[u]+p->pp;
                if(!flag[p->to])
                {
                    flag[p->to]=1;
                    S[top++]=p->to;
                }
            }
        }
    }
    return dis[n];
}
int main()
{
    while(scanf("%d",&n),n)
    {
        int x,y,p,top=-1;
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&p);
            double pp=log10(p*1.0/100);
            Add_Edge(x,y,pp,top);
            Add_Edge(y,x,pp,top);
        }
        printf("%.6lf percent\n",100*pow(10,spfa()));
    }
    return 0;
}
