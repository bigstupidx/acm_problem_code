#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
struct edge{
    int to,r,next;
    double c,f;
}e[4000000];
int m,n,head[1200],p[1200][2],L[1200],nod[1002][2],flag[200];
void Add_Edge(int x,int y,double va,int &top)
{
    e[++top].to=y;  e[top].c=va;    e[top].f=0;
    e[top].r=top+1; e[top].next=head[x];    head[x]=top;

    e[++top].to=x;  e[top].c=0; e[top].f=0;
    e[top].r=top-1; e[top].next=head[y];    head[y]=top;
}
void Build_G(double mid)
{
    int top=-1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)
        Add_Edge(i,n+m+1,mid,top);
    for(int i=1;i<=m;i++)
    {
        Add_Edge(0,n+i,1,top);
        Add_Edge(n+i,nod[i][0],10000,top);
        Add_Edge(n+i,nod[i][1],10000,top);
    }
}
double Max_Flow(int s,int t)
{
    double flow=0;
    while(1)
    {
        queue<int>Q;
        memset(L,-1,sizeof(L));
        Q.push(s);L[s]=0;
        while(!Q.empty())
        {
            int i=Q.front();Q.pop();
            for(int j=head[i];j!=-1;j=e[j].next)
            {
                if(L[e[j].to]==-1 && e[j].c > e[j].f)
                {
                    L[e[j].to]=L[i]+1;
                    Q.push(e[j].to);
                }
            }
        }
        if(L[t]==-1){
            //printf("%lf\n",flow);
            return flow;
        }
        int top=0;
        p[0][0]=s;  p[0][1]=head[s];
        while(top>=0)
        {
            if(p[top][0]!=t)
            {
                while(p[top][1]>=0)
                {
                    if(L[p[top][0]]<L[e[p[top][1]].to]&& e[p[top][1]].c > e[p[top][1]].f)
                    {
                        p[top+1][0]=e[p[top][1]].to;
                        p[top+1][1]=head[p[top+1][0]];
                        top++;break;
                    }
                    p[top][1]=e[p[top][1]].next;
                }
                if(p[top][1]<0)
                {
                    top--;
                    if(top<0)break;
		    p[top][1]=e[p[top][1]].next;
                }
            }
            else
            {
                double min=10000;
                int k=top-1,flag=1;
                for(int i=0;i<top;i++)
                    if(min > e[p[i][1]].c-e[p[i][1]].f)min = e[p[i][1]].c-e[p[i][1]].f;
                flow+=min;
                for(int i = top-1;i>=0;i--)
                {
                    e[p[i][1]].f+=min;
                    e[e[p[i][1]].r].f=-e[p[i][1]].f;
                    if(flag&&e[p[i][1]].f==e[p[i][1]].c){flag=0;k=i;}
                }
                top=k;
                p[top][1]=e[p[top][1]].next;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        double left=1.0/n,right=m,mid,mini=0.1/(n*n);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&nod[i][0],&nod[i][1]);
        while(right-left>=mini)
        {
            mid=(left+right)/2;
            Build_G(mid);
            //printf("try %lf ",mid);
            if(m-Max_Flow(0,m+n+1)>mini)
                left=mid+mini;
            else
                right=mid-mini;
        }
        if(left>m)printf("1\n1\n");
        else{
            int cnt=0;
            memset(flag,0,sizeof(flag));
            for(int i=1;i<=n;i++)
                for(int j=head[i];j!=-1;j=e[j].next)
                    if(e[j].to==n+m+1&&fabs(e[j].c-e[j].f)<=mini)
                    {   cnt++;flag[i]=1;    break;  }
            printf("%d\n",cnt);
            for(int i=1;i<=n;i++)
                if(flag[i])printf("%d\n",i);
        }
    }
    return 0;
}

