#include<cstdio>
#include<cstring>
#include<queue>
#define inf 1000000000
using namespace std;

struct edge{
    int to,r,c,f,next;
}e[500020];
int n,m,deg[12],s,t,L[400],p[400][400],head[400];
int fi[12]={1,2,4,8,16,32,64,128,256,512,1024,2048};
int Dinic()
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
                int min=1000000000,k=top-1,flag=1;
                for(int i=0;i<top;i++)
                    if(min > e[p[i][1]].c-e[p[i][1]].f)
                    {
                        min = e[p[i][1]].c-e[p[i][1]].f;
                        k=i;
                    }
                flow+=min;
                for(int i = top-1;i>=0;i--)
                {
                    e[p[i][1]].f+=min;
                    e[e[p[i][1]].r].f=-e[p[i][1]].f;
                }
                top=k;
                p[top][1]=e[p[top][1]].next;
            }
        }
    }
}
void Add_Edge(int x,int y,int c,int &top)
{
    e[++top].to=y;  e[top].c=c; e[top].f=0;
    e[top].r=top+1; e[top].next=head[x];    head[x]=top;

    e[++top].to=x;  e[top].c=0; e[top].f=0;
    e[top].r=top-1; e[top].next=head[y];    head[y]=top;
}
int main()
{
    int tcase;
    scanf("%d",&tcase);
    getchar();
    while(tcase--)
    {
        char ch;
        n=0;
        while(1){
            ch=getchar();
            if(ch>='0'&&ch<='9')
                deg[n++]=ch-'0';
            else if(ch=='\n')break;
        }

        m=n*(n-1)/2;    s=0;    t=m+n+1;
        int ans=0,aa[12];
        for(int i=1;i<fi[n];i++)
        {
            int xx=0,cnt=0,tem=i,top=-1,tail=1;
            memset(aa,0,sizeof(aa));
            while(tem){
                aa[xx++]=tem%2;
                if(tem%2)cnt++;
                tem/=2;
            }
            if(cnt<=ans)continue;
            memset(head,-1,sizeof(head));
            for(int i=1;i<=m;i++)   Add_Edge(0,i,1,top);
            for(int i=m+1;i<=m+n;i++)   Add_Edge(i,t,deg[i-m-1],top);
            for(int j=m+1;j<=m+n;j++)
                for(int k=j+1;k<=m+n;k++)
                    if(aa[j-m-1]&&deg[j-m-1]<deg[k-m-1])
                        Add_Edge(tail++,j,1,top);
                    else{   Add_Edge(tail,j,1,top);
                            Add_Edge(tail++,k,1,top);
                    }
            if(Dinic()==m)ans=cnt;
        }
        printf("%d\n",ans);
    }
    return 0;
}
