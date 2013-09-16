#include<queue>
#include<iostream>
using namespace std;
struct node{
    int to;
    int c,f,r;//r±íÊ¾ÄæÏò±ßµÄÖ¸Õë 
    int next;
}e[1000];
int head[202],L[202],p[202][2];

int dinic(int s,int t)
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
                    p[top][1]=e[p[top][1]].next;
                }
            }
            else
            {
                int min=1000000000,k=top-1,flag=1;
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
    int m,n;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        int a,b,va,top=-1;
        memset(head,-1,sizeof(head));
        for(int i=0;i<2*m+2;i++)
            e[i].c=0;
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&va);
            e[++top].to=b;e[top].c=+va;e[top].f=0;
            e[top].next=head[a];e[top].r=top+1;head[a]=top;
            
            e[++top].to=a;e[top].c=0;e[top].f=0;
            e[top].next=head[b];e[top].r=top-1;head[b]=top;
        }
        printf("%d\n",dinic(1,n));
    }
    return 0;
}
