#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

struct edge{
    int u,v,c,wi,next;
}e[10000];

struct node{
    int x,y,va;
}nod[220];

int head[500],aa[500],flag[500],dis[500],pre[500],id[500];
const int inf=1000000000;

void Add_Edge(int u,int v,int c,int wi,int &tot)
{
    //printf("%d -> %d %d %d\n",u,v,c,wi);
    e[++tot].u=u;   e[tot].v=v;     e[tot].c=c;
    e[tot].wi=wi;   e[tot].next=head[u];    head[u]=tot;
    
    e[++tot].u=v;   e[tot].v=u;     e[tot].c=0;
    e[tot].wi=-wi;  e[tot].next=head[v];    head[v]=tot;
}
bool Spfa(int n)
{
    queue<int>Q;
    for(int i=0;i<=n;i++){dis[i]=inf;flag[i]=0;}
    Q.push(0);  dis[0]=0;   flag[0]=1;
    while(!Q.empty())
    {
        int i=Q.front();Q.pop();
        flag[i]=0;
        for(int j=head[i];j!=-1;j=e[j].next)
        {
            if(e[j].c>0&&dis[e[j].v]>dis[i]+e[j].wi)
            {
                dis[e[j].v]=dis[i]+e[j].wi;
                pre[e[j].v]=j;
                if(!flag[e[j].v])
                {
                    flag[e[j].v]=1;
                    Q.push(e[j].v);
                } 
            }
        }
    }
    if(dis[n]==inf)return false;
    return true;
}
int Find(int x,int n)
{
    int left=0,right=n,mid;
    while(left<=right)
    {
        mid=(left+right)/2;
        if(x>aa[mid])
            left=mid+1;
        else 
            right=mid-1;
    }
    return left;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,k,n=1,top=-1;
        map<int,int>mp;
        
        aa[0]=0;
        scanf("%d%d",&m,&k);
        memset(head,-1,sizeof(head));
        
        for(int i=0;i<m;i++)
        {
            int x,y,va;
            scanf("%d%d%d",&nod[i].x,&nod[i].y,&nod[i].va);
            if(mp.find(nod[i].x)==mp.end())
            {
                aa[n++]=nod[i].x;
                mp[nod[i].x]=1;
            }
            if(mp.find(nod[i].y)==mp.end())
            {
                aa[n++]=nod[i].y;
                mp[nod[i].y]=1;
            }
        }
        sort(aa,aa+n);
        
        for(int i=0;i<n;i++)
            Add_Edge(i,i+1,k,0,top);
        
        for(int i=0;i<m;i++)
        {
            int u,v;
            u=Find(nod[i].x,n);
            v=Find(nod[i].y,n);
            Add_Edge(u,v,1,-nod[i].va,top);
        }
        int cost=0;
        while(Spfa(n))
        {
            int mini=inf,i;
            for(i=n;i!=0;i=e[pre[i]].u)
            {
                if(mini>e[pre[i]].c)mini=e[pre[i]].c;
            }
            cost+=mini*dis[n];
            for(i=n;i!=0;i=e[pre[i]].u)
            {
                e[pre[i]].c-=mini;
                e[pre[i]^1].c+=mini;
            }
        }
        printf("%d\n",-cost);
    }
    system("pause");
    return 0;
}
