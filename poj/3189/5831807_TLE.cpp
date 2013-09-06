#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct edge{
    int to,r,c,f,next;
}e[1000000];
int head[1200],L[1200],p[1200][2],order[1002][21],cap[21];
int n,b;
void Add_Edge(int x,int y,int va,int &top)
{
    //printf("%d->%d %d\n",x,y,va);
    e[++top].to=y;  e[top].c=va;    e[top].f=0;
    e[top].r=top+1; e[top].next=head[x];    head[x]=top;
    
    e[++top].to=x;  e[top].c=0;     e[top].f=0;
    e[top].r=top-1; e[top].next=head[y];    head[y]=top;
}
void Build_G(int k,int mid)
{
    int top=-1;
    memset(head,-1,sizeof(head));
    for(int i=1;i<=n;i++)Add_Edge(0,i,1,top);
    for(int i=1;i<=b;i++)Add_Edge(i+n,n+b+1,cap[i],top);
    for(int i=1;i<=n;i++)
        for(int j=k;j<k+mid;j++)
            Add_Edge(i,order[i][j]+n,1,top);
}
int Max_Flow(int s,int t)
{
    int flow=0;
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
        if(L[t]==-1)return flow;
        int top=0;
        p[0][0]=s;p[0][1]=head[s];
        while(top>=0)
        {
            if(p[top][0]!=t)
            {
                while(p[top][1]>=0)
                {
                    if(L[p[top][0]]<L[e[p[top][1]].to]&& 
                        e[p[top][1]].c > e[p[top][1]].f)
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
                int min=1000000000,k=top-1,flag=1;
                for(int i=0;i<top;i++)
                    if(min > e[p[i][1]].c-e[p[i][1]].f)
                        min = e[p[i][1]].c-e[p[i][1]].f;
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
    while(scanf("%d%d",&n,&b)!=EOF)
    {
        int i,flag;
        for(i=1;i<=n;i++)
            for(int j=0;j<b;j++)
                scanf("%d",&order[i][j]);
        for(i=1;i<=b;i++)
            scanf("%d",cap+i);
        int left=1,right=b+1,mid;
        while(left<=right)
        {
            flag=0;
            mid=(left+right)/2;
            for(i=0;i<b-mid+1;i++)
            {
                //printf("try %d %d\n",mid,i);
                Build_G(i,mid);
                //system("pause");
                if(Max_Flow(0,n+b+1)==n)
                {
                    flag=1; break;
                }
            }
            if(flag)right=mid-1;
            else left=mid+1;
        }
        printf("%d\n",left);
    }
    return 0;
}