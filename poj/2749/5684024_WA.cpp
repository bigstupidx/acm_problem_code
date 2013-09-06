#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<cstdlib>
#define ones(x) (2*x+1)
#define zeros(x) (2*x)
using namespace std;
vector<int>tem[1010];
struct edge{
    int to;
    edge *next;
}edg[1000010],r_edg[1000010],*vert[1010],*r_vert[1010];

struct node{
    int x,y;
}nod[505];

int top,n,order[1010],color[1010],id[1010],s[2][2],d,disa[505],disb[505];
bool v[1010];

void Add_Edge(int x,int y)
{
    edge *p=&edg[top];
    p->to=y;
    p->next=vert[x];vert[x]=p;

    p=&r_edg[top++];
    p->to=x;
    p->next=r_vert[y];r_vert[y]=p;
}
int Distance(int i,int j)
{
    return abs(nod[i].x-s[j][0])+abs(nod[i].y-s[j][1]);
}

void DFS(int s)
{
    v[s]=1;
    for(edge *p=vert[s];p;p=p->next)
        if(!v[p->to])DFS(p->to);
    order[top++]=s;
}
void DFS_RG(int s)
{
    v[s]=1;
    id[s]=top;
    for(edge *p=r_vert[s];p;p=p->next)
        if(!v[p->to])DFS_RG(p->to);
}
void Make_Graph(int mid)
{
    int i,j;
    top=0;
    for(i=0;i<2*n;i++){vert[i]=NULL;    r_vert[i]=NULL;}
    for(i=0;i<2*n;i++)
    {
        for(j=0;j<tem[i].size();j++)
        {
            Add_Edge(i,tem[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(disa[i]+disa[j]>mid)
            {
                Add_Edge(zeros(i),ones(j));
                Add_Edge(zeros(j),ones(i));
            }
            if(disb[i]+disb[j]>mid)
            {
                Add_Edge(ones(i),zeros(j));
                Add_Edge(ones(j),zeros(i));
            }
            if(disa[i]+disb[j]+d>mid)
            {
                Add_Edge(zeros(i),zeros(j));
                Add_Edge(ones(j),ones(j));
            }
            if(disb[i]+disa[j]+d>mid)
            {
                Add_Edge(ones(i),ones(j));
                Add_Edge(zeros(j),zeros(i));
            }
        }
    }
}
bool solve(int mid)
{
    Make_Graph(mid);

    memset(v,0,sizeof(v));top=0;
    for(int i=0;i<2*n;i++)
        if(!v[i])DFS(i);

    memset(v,0,sizeof(v));top=0;
    for(int i=2*n-1;i>=0;i--)
        if(!v[order[i]]){DFS_RG(order[i]);top++;}

    for(int i=0;i<n;i++)
        if(id[zeros(i)]==id[ones(i)])return false;
    return true;
}
int main()
{
    int m1,m2;
    while(scanf("%d%d%d",&n,&m1,&m2)!=EOF)
    {
        int i,j;
        for(i=0;i<2*n;i++)  tem[i].clear();
        scanf("%d%d%d%d",&s[0][0],&s[0][1],&s[1][0],&s[1][1]);
        for(i=0;i<n;i++)scanf("%d%d",&nod[i].x,&nod[i].y);
        while(m1--)
        {
            scanf("%d%d",&i,&j);
            i--;j--;
            tem[zeros(i)].push_back(ones(j));   tem[zeros(j)].push_back(ones(i));
            tem[ones(i)].push_back(zeros(j));   tem[ones(j)].push_back(zeros(i));
        }
        while(m2--)
        {
            scanf("%d%d",&i,&j);
            i--;j--;
            tem[zeros(i)].push_back(zeros(j));  tem[zeros(j)].push_back(zeros(i));
            tem[ones(i)].push_back(ones(j));    tem[ones(j)].push_back(ones(i));
        }

        d=abs(s[0][0]-s[1][0])+abs(s[0][1]-s[1][1]);
        memset(disa,0,sizeof(disa));
        memset(disb,0,sizeof(disb));

        for(i=0;i<n;i++)
        {
            disa[i]=Distance(i,0);disb[i]=Distance(i,1);
        }
        int maxi=-1;
        for(i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
            {
                if(maxi<disa[i]+disa[j])maxi=disa[i]+disa[j];
                if(maxi<disa[i]+disb[j]+d)maxi=disa[i]+disb[j]+d;
                if(maxi<disb[i]+disa[j]+d)maxi=disb[i]+disa[j]+d;
                if(maxi<disb[i]+disb[j])maxi=disb[i]+disb[j];
            }
        //printf("%d\n",maxi);
        int l=0,r=maxi,mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            //printf("try mid :%d\n",mid);
            if(solve(mid))
                r=mid-1;
            else
                l=mid+1;
        }
        if(l>maxi)puts("-1");
        else printf("%d\n",l);
    }
    return 0;
}
