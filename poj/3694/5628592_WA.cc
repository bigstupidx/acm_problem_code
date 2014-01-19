#include<cstdio>
#include<cstring>
#include<map>
#define N 100010
using namespace std;

struct edge{
    int to;
    edge *next;
}edg[404000],*vert[N];
int n,top,tail,color[N],par[N],anc[N],deep[N],bri[N][2],id[N];
void Add_Edge(int x,int y)
{
    edge *p=&edg[top++];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&edg[top++];
    p->to=x;
    p->next=vert[y];vert[y]=p;
}
int F(int s)
{
    int t=par[s];
    if(t==-1)return s;
    return par[s]=F( t );
}
void DFS(int k,int k_father,int depth)
{
    color[k]=1;
    anc[k]=deep[k]=depth;
    int repeat=0;
    for(edge *p=vert[k];p;p=p->next)
    {
        int i=p->to;
        if(i==k_father)repeat++;
        if(color[i]==1&&(i!=k_father||repeat!=1))
            anc[k]=anc[k]<deep[i]?anc[k]:deep[i];
        if(color[i]==0)
        {
            DFS(i,k,depth+1);
            anc[k]=anc[k]<anc[i]?anc[k]:anc[i];
            if(anc[i]<=deep[k])
            {
                int ii,kk;
                ii=F(i);kk=F(k);
                par[ii]=kk;
            }
            else
            {
                bri[tail][0]=k;
                bri[tail++][1]=i;
            }
        }
    }
    color[k]=2;
}
void Construct_Tree()
{
    int ret=1;
    for(int i=1;i<=n;i++)id[i]=0;
//    printf("id :\n");
    for(int i=1;i<=n;i++)
    {
        int j=F(i);
        if(!id[j])id[j]=ret++;
        id[i]=id[j];
//        printf("%d ",id[i]);
    }
//    puts("");
    for(int i=1;i<ret;i++)par[i]=-1;
//    printf("Bridge :\n");
    for(int i=0;i<tail;i++)
    {
        int j=bri[i][0],k=bri[i][1];
//        printf("%d %d\n",j,k);
        par[id[j]]=id[k];
    }
    return ;
}
int main()
{
    int m,ncase=0;
    while(scanf("%d%d",&n,&m),m||n)
    {
        int i,j,q;
        for(i=1;i<=n;i++)
        {
            par[i]=-1;color[i]=0;
            vert[i]=NULL;
        }
        top=0;ncase++;
        while(m--)
        {
            scanf("%d%d",&i,&j);
            Add_Edge(i,j);
        }
        tail=0;
        DFS(1,0,1);
        Construct_Tree();
        int ans=tail,m1,m2,t1,t2;
        scanf("%d",&q);
        printf("Case %d:\n",ncase);
        map<int,int>mp;
        while(q--)
        {
            scanf("%d%d",&i,&j);
            int ii=id[i],jj=id[j],t2=j,kk;
            mp.clear();
            while(ii!=-1){mp[ii]=1;ii=par[ii];}
            while(jj!=-1){
                if(mp.find(jj)!=mp.end())break;
                jj=par[jj];
            }
            m1=0;m2=0;kk=jj;
            ii=id[i];jj=id[j];t1=i;t2=j;
            while(ii!=kk){m1++;id[t1]=kk;t1=ii;ii=par[ii];}
            while(jj!=kk){m2++;id[t2]=kk;t2=jj;jj=par[jj];}
            if(ans!=0)ans=ans-m1-m2;
            printf("%d\n",ans);
        }
        puts("");
    }
    return 0;
}
